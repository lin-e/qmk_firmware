#include QMK_KEYBOARD_H

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
  [_BL] = LAYOUT_all(
	TD_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, ___X___, KC_PSCR,
	KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_NUHS, KC_DEL ,
	KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , KC_PGUP,
	KC_LSPO, KC_NUBS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSPC, KC_UP  , KC_PGDN,
	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC , MO(_FL), MO(_ML), KC_RALT, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_FL] = LAYOUT_all(
	KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , _______, RESET  ,
	_______, _______, _______, _______, _______, _______, _______, _______, KC_UP  , _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
//   [___] = LAYOUT_all(
// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//   ),
};
