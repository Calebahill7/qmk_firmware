#include QMK_KEYBOARD_H
#include "config_led.h"
bool GUION = true;

enum alt_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction
    U_T_AUTO,           //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    MD_BOOT,            //Restart into bootloader after hold timeout
	EMAIL,              //Sends my email
	CJCLDS,				//Sends The Church of Jesus Christ of Latter Day Saints
	GUI_TOGGLE,			//Toggles Windows Lock
	OTHER,				//Sends my OTHER email
	SPNGBB,				//Activates Spongebob Meme Text Mode
	//CAPSLG,				//acts as a special caps lock toggle, it will activate the caps lock light even if RGB has been disabled. 
};
#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;
extern keymap_config_t keymap_config;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PSCR, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  \
        MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  LT(2,KC_HOME),\
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,  \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
	[1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_CAPS, _______, \
        _______, L_T_MD,  L_PSI,   EMAIL,   OTHER,   CJCLDS,  _______, _______, _______, _______, KC_PAUS, _______, KC_SLCK, KC_INS,  KC_MUTE, \
        _______, L_PTP,   L_PSD,   L_PTN,   L_T_PTD, L_T_BR,  _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,          _______, KC_VOLU, \
        _______, L_BRD,   L_BRI,   KC_CALC, _______, _______, TG_NKRO, SPNGBB,  KC_BRID, KC_BRIU, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            L_T_ONF,                            _______, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
	[2] = LAYOUT(
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, _______, \
        _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, GUI_TOGGLE, MAGIC_UNHOST_NKRO,               MAGIC_HOST_NKRO,                    _______, _______, _______, _______, _______  \
    ),
    /* old two function key layout
	[0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PSCR, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  \
        MO(2),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_HOME, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,  \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
	[1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLCK, KC_PAUS, KC_INS,  KC_MUTE, \
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_VOLU, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_VOLD, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT  \
    ),
	[2] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   L_PTP,   L_PTN,   L_T_MD,  L_BRD,   L_BRI,   L_T_PTD, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_UP,   EMAIL,   KC_TRNS, KC_TRNS, KC_TRNS, U_T_AUTO,U_T_AGCR,KC_TRNS, KC_TRNS, L_PSD,   L_PSI,   L_T_BR,  KC_MUTE, \
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_VOLU, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_CALC, KC_TRNS, MD_BOOT, TG_NKRO, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS,          KC_PGUP, KC_VOLD, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            L_T_ONF,                            KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END  \
    ),
	*/
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),
    */
	/* // new one function key layout
    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_CAPS, KC_TRNS, \
        KC_TRNS, L_T_MD,  L_PSI,   EMAIL,   KC_TRNS, KC_TRNS, U_T_AGCR,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, \
        KC_TRNS, L_PTP,   L_PSD,   L_PTN,   L_T_PTD, L_T_BR,  U_T_AUTO,KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,          KC_TRNS, KC_VOLU, \
        KC_TRNS, L_BRD,   L_BRI,   KC_CALC, KC_TRNS, MD_BOOT, TG_NKRO, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS,          KC_PGUP, KC_VOLD, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            L_T_ONF,                            KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (keyboard_report->mods & MOD_BIT(KC_LSHIFT) || keyboard_report->mods & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (keyboard_report->mods & MOD_BIT(KC_LCTL) || keyboard_report->mods & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
	
	//bool lshifted = keyboard_report->mods & MOD_BIT(KC_LSFT);
	//bool rshifted = keyboard_report->mods & MOD_BIT(KC_RSFT);
	switch (keycode) {
		case SPNGBB:
			if (record->event.pressed) {
				if (GUION) {
					GUION = false;
					keymap_config.no_gui = true;
				}
				else {
					GUION = true;
					keymap_config.no_gui = false;
				}
			} else {
				
			}
			return false;
		case GUI_TOGGLE:
			if (record->event.pressed) {
				if (GUION) {
					GUION = false;
					keymap_config.no_gui = true;
				}
				else {
					GUION = true;
					keymap_config.no_gui = false;
				}
			} else {
				
			}
			return false;
		case EMAIL:
			if (record->event.pressed) {
				// when keycode EMAIL is pressed
				SEND_STRING("calebahill7@gmail.com");
			} else {
				// when keycode EMAIL is released
			}
			return false;
		case OTHER:
			if (record->event.pressed) {
				// when keycode OTHER is pressed
				SEND_STRING("calebanthonyhill@gmail.com");
			} else {
				// when keycode OTHER is released
			}
			return false;
		case CJCLDS:
			if (record->event.pressed) {
				// when keycode CJCLDS is pressed
				SEND_STRING("The Church of Jesus Christ of Latter-day Saints");
			} else {
				// when keycode CJCLDS is released
			}
			return false;
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
			if (led_enabled==0) {
				led_enabled = 1; 
				I2C3733_Control_Set(led_enabled);
			}
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
			if (led_enabled==0) {
				led_enabled = 1; 
				I2C3733_Control_Set(led_enabled);
			}
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
/*
enum unicode_names {
	NULLCHARS,          //nul
	TRIANGLE,           //triangle
	KEEB,				//keyboard
	OHM,				//ohm
	MALE,				//male sign
	MU,					//greek mu
	PI,					//3.1415...
	PLSR,				//plus or minus
	SQRT,				//square root
);
const uint32_t PROGMEM unicode_map[] = {
    [NULLCHARS]  = 0x2400 ,  // nul
    [TRIANGLE] = 0x25B3,  // △
    [KEEB]  = 0x2328, // ⌨
	[OHM]  = 0x03A9, // Ω 
	[MALE]  = 0x2642, //♂
	[MU]  = 0x03BC, //μ
	[PI]  = 0x03C0, //π
	[PLSR]  = 0x00B1, //±
	[SQRT]  = 0x221A, //√
};*/
