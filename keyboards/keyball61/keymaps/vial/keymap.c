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

    [QWE] = LAYOUT_right_ball(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_EQL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_GRV, KC_Z, LALT_T(KC_X), LCTL_T(KC_C), LSFT_T(KC_V), KC_B, KC_QUOT, KC_MINS, KC_N, RSFT_T(KC_M), RCTL_T(KC_COMMA), RALT_T(KC_DOT), KC_SLSH, KC_PGUP,
        KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, KC_LSFT, LT(13, KC_BSPC), LT(11, KC_DEL), LT(10, KC_ENT), LT(12, KC_SPC), KC_RGUI, KC_PGDN
    ),

    [GAL] = LAYOUT_right_ball(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_EQL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_GRV, KC_Z, LALT_T(KC_X), LCTL_T(KC_C), LSFT_T(KC_V), KC_B, KC_QUOT, KC_MINS, KC_N, RSFT_T(KC_M), RCTL_T(KC_COMMA), RALT_T(KC_DOT), KC_SLSH, KC_HOME,
        KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, KC_LSFT, LT(7, KC_BSPC), LT(6, KC_DEL), LT(4, KC_ENT), LT(5, KC_SPC), KC_RGUI, KC_END
    ),

    [COL] = LAYOUT_right_ball(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_EQL, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,
        KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
        KC_GRV, KC_Z, LALT_T(KC_X), LCTL_T(KC_C), LSFT_T(KC_D), KC_V, KC_QUOT, KC_MINS, KC_K, RSFT_T(KC_H), RCTL_T(KC_COMMA), RALT_T(KC_DOT), KC_SLSH, KC_HOME,
        KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, KC_LSFT, LT(7, KC_BSPC), LT(6, KC_DEL), LT(4, KC_ENT), LT(5, KC_SPC), KC_RGUI, KC_END
    ),

    [GAM] = LAYOUT_right_ball(
        KC_ESC, KC_5, KC_1, KC_2, KC_3, KC_4, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_H, KC_T, KC_Q, KC_W, KC_E, KC_R, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_L, KC_M, KC_A, KC_S, KC_D, KC_F, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_GRV, KC_B, KC_Z, KC_X, KC_C, KC_V, KC_N, TO(0), KC_N, RSFT_T(KC_M), RCTL_T(KC_COMMA), RALT_T(KC_DOT), KC_SLSH, KC_HOME,
        KC_TAB, KC_7, KC_6, KC_RGHT, KC_LSFT, KC_SPC, KC_LCTL, KC_ENT, KC_SPC, KC_RGUI, KC_END
    ),

    [NUM] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [FUN] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [NAV] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [MED] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [L08] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [L09] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [L10] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_BSLS, KC_LBRC, LSFT(KC_LBRC), LSFT(KC_9), KC_QUOT, KC_GRV, LSFT(KC_0), LSFT(KC_RBRC), KC_RBRC, KC_EQL, KC_NO,
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
        KC_NO, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), KC_LALT, KC_NO, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), KC_MINS, LSFT(KC_MINS), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_BSPC, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [L11] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F21, KC_F22, KC_F23, KC_F24, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
        KC_NO, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_NO, KC_NO, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [L12] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_PSCR, KC_NO, KC_NO, KC_NO, LGUI(KC_L), KC_NO, KC_WBAK, KC_WFWD, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_LGUI, KC_VOLD, KC_MUTE, KC_VOLU, KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_END, KC_TAB, KC_H, KC_J, KC_K, KC_L, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_LCTL, KC_NO, KC_NO
    ),

    [L13] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), TO(1), TO(2), TO(3), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_NO, KC_NO
    ),

    [MOUSE] = LAYOUT_right_ball(
        KC_NO, UG_SPDD, UG_HUED, UG_SATD, UG_VALD, UG_PREV, UG_NEXT, UG_VALU, UG_SATU, UG_HUEU, UG_SPDU, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, KC_NO,
        KC_NO, KC_NO, MS_BTN3, MS_BTN2, MS_BTN1, SCRL_TO, CPI_D100, CPI_I100, KC_NO, MS_BTN1, MS_BTN2, MS_BTN3, KC_NO, KC_NO,
        UG_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

// clang-format on


/*
 * Per-layer RGB colors.
 * RGBLIGHT applies the selected color to all LEDs on both halves.
 */
static void set_layer_color(uint8_t layer) {
#ifdef RGBLIGHT_ENABLE
    switch (layer) {
        case QWE:   rgblight_setrgb(0x05, 0x8C, 0xFA); break; // #058cfa
        case GAL:   rgblight_setrgb(0x05, 0x8C, 0xFA); break; // #058cfa
        case COL:   rgblight_setrgb(0x05, 0x8C, 0xFA); break; // #058cfa
        case GAM:   rgblight_setrgb(0xF7, 0x50, 0x93); break; // #f75093
        case NUM:   rgblight_setrgb(0x83, 0xA8, 0xC7); break; // #83a8c7
        case FUN:   rgblight_setrgb(0x27, 0x04, 0xC2); break; // #2704c2
        case NAV:   rgblight_setrgb(0xD6, 0x81, 0x0B); break; // #d6810b
        case MED:   rgblight_setrgb(0xC2, 0x04, 0x69); break; // #c20469
        case L08:   rgblight_setrgb(0x05, 0x8C, 0xFA); break;
        case L09:   rgblight_setrgb(0x05, 0x8C, 0xFA); break;
        case L10:   rgblight_setrgb(0x05, 0x8C, 0xFA); break;
        case L11:   rgblight_setrgb(0x05, 0x8C, 0xFA); break;
        case L12:   rgblight_setrgb(0x05, 0x8C, 0xFA); break;
        case L13:   rgblight_setrgb(0x05, 0x8C, 0xFA); break;
        case MOUSE: rgblight_setrgb(0xFF, 0xFF, 0xFF); break; // #ffffff
        default:    rgblight_setrgb(0x05, 0x8C, 0xFA); break;
    }
#endif
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    set_layer_color(get_highest_layer(layer_state));
#endif
}

/*
 * Latched mouse layer behavior:
 * - Trackball movement turns MOUSE on from keyball.c.
 * - MOUSE stays on until a non-mouse key is pressed.
 * - Mouse keys do not dismiss the layer.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && layer_state_is(MOUSE)) {
        switch (keycode) {
            case MS_BTN1:
            case MS_BTN2:
            case MS_BTN3:
            case MS_BTN4:
            case MS_BTN5:
            case MS_LEFT:
            case MS_RGHT:
            case MS_UP:
            case MS_DOWN:
            case MS_WHLL:
            case MS_WHLR:
            case MS_WHLU:
            case MS_WHLD:
                break;
            default:
                layer_off(MOUSE);
                break;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_layer_color(get_highest_layer(state));
    return state;
}


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