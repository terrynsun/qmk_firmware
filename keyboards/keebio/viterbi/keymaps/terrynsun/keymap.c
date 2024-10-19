#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _FNKEYS
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FNKEYS,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  `~  |   1  |   2  |   3  |   4  |   5  |   6  |      |   7  |   8  |   9  |   0  | - _  | = +  | \ |  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | M1   |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------|------|      |------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  | PgUp |      |   H  |   J  |   K  |   L  |   ;  |   "  | Enter|
 * |------+------+------+------+------+------|------|      |------+------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  | PgDn |      |   N  |   M  |   ,  |   .  |   /  |  Up  |RShift|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | FnKey| Ext  | Alt  | Super| Ctrl | Space|Enter |      |Backsp|Delete| Space|      | Left | Down | Right|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,     KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_BTN1,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_PGUP,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_PGDN,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_UP  , KC_RSFT,
    FNKEYS , KC_LCTL, KC_LALT, KC_LGUI, KC_LCTL, KC_SPC , KC_ENT ,     KC_BSPC, KC_DEL , KC_SPC , FNKEYS , KC_LEFT, KC_DOWN, KC_RGHT
  ),

/*
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F2  |  F4  |  F4  |  F5  |  F6  |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      | Vol+ | Play |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      | Prev | Vol- | Next |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_FNKEYS] = LAYOUT_ortho_5x14(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FNKEYS:
      if (record->event.pressed) {
        layer_on(_FNKEYS);
      } else {
        layer_off(_FNKEYS);
      }
      return false;
      break;
  }
  return true;
}
