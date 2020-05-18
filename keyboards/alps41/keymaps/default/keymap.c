#include QMK_KEYBOARD_H

/* this keymap is to provide a basic keyboard layout for testing the matrix
 * for more practical and complicated keymap refer to other keymaps in the same folder
 */
 
enum custom_keycodes {
	EMAIL,              //Sends my email
	CJCLDS,				//Sends The Church of Jesus Christ of Latter Day Saints
	OTHER,				//Sends my OTHER email
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, KC_BSPC,  
    LT(4,KC_A),KC_S,  KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT,                            LT(1,KC_SPC),                           RALT_T(KC_RGUI), RCTL_T(KC_DEL)
  ),
  [1] = LAYOUT( /*missing keys*/
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  
    KC_GRV,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,LT(3,KC_SCLN),_______, KC_PSCR, 
    _______, _______, _______, KC_CALC, _______, KC_LGUI, _______, _______, KC_BRID, KC_BRIU, KC_BSLS, _______, 
    MO(2),   _______,                   _______,                                     _______, _______
  ),
  [2] = LAYOUT( /*function, navigation*/
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    
    KC_ESC,  _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______,
	_______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, 
    _______, _______,                            _______,                                     _______, _______
  ),
  [3] = LAYOUT( /*media, alternative navigation*/
    _______, KC_MSTP, EMAIL,   OTHER,   CJCLDS,  _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______,
    KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, _______,
	_______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______,                            _______,                                     _______, _______
  ),
  [4] = LAYOUT( /*numpad*/
    _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_NLCK,
    _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PSLS,
	_______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, 
    _______, _______,                                                         KC_P0,          KC_PDOT, KC_PENT
  ),
  /*[#] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______,                            _______,                                     _______, _______
  ),*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EMAIL:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("calebahill7@gmail.com");
      } else {
        // when keycode QMKBEST is released
      }
      break;
	case OTHER:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("calebanthonyhill@gmail.com");
      } else {
        // when keycode QMKBEST is released
      }
      break;
	case CJCLDS:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("The Church of Jesus Christ of Latter-day Saints");
      } else {
        // when keycode QMKBEST is released
      }
      break;
  }
  return true;
};
