/* Copyright 2018 sevenseacat
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define ___ KC_TRNS

// Layer names
#define _BASE  0
#define _NUM   1
#define _ARROW 2
#define _THREE 3
#define _FOUR  4

// Unicode definitions
#define ARING UC(0x00E5) // å
#define ADIA  UC(0x00E4) // ä
#define ODIA  UC(0x00F6) // ö

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KBD4X = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,                KC_Y,               KC_U,      KC_I,    KC_O,    KC_P,    KC_QUOT,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,       KC_G,                KC_H,               KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENTER,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,                KC_N,               KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    ___,     KC_LCTL, KC_LALT, KC_LGUI, MO(_THREE), LT(_ARROW, KC_BSPC), LT(_NUM, KC_SPACE), MO(_FOUR), KC_RGUI, KC_RALT, KC_RCTL, ___
  ),

  [_NUM] = LAYOUT_ortho_4x12(
    ___,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  ___,
    ___,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ___,
    ___,      S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), ___,
    ___,      ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___
  ),

  [_ARROW] = LAYOUT_ortho_4x12(
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,     KC_UP,   ___,     ___,  ARING,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  KC_LEFT, KC_DOWN, KC_DOWN, ODIA, ADIA,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,     ___,     ___,     ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,     ___,     ___,     ___,  ___
  ),

  [_THREE] = LAYOUT_ortho_4x12(
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, ___,  ___,  ___,  ___,  ___,  ___,  RESET,
    ___,      BL_TOGG, BL_STEP, ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___
  ),

  [_FOUR] = LAYOUT_ortho_4x12(
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
