#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  |   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   |LCTRL | LAlt | LGUI | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_GESC,             KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    LT(_ADJUST, KC_TAB), KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE, \
    LCTL_T(KC_CAPS),     KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,             KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC, KC_RBRC, KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
                              KC_LCTL, KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), KC_BSPC, KC_RGUI, MO(_RAISE) \
  ),
  /* LOWER
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |   `  |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   |LOWER | LAlt | LGUI | /Space  /       \Enter \  |Delete| RGUI |RAISE |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */
  [_LOWER] = LAYOUT( \
    KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
    _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                               _______, _______, _______, _______, _______, KC_DEL,  _______, _______ \
  ),
  /* RAISE
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |   `  |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   |LOWER | LAlt | LGUI | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */
  [_RAISE] = LAYOUT( \
    KC_GRV,  _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______, KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                               _______, _______, _______,  _______, _______, _______, _______, _______ \
  ),
  /* ADJUST
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |Reset |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                    |      |      |      |      | Play |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
   * |------+------+------+------+------+------| Prev  |    | Next  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------|    |-------|      |      | VolD | VolU | Mute |      |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   |LOWER | LAlt | LGUI | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */
  [_ADJUST] = LAYOUT( \
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, \
                               _______, _______, _______, _______, _______, _______, _______, _______ \
  )
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
  }
  return true;
}
