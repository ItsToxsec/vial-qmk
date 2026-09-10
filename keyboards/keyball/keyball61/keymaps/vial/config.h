/*
This is the c configuration file for the keymap

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

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5

#define AUTO_MOUSE_DEFAULT_LAYER 14

// Vial dynamic keymap settings
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 15

#define DYNAMIC_KEYMAP_MACRO_COUNT 32
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 1024

// Unique Vial keyboard ID for this Keyball61 build.
#define VIAL_KEYBOARD_UID {0x61, 0x4B, 0xA7, 0xD2, 0x38, 0xC5, 0xEE, 0x10}

// VIAL_INSECURE is enabled in rules.mk so vial.rocks can connect
// without requiring a physical unlock chord while testing.

// Cap RGB brightness to reduce current spikes on full-board lighting.
#define RGBLIGHT_LIMIT_VAL 96
