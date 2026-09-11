#include QMK_KEYBOARD_H
#include <string.h>

enum layers {
    DEFAULT = 0,
    GALLIUM,
    COLEMAK,
    GAMING,
    L4,
    L5,
    L6,
    L7,
    L8,
    L9,
    L10,
    NUMBERS,
    FUNCTION,
    MEDIA,
    NAV,
    MOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEFAULT] = LAYOUT_right_ball(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_EQL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_GRV, KC_Z, LALT_T(KC_X), LCTL_T(KC_C), LSFT_T(KC_V), KC_B, KC_QUOT, KC_MINS, KC_N, RSFT_T(KC_M), RCTL_T(KC_COMMA), RALT_T(KC_DOT), KC_SLSH, KC_PGUP,
        KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, KC_LSFT, LT(11, KC_BSPC), LT(13, KC_DEL), LT(12, KC_ENT), LT(10, KC_SPC), KC_RGUI, KC_PGDN
    ),

    [GALLIUM] = LAYOUT_right_ball(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_EQL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_GRV, KC_Z, LALT_T(KC_X), LCTL_T(KC_C), LSFT_T(KC_V), KC_B, KC_QUOT, KC_MINS, KC_N, RSFT_T(KC_M), RCTL_T(KC_COMMA), RALT_T(KC_DOT), KC_SLSH, KC_HOME,
        KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, KC_LSFT, LT(7, KC_BSPC), LT(6, KC_DEL), LT(4, KC_ENT), LT(5, KC_SPC), KC_RGUI, KC_END
    ),

    [COLEMAK] = LAYOUT_right_ball(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_EQL, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,
        KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
        KC_GRV, KC_Z, LALT_T(KC_X), LCTL_T(KC_C), LSFT_T(KC_D), KC_V, KC_QUOT, KC_MINS, KC_K, RSFT_T(KC_H), RCTL_T(KC_COMMA), RALT_T(KC_DOT), KC_SLSH, KC_HOME,
        KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, KC_LSFT, LT(7, KC_BSPC), LT(6, KC_DEL), LT(4, KC_ENT), LT(5, KC_SPC), KC_RGUI, KC_END
    ),

    [GAMING] = LAYOUT_right_ball(
        KC_ESC, KC_5, KC_1, KC_2, KC_3, KC_4, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_H, KC_T, KC_Q, KC_W, KC_E, KC_R, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_L, KC_M, KC_A, KC_S, KC_D, KC_F, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_GRV, KC_B, KC_Z, KC_X, KC_C, KC_V, KC_N, TO(0), KC_N, RSFT_T(KC_M), RCTL_T(KC_COMMA), RALT_T(KC_DOT), KC_SLSH, KC_HOME,
        KC_TAB, KC_7, KC_6, KC_RGHT, KC_LSFT, KC_SPC, KC_LCTL, KC_ENT, KC_SPC, KC_RGUI, KC_END
    ),

    [L4] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [L5] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [L6] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_BSLS, KC_LBRC, LSFT(KC_LBRC), LSFT(KC_9), KC_QUOT, KC_GRV, LSFT(KC_0), LSFT(KC_RBRC), KC_RBRC, KC_EQL, KC_NO,
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
        KC_NO, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), KC_LALT, KC_NO, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), KC_MINS, LSFT(KC_MINS), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_BSPC, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [L7] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F21, KC_F22, KC_F23, KC_F24, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
        KC_NO, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_NO, KC_NO, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [L8] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_PSCR, KC_NO, KC_NO, KC_NO, LGUI(KC_L), KC_NO, KC_WBAK, KC_WFWD, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_LGUI, KC_VOLD, KC_MUTE, KC_VOLU, KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_END, KC_TAB, KC_H, KC_J, KC_K, KC_L, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_LCTL, KC_NO, KC_NO
    ),

    [L9] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), TO(1), TO(2), TO(3), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_NO, KC_NO
    ),

    [L10] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), TO(1), TO(2), TO(3), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_NO, KC_NO
    ),

    [NUMBERS] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [FUNCTION] = LAYOUT_right_ball(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [MEDIA] = LAYOUT_right_ball(
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

    [MOUSE] = LAYOUT_right_ball(
        KC_NO, UG_SPDD, UG_HUED, UG_SATD, UG_VALD, UG_PREV, UG_NEXT, UG_VALU, UG_SATU, UG_HUEU, UG_SPDU, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, KC_NO,
        KC_NO, KC_NO, MS_BTN3, MS_BTN2, MS_BTN1, SCRL_TO, CPI_D100, CPI_I100, KC_NO, MS_BTN1, MS_BTN2, MS_BTN3, KC_NO, KC_NO,
        RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"
#    include "sly_oled.h"

static void render_layer_name(void) {
    oled_clear();

    const char *name = "Default";

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case DEFAULT:  name = "Default";  break;
        case GALLIUM:  name = "Gallium";  break;
        case COLEMAK:  name = "Colemak";  break;
        case GAMING:   name = "Gaming";   break;
        case L4:       name = "L4";       break;
        case L5:       name = "L5";       break;
        case L6:       name = "L6";       break;
        case L7:       name = "L7";       break;
        case L8:       name = "L8";       break;
        case L9:       name = "L9";       break;
        case L10:      name = "L10";      break;
        case NUMBERS:  name = "Numbers";  break;
        case FUNCTION: name = "Function"; break;
        case MEDIA:    name = "Media";    break;
        case NAV:      name = "Nav";      break;
        case MOUSE:    name = "Mouse";    break;
    }

    uint8_t len = strlen(name);
    uint8_t col = 0;
    if (len < 21) {
        col = (21 - len) / 2;
    }
    oled_set_cursor(col, 1);
    oled_write(name, false);
}

void oledkit_render_info_user(void) {
    render_layer_name();
}

void oledkit_render_logo_user(void) {
    oled_clear();
    oled_set_cursor(0, 0);
    render_sly_logo();
}
#endif
