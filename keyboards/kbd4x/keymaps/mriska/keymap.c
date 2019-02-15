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
#define _ARROW 1
#define _NUM   2
#define _THREE 3
#define _FOUR  4

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KBD4X = SAFE_RANGE,
  AA,
  AE,
  OE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,          KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,               KC_U,    KC_I,    KC_O,      KC_P,      KC_QUOT,
    KC_TAB,  KC_A,          KC_S,    KC_D,    KC_F,    KC_G,                KC_H,               KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_ENTER,
    KC_HOME, KC_Z,          KC_X,    KC_C,    KC_V,    KC_B,                KC_N,               KC_M,    KC_COMM, KC_DOT,    KC_SLSH,   KC_END,
    KC_LSFT, MO(_THREE),    ___,     KC_LALT, KC_LGUI, LT(_ARROW, KC_BSPC), LT(_NUM, KC_SPACE), KC_RGUI, KC_RALT, ___,       MO(_FOUR), KC_RCTL
  ),

  [_ARROW] = LAYOUT_ortho_4x12(
    ___, KC_LPRN, KC_RPRN, KC_LT,   KC_GT,   ___,  ___,  ___,     KC_UP,   ___,     ___,  AA,
    ___, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, ___,  ___,  KC_LEFT, KC_DOWN, KC_RGHT, OE,   AE,
    ___, KC_BSLS, KC_PIPE, ___,     ___,     ___,  ___,  ___,     ___,     ___,     ___,  ___,
    ___, ___,     ___,     ___,     ___,     ___,  ___,  ___,     ___,     ___,     ___,  ___
  ),

  [_NUM] = LAYOUT_ortho_4x12(
    KC_PLUS,  KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINUS,
    KC_EQUAL, KC_1,    KC_2,  KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_UNDS,
    KC_GRAVE, KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TILD,
    ___,      ___,     ___,   ___,     ___,     KC_DEL,  ___,     ___,     ___,     ___,     ___,     ___
  ),

  [_THREE] = LAYOUT_ortho_4x12(
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  KC_MUTE, KC_VOLU, KC_MPLY, ___,  ___,
    ___,      RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, ___,  ___,  KC_MRWD, KC_VOLD, KC_MFFD, ___,  RESET,
    ___,      BL_TOGG, BL_STEP, ___,     ___,     ___,  ___,  ___,     ___,     ___,     ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,     ___,     ___,     ___,  ___
  ),

  [_FOUR] = LAYOUT_ortho_4x12(
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t current_mods = get_mods();
  bool shifted = current_mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
  switch (keycode) {
    case AA:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("a"));
      }
      break;
    case AE:
      if (record->event.pressed) {
        clear_mods();
        if (shifted) {
          SEND_STRING(SS_LALT("u")"A");
        } else {
          SEND_STRING(SS_LALT("u")"a");
       }
       set_mods(current_mods);
      }
      break;
    case OE:
      if (record->event.pressed) {
        clear_mods();
        if (shifted) {
          SEND_STRING(SS_LALT("u")"O");
        } else {
          SEND_STRING(SS_LALT("u")"o");
        }
        set_mods(current_mods);
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
