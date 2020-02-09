/*
Copyright 2020 Alberto Grespan <alberto@albertogrespan.com>

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

enum whitefox_layers {
  _QWERTY,
  _FUNC,
  _MEDIA,
};

enum whitefox_keycodes {
  QWERTY = SAFE_RANGE,
  FUNC,
  MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backsp|Ins|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|Del|
     * |---------------------------------------------------------------|
     * |Fn|Cps|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU|
     * |---------------------------------------------------------------|
     * |Shif    |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|Alt |Gui |         Space          |Gui|Alt|Fn |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_vanilla( \
        KC_GESC,          KC_1,     KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,   KC_EQL, KC_BSPC,KC_INS, \
        KC_TAB,           KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,   KC_RBRC,KC_BSLS,KC_DEL, \
        LT(_FUNC,KC_CAPS),KC_A,     KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,           KC_ENT, KC_PGUP, \
        KC_LSFT,          KC_Z,     KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,           KC_UP,  KC_PGDN, \
        KC_LCTL,          KC_LALT,  KC_LGUI,               KC_SPC,                          KC_RGUI,KC_RALT,MO(_MEDIA),KC_LEFT,KC_DOWN,KC_RGHT \
    ),
    /* Layer 1: Func Layer
     * ,---------------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Backsp|Rst|
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |Ply|Nxt|Prv|     |Del|
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |Lef|Dow|Up |Rig|   |   |Enter   |PgU|
     * |---------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |VoD|VoU|Mut|      |Up |PgD|
     * |---------------------------------------------------------------|
     * |    |Swap|Norm|                        |   |   |   |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [_FUNC] = LAYOUT_vanilla( \
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_BSPC,RESET, \
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_MPLY,KC_MPRV,KC_MNXT,_______,KC_DEL, \
        _______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______,_______,        KC_ENT, KC_PGUP, \
        _______,_______,_______,_______,_______,_______,_______,_______,KC_VOLD,KC_VOLU,KC_MUTE,_______,        KC_UP,  KC_PGDN, \
        _______,AG_SWAP,AG_NORM,                _______,                        _______,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT \
    ),
    /* Layer 2: Media (macOS) Layer
     * ,---------------------------------------------------------------.
     * |`  |F14|F15|   |   |Bld|Bli|Prv|Ply|Nxt|Mut|VoD|VoU|       |Ejc|
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
     * |---------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |                        |   |   |   |   |   |   |
     * `---------------------------------------------------------------'
     */
    [_MEDIA] = LAYOUT_vanilla( \
        KC_GRV, KC_F1,  KC_F2,  _______,_______, BL_DEC, BL_INC,KC_MPRV,KC_MPLY,KC_MNXT,KC_MUTE,KC_VOLD,KC_VOLU,_______,KC_EJCT, \
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______, \
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______, \
        _______,_______,_______,                _______,                        _______,_______,_______,_______,_______,_______ \
    ),
};
