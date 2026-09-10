# GitHub Actions setup for the custom Keyball61 Vial firmware

This repository can automatically compile the custom Keyball61 firmware whenever
you push an update to the `keyball/` directory.

The workflow uses the official QMK CLI container as the build environment, checks
out the `vial` branch of `vial-kb/vial-qmk`, replaces its
`keyboards/keyball/` directory with your customized `keyball/` directory, and
runs:

```bash
qmk compile -kb keyball/keyball61 -km vial
```

The resulting RP2040 `.uf2` is uploaded to the GitHub Actions run as a downloadable
artifact.

## 1. Repository layout

Your GitHub repository should look like this:

```text
your-keyball-repo/
├── .github/
│   └── workflows/
│       └── build-keyball.yml
├── keyball/
│   ├── config.h
│   ├── keyball61/
│   ├── lib/
│   └── ...
└── GITHUB_ACTIONS_SETUP.md
```

Do **not** put another `keyboards/` directory around `keyball/` when using the
included workflow. The workflow expects the customized keyboard directory at:

```text
keyball/
```

## 2. Create a GitHub repository

On GitHub:

1. Create a new repository, for example `keyball61-firmware`.
2. It can be public or private.
3. Do not initialize it with files if you already have this package locally.

## 3. Put the files into the repository

Extract this package. From the directory containing `keyball/` and `.github/`,
initialize Git:

```bash
git init
git add .
git commit -m "Initial Keyball61 Vial firmware"
git branch -M main
```

Add your repository as the remote:

```bash
git remote add origin git@github.com:YOUR_USERNAME/keyball61-firmware.git
```

Or with HTTPS:

```bash
git remote add origin https://github.com/YOUR_USERNAME/keyball61-firmware.git
```

Then push:

```bash
git push -u origin main
```

## 4. What happens after a push

A push that changes either:

```text
keyball/**
.github/workflows/build-keyball.yml
```

starts the workflow automatically.

The workflow:

1. Starts an Ubuntu GitHub Actions runner.
2. Uses `ghcr.io/qmk/qmk_cli:latest`.
3. Checks out your repository.
4. Checks out `vial-kb/vial-qmk`, branch `vial`, including submodules.
5. Replaces `vial-qmk/keyboards/keyball` with your custom `keyball` directory.
6. Runs the Keyball61 Vial build.
7. Collects `.uf2`, `.hex`, or `.bin` firmware files.
8. Uploads them as a GitHub Actions artifact.

## 5. Download the compiled firmware

On GitHub:

1. Open your repository.
2. Select **Actions**.
3. Open **Build Keyball61 Vial Firmware**.
4. Open the latest successful run.
5. Scroll to **Artifacts**.
6. Download the artifact named similar to:

```text
keyball61-vial-0123456789abcdef...
```

Inside it should be the compiled `.uf2`.

For your RP2040 Keyball61, the `.uf2` is the file you normally flash.

## 6. Run a build without changing anything

The workflow includes `workflow_dispatch`.

On GitHub:

1. Open **Actions**.
2. Select **Build Keyball61 Vial Firmware**.
3. Select **Run workflow**.
4. Choose the branch.
5. Select **Run workflow**.

This is useful when you want to verify that the current source still compiles.

## 7. Normal update workflow

After editing your Keyball files locally:

```bash
git status
git add keyball
git commit -m "Update Keyball firmware"
git push
```

GitHub will automatically build the new firmware.

For example, after editing:

```text
keyball/keyball61/keymaps/vial/keymap.c
```

you can run:

```bash
git add keyball/keyball61/keymaps/vial/keymap.c
git commit -m "Update Vial keymap"
git push
```

## 8. Build additional Vial variants

The workflow currently builds only:

```yaml
matrix:
  keymap:
    - vial
```

To build the other Keyball61 Vial keymaps too, edit:

```text
.github/workflows/build-keyball.yml
```

and change the matrix to:

```yaml
matrix:
  keymap:
    - vial
    - vial_left
    - vial_right
    - vial_dual
    - vial_none
```

GitHub will create a separate build job and artifact for every keymap.

If you only use the normal `vial` keymap, leaving the other entries commented is
faster and uses less Actions time.

## 9. Build on every push instead of only keyboard changes

The included workflow uses path filtering. To build on every push, change:

```yaml
on:
  push:
    paths:
      - "keyball/**"
      - ".github/workflows/build-keyball.yml"
```

to:

```yaml
on:
  push:
```

Keep `workflow_dispatch:` if you still want the manual **Run workflow** button.

## 10. Build only the main branch

To restrict automatic builds to `main`:

```yaml
on:
  push:
    branches:
      - main
    paths:
      - "keyball/**"
      - ".github/workflows/build-keyball.yml"
```

You can still retain `pull_request:` separately for testing proposed changes.

## 11. Release firmware automatically

The included workflow uploads normal Actions artifacts rather than creating
GitHub Releases. That is safer while you are actively developing the keyboard.

A later workflow can tag versions and publish the `.uf2` as a GitHub Release if
you want permanent downloadable firmware builds.

## 12. Troubleshooting

### `keyball/keyball61` not found

Verify that your repository has:

```text
keyball/keyball61/
```

and not:

```text
keyboards/keyball/keyball61/
```

The workflow copies `keyball/` into Vial-QMK's `keyboards/` directory itself.

### Vial-specific symbols are missing

Make sure the workflow is checking out:

```yaml
repository: vial-kb/vial-qmk
ref: vial
```

Your custom firmware uses Vial-specific functionality and should not be built
against the normal upstream `qmk/qmk_firmware` tree.

### No `.uf2` artifact

Open the **Build firmware** step in the Actions log. The artifact step only runs
after a successful compile.

### Workflow does not run after a change

The automatic trigger is restricted to:

```text
keyball/**
.github/workflows/build-keyball.yml
```

A change elsewhere in the repository will not start an automatic build. Use
**Run workflow** or alter the path filters.

### YAML error

YAML indentation matters. Keep the workflow at exactly:

```text
.github/workflows/build-keyball.yml
```

GitHub recognizes workflow files only from `.github/workflows/`.

## 13. Test the same build locally

If you already have `vial-qmk` checked out:

```bash
cd ~/vial-qmk
rm -rf keyboards/keyball
cp -a /path/to/your/repository/keyball keyboards/keyball
rm -rf .build
qmk compile -kb keyball/keyball61 -km vial
```

This follows the same essential build process as the GitHub Action.

## 14. Files included in this package

The package contains:

```text
.github/workflows/build-keyball.yml
GITHUB_ACTIONS_SETUP.md
keyball/
```

The `keyball/` directory is the latest custom firmware package, including the
Vial keymap, custom Keyball code, anti-jitter behavior, mouse-layer timeout
cycling, RGB changes, OLED files, and the other changes already made to this
firmware.
