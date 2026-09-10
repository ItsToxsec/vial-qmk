# Keyball61 Vial.rocks keymap

This keymap is set up for the RP2040 Keyball61 right-ball layout and Vial Web.

Build from a **vial-kb/vial-qmk** checkout, not upstream QMK:

    qmk clean
    qmk compile -kb keyball/keyball61 -km vial

Flash the resulting RP2040 `.uf2` to the USB/master half (and normally both halves so firmware stays in sync).

The Vial definition contains 61 unique matrix positions matching `LAYOUT_right_ball`.
The keymap exposes 15 dynamic layers and retains the Sly OLED module.

For initial testing `VIAL_INSECURE = yes` is enabled in `rules.mk`. Once Vial Web connectivity is confirmed, replace insecure mode with a physical unlock combo in `config.h`.


## Latched mouse layer

The 15th layer (`MOUSE`, QMK index 14) is activated by trackball movement in `lib/keyball/keyball.c`. It stays active until a non-mouse key is pressed. The mouse layer is transparent on ordinary keys so the key that dismisses the layer still passes through to the underlying active layer.

`MOUSE_LAYER_LED` in `config.h` selects the RGBLIGHT LED used as the indicator. It is currently set to LED 0 for the left-side quote-key position. While the mouse layer is active it is forced red; on exit it is restored to the current global RGBLIGHT HSV color.

## Scroll-hold custom keycode

The Vial `User` tab now exposes the Keyball custom keycodes, including `SCRL_MO`.
Assign `SCRL_MO` to a key for hold-to-scroll behavior.

This package is based on the working latched-auto-mouse build. The auto-mouse
changes in `lib/keyball/keyball.c`, `keymaps/vial/keymap.c`, `config.h`, and
`rules.mk` are preserved.


## Layer RGB colors

The Vial keymap sets all RGBLIGHT LEDs according to the highest active layer:

- 0 QWE: `#058cfa`
- 1 GAL: `#058cfa`
- 2 COL: `#058cfa`
- 3 GAM: `#f75093`
- 4 NUM: `#83a8c7`
- 5 FUN: `#2704c2`
- 6 NAV: `#d6810b`
- 7 MED: `#c20469`
- 8-13: `#058cfa`
- 14 MOUSE: `#ffffff`

The previous single-LED mouse indicator is removed because the entire keyboard turns white on the mouse layer.

## Inverted trackball scrolling

The final Keyball mouse report now negates both vertical (`v`) and horizontal (`h`) scroll axes. Normal pointer X/Y movement is unchanged.

## AML TIME — trackball mouse-layer timeout

The Vial **User** tab includes `AML TIME`.

Each press cycles:

`0s -> 0.5s -> 1s -> 5s -> 10s -> NEVER -> 0s`

`NEVER` is the default and preserves the existing behavior: trackball movement
activates layer 14 and it stays active until a normal key dismisses it.
Finite settings automatically dismiss layer 14 after the selected amount of
time since the most recent trackball movement. A normal key can still dismiss
the mouse layer early.

## Anti-jitter auto-mouse filter

Trackball X/Y motion must now accumulate at least 8 counts across at least
2 reports within 50 ms before layer 14 activates. This filters small trackball
movement caused by hard typing or desk vibration. Once layer 14 is active,
normal trackball movement immediately refreshes the selected `AML TIME` timeout.

The defaults can be tuned in `lib/keyball/keyball.c` with:

- `KEYBALL_AUTO_MOUSE_JITTER_THRESHOLD`
- `KEYBALL_AUTO_MOUSE_JITTER_WINDOW_MS`
- `KEYBALL_AUTO_MOUSE_JITTER_MIN_REPORTS`

## Default Vial keymap

The compiled 15-layer default keymap was regenerated from `Keyball_default.vil`,
which is a copy of the supplied `Keyball(2).vil` profile.

## RGB power-safety adjustment

The MOUSE layer no longer uses full-power `#FFFFFF`. It now uses dim white:

`0x40, 0x40, 0x40`

`RGBLIGHT_LIMIT_VAL` is also set to `96` in `config.h` to reduce current spikes.
This is intended to avoid resets/brownouts when auto-mouse activates the
full-board mouse-layer color.

