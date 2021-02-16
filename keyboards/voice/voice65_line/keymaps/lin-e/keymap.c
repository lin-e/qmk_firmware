#include QMK_KEYBOARD_H
#include "secret.h"

enum {
    D_BASE = 0,
    D_ESC
};

#define _BL 0
#define _FL 1
#define _ML 2

#define _______ KC_TRNS
#define ___X___ KC_NO
#define TD_ESC TD(D_ESC)

#define SC_M 0

void dance_esc_each(qk_tap_dance_state_t *state, void *user_data) {
    register_code(KC_ESC);
}
void dance_esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        register_code(KC_LALT);
        register_code(KC_Q);
    }
}
void dance_esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        unregister_code(KC_LALT);
        unregister_code(KC_Q);
    }
    unregister_code(KC_ESC);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [D_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(dance_esc_each, dance_esc_finished, dance_esc_reset)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// [___] = LAYOUT_voice(
	//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	// ),
	[_BL] = LAYOUT_voice(
		TD_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, ___X___,
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_NUHS, KC_DEL ,
		KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , KC_PSCR, KC_PGUP,
		KC_LSPO, KC_NUBS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSPC, KC_UP  , KC_PGDN,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC , MO(_FL), KC_SPC , KC_RALT, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
	),
	[_FL] = LAYOUT_voice(
	    KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , _______,
	    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_BTN1, KC_MS_U, KC_BTN2, _______, KC_UP  , _______, _______, _______, _______, _______, _______,
	    RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, KC_MS_L, KC_MS_D, KC_MS_R, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, RESET  , _______,
	    _______, M(SC_M), _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, KC_BTN1, KC_MS_U, KC_BTN2,
	    KC_RCTL, KC_RGUI, KC_RALT, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
	)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    if (event.pressed) {
        switch (id) {
            case SC_M:
                SEND_STRING(SEC_MASTER);
                return false;
        }
    }
    return MACRO_NONE;
}

void matrix_init_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void matrix_scan_user(void) {
}

void encoder_update_user(uint8_t index, bool clockwise) {
	// note clockwise is scrolling up
	tap_code(clockwise ? KC_VOLU : KC_VOLD);
}

void let_set_user(uint8_t usb_led){

}