/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "sly_oled.h"

enum layers {
    QWE = 0,
    GAL,
    COL,
    GAM,
    NUM,
    FUN,
    NAV,
    MED,
    L08,
    L09,
    L10,
    L11,
    L12,
    L13,
    MOUSE
};

#define HM_LALT_X    LALT_T(KC_X)
#define HM_LCTL_C    LCTL_T(KC_C)
#define HM_LSFT_V    LSFT_T(KC_V)

#define HM_RSFT_M    RSFT_T(KC_M)
#define HM_RCTL_COMM RCTL_T(KC_COMM)
#define HM_RALT_DOT  RALT_T(KC_DOT)
#define HM_LSFT_D    LSFT_T(KC_D)

/*
 * Convenient aliases.
 */
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * QWE - Qwerty
     */
    [QWE] = LAYOUT_right_ball(
        KC_ESC,   KC_1,      KC_2,         KC_3,         KC_4,         KC_5,                                  KC_6,          KC_7,         KC_8,          KC_9,          KC_0,        KC_BSPC,
        KC_EQL,   KC_Q,      KC_W,         KC_E,         KC_R,         KC_T,                                  KC_Y,          KC_U,         KC_I,          KC_O,          KC_P,        KC_BSLS,
        KC_TAB,   KC_A,      KC_S,         KC_D,         KC_F,         KC_G,                                  KC_H,          KC_J,         KC_K,          KC_L,          KC_SCLN,     KC_QUOT,
        KC_GRV,   KC_Z,      HM_LALT_X,    HM_LCTL_C,    HM_LSFT_V,    KC_B,       KC_QUOT,          KC_MINS, KC_N,          HM_RSFT_M,    HM_RCTL_COMM,  HM_RALT_DOT,  KC_SLSH,     KC_PGUP,
        KC_UP,    KC_DOWN,   KC_LEFT,      KC_RGHT,      KC_LSFT,      LT(MED, KC_BSPC), LT(FUN, KC_DEL),      LT(NUM, KC_ENT), LT(NAV, KC_SPC),                        KC_RGUI,     KC_PGDN
    ),

    /*
     * GAL - GalMod
     */
    [GAL] = LAYOUT_right_ball(
        KC_ESC,   KC_1,      KC_2,         KC_3,         KC_4,         KC_5,                                  KC_6,          KC_7,         KC_8,          KC_9,          KC_0,        KC_BSPC,
        KC_EQL,   KC_Q,      KC_W,         KC_E,         KC_R,         KC_T,                                  KC_Y,          KC_U,         KC_I,          KC_O,          KC_P,        KC_BSLS,
        KC_TAB,   KC_A,      KC_S,         KC_D,         KC_F,         KC_G,                                  KC_H,          KC_J,         KC_K,          KC_L,          KC_SCLN,     KC_QUOT,
        KC_GRV,   KC_Z,      HM_LALT_X,    HM_LCTL_C,    HM_LSFT_V,    KC_B,       KC_QUOT,          KC_MINS, KC_N,          HM_RSFT_M,    HM_RCTL_COMM,  HM_RALT_DOT,  KC_SLSH,     KC_HOME,
        KC_UP,    KC_DOWN,   KC_LEFT,      KC_RGHT,      KC_LSFT,      LT(MED, KC_BSPC), LT(NAV, KC_DEL),      LT(NUM, KC_ENT), LT(FUN, KC_SPC),                        KC_RGUI,     KC_END
    ),

    /*
     * COL - Colemak
     */
    [COL] = LAYOUT_right_ball(
        KC_ESC,   KC_1,      KC_2,         KC_3,         KC_4,         KC_5,                                  KC_6,          KC_7,         KC_8,          KC_9,          KC_0,        KC_BSPC,
        KC_EQL,   KC_Q,      KC_W,         KC_F,         KC_P,         KC_B,                                  KC_J,          KC_L,         KC_U,          KC_Y,          KC_SCLN,     KC_BSLS,
        KC_TAB,   KC_A,      KC_R,         KC_S,         KC_T,         KC_G,                                  KC_M,          KC_N,         KC_E,          KC_I,          KC_O,        KC_QUOT,
        KC_GRV,   KC_Z,      HM_LALT_X,    HM_LCTL_C,    HM_LSFT_D,    KC_V,       KC_QUOT,          KC_MINS, KC_K,          RSFT_T(KC_H), RCTL_T(KC_COMM), RALT_T(KC_DOT), KC_SLSH, KC_HOME,
        KC_UP,    KC_DOWN,   KC_LEFT,      KC_RGHT,      KC_LSFT,      LT(MED, KC_BSPC), LT(NAV, KC_DEL),      LT(NUM, KC_ENT), LT(FUN, KC_SPC),                        KC_RGUI,     KC_END
    ),

    /*
     * GAM - Gaming
     */
    [GAM] = LAYOUT_right_ball(
        KC_ESC,   KC_5,      KC_1,         KC_2,         KC_3,         KC_4,                                  KC_6,          KC_7,         KC_8,          KC_9,          KC_0,        KC_BSPC,
        KC_H,     KC_T,      KC_Q,         KC_W,         KC_E,         KC_R,                                  KC_Y,          KC_U,         KC_I,          KC_O,          KC_P,        KC_BSLS,
        KC_L,     KC_M,      KC_A,         KC_S,         KC_D,         KC_F,                                  KC_H,          KC_J,         KC_K,          KC_L,          KC_SCLN,     KC_QUOT,
        KC_GRV,   KC_B,      KC_Z,         KC_X,         KC_C,         KC_V,       KC_N,             TO(QWE), KC_N,          HM_RSFT_M,    HM_RCTL_COMM,  HM_RALT_DOT,  KC_SLSH,     KC_HOME,
        KC_TAB,   KC_7,      KC_6,         KC_RGHT,      KC_LSFT,      KC_SPC,     KC_LCTL,                     KC_ENT,         KC_SPC,                                   KC_RGUI,     KC_END
    ),

    /*
     * NUM - Numbers / symbols
     *
     * ZMK &trans -> QMK _______
     * ZMK &none  -> QMK XXXXXXX
     * ZMK key_repeat has been disabled here.
     */
    [NUM] = LAYOUT_right_ball(
        _______,  _______,   _______,       _______,       _______,       _______,                               _______,       _______,       _______,        _______,       _______,      _______,
        _______,  KC_BSLS,   KC_LBRC,       KC_LCBR,       KC_LPRN,       KC_QUOT,                               KC_GRV,         KC_RPRN,       KC_RCBR,        KC_RBRC,       KC_EQL,      _______,
        _______,  KC_1,      KC_2,          KC_3,          KC_4,          KC_5,                                  KC_6,           KC_7,          KC_8,           KC_9,          KC_0,        _______,
        _______,  KC_EXLM,   KC_AT,         KC_HASH,       KC_DLR,        KC_PERC,    KC_LALT,          XXXXXXX, KC_CIRC,        KC_AMPR,       KC_ASTR,        KC_MINS,       KC_UNDS,     _______,
        _______,  _______,   _______,       _______,       KC_LSFT,       KC_BSPC,    KC_LCTL,                    _______,        _______,                                  _______,      _______
    ),

    /*
     * FUN - Function keys
     */
    [FUN] = LAYOUT_right_ball(
        _______,  _______,   _______,       _______,       _______,       _______,                               _______,       _______,       _______,        _______,       _______,      _______,
        XXXXXXX,  KC_F21,    KC_F22,        KC_F23,        KC_F24,        XXXXXXX,                               XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,       XXXXXXX,      XXXXXXX,
        XXXXXXX,  KC_F1,     KC_F2,         KC_F3,         KC_F4,         KC_F5,                                  KC_F6,          KC_F7,         KC_F8,           KC_F9,          KC_F10,      XXXXXXX,
        _______,  KC_F11,    KC_F12,        KC_F13,        KC_F14,        KC_F15,     _______,          _______, KC_F16,         KC_F17,        KC_F18,         KC_F19,        KC_F20,      _______,
        _______,  _______,   _______,       _______,       _______,       _______,    _______,                    _______,        _______,                                  _______,      _______
    ),

    /*
     * NAV - Navigation / mouse
     */
    [NAV] = LAYOUT_right_ball(
        XXXXXXX,  XXXXXXX,   XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                               XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,       XXXXXXX,      XXXXXXX,
        XXXXXXX,  KC_PSCR,   XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                               XXXXXXX,       KC_WBAK,       KC_WFWD,        XXXXXXX,       XXXXXXX,      XXXXXXX,
        XXXXXXX,  KC_LGUI,   KC_VOLD,       KC_MUTE,       KC_VOLU,       KC_PGUP,                                KC_PGDN,        KC_UP,         KC_DOWN,         KC_LEFT,        KC_RGHT,      XXXXXXX,
        XXXXXXX,  XXXXXXX,   XXXXXXX,       MS_BTN3,       MS_BTN2,       MS_BTN1,    KC_HOME,           KC_END,  KC_TAB,         KC_H,          KC_J,            KC_K,           KC_L,         XXXXXXX,
        XXXXXXX,  XXXXXXX,   XXXXXXX,       XXXXXXX,       _______,       _______,    _______,                    KC_LALT,        KC_LCTL,                                   XXXXXXX,      XXXXXXX
    ),

    /*
     * MED - Media / system
     *
     * ZMK-specific:
     *   sys_reset
     *   OUT_USB
     *   OUT_BLE
     *   BT_CLR
     *   BT_SEL
     *   BT_CLR_ALL
     *
     * are replaced with XXXXXXX.
     *
     * ZMK bootloader does have a QMK equivalent, so QK_BOOT is retained.
     */
    [MED] = LAYOUT_right_ball(
        XXXXXXX,  XXXXXXX,   XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                               XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,       XXXXXXX,      XXXXXXX,
        XXXXXXX,  XXXXXXX,   XXXXXXX,       XXXXXXX,       XXXXXXX,       QK_BOOT,                               QK_BOOT,       XXXXXXX,       XXXXXXX,        XXXXXXX,       XXXXXXX,      XXXXXXX,
        XXXXXXX,  XXXXXXX,   XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                               XXXXXXX,       TO(QWE),       TO(GAL),        TO(COL),       TO(GAM),      XXXXXXX,
        XXXXXXX,  XXXXXXX,   XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,    _______,          _______, KC_MSTP,        XXXXXXX,       XXXXXXX,        XXXXXXX,       XXXXXXX,      XXXXXXX,
        _______,  _______,   _______,       _______,       _______,       _______,    _______,                    _______,        KC_TAB,                                    XXXXXXX,      XXXXXXX
    ),
    [L08] = LAYOUT_right_ball(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                _______, _______,                         _______, _______
),

[L09] = LAYOUT_right_ball(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                _______, _______,                         _______, _______
),

[L10] = LAYOUT_right_ball(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                _______, _______,                         _______, _______
),

[L11] = LAYOUT_right_ball(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                _______, _______,                         _______, _______
),

[L12] = LAYOUT_right_ball(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                _______, _______,                         _______, _______
),


[L13] = LAYOUT_right_ball(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                _______, _______,                         _______, _______
),
[MOUSE] = LAYOUT_right_ball(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, MS_WHLL, MS_UP,   MS_WHLR, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         MS_WHLL, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLR, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN3, MS_BTN2, MS_BTN1, _______,       _______, MS_BTN1, MS_BTN2, MS_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______,                _______, _______,                         _______, _______
)
};

// clang-format on


/*
 * Do NOT keep the original:
 *
 *   keyball_set_scroll_mode(get_highest_layer(state) == 3);
 *
 * because layer 3 is now the GAMING layer.
 *
 * With this layout the trackball remains in normal pointer mode.
 *
 * If you later want NAV to automatically turn the trackball into
 * a scroll wheel, replace this comment with:
 *
 * layer_state_t layer_state_set_user(layer_state_t state) {
 *     keyball_set_scroll_mode(get_highest_layer(state) == NAV);
 *     return state;
 * }
 */


#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"
#    include "sly_oled.h"

/*
 * Master side:
 *   Keyball status information
 */
void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}

/*
 * Secondary side:
 *   custom logo
 */
void oledkit_render_logo_user(void) {
    oled_clear();
    oled_set_cursor(0, 0);
    render_sly_logo();
}

#endif