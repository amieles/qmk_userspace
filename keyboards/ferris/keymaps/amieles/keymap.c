#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// Tap Dance declarations
enum {
   TD_A_ESC,
   TD_Z_TAB,
   TD_Q_WIN1,
   TD_W_WIN2,
   TD_E_WIN3,
   TD_R_WIN4,
   TD_0_CTRL_ALT_DEL
};

void zero_ctrl_alt_del_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_0);  // normal tap = 0
    } else if (state->count == 2) {
        // Send Ctrl+Alt+Del
        register_code(KC_LCTL);
        register_code(KC_LALT);
        tap_code(KC_DEL);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
   // Tap once for a, twice for ESC
   [TD_A_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC),
   [TD_Z_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_TAB),
   [TD_Q_WIN1] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LGUI(KC_1)),
   [TD_W_WIN2] = ACTION_TAP_DANCE_DOUBLE(KC_W, LGUI(KC_2)),
   [TD_E_WIN3] = ACTION_TAP_DANCE_DOUBLE(KC_E, LGUI(KC_3)),
   [TD_R_WIN4] = ACTION_TAP_DANCE_DOUBLE(KC_R, LGUI(KC_4)),
   [TD_0_CTRL_ALT_DEL] = ACTION_TAP_DANCE_FN(zero_ctrl_alt_del_finished)

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_split_3x5_2(
      KC_Q,        KC_W,         KC_E,         KC_R,   KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,    KC_P, 
   //----------------------------------------------------------------         --------------------------------------------------------
      TD(TD_A_ESC), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F),   KC_G,         KC_H, RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), KC_SCLN, 
   //----------------------------------------------------------------         --------------------------------------------------------
      TD(TD_Z_TAB),         KC_X,         KC_C,         KC_V,   KC_B,         KC_N,         KC_M,      KC_COMM,       KC_DOT,  KC_ENT, 
   //----------------------------------------------------------------         --------------------------------------------------------
                                                     KC_LSFT, KC_SPC,         KC_BSPC, MO(1)
),
   [1] = LAYOUT_split_3x5_2(
              KC_1,       KC_2,         KC_3,         KC_4,   KC_5,         KC_6,         KC_7,         KC_8,         KC_9,    TD(TD_0_CTRL_ALT_DEL), 
   //----------------------------------------------------------------         --------------------------------------------------------
      KC_ESC,    KC_TILD,      KC_PLUS,       KC_EQL, KC_GRV,         KC_BSLS,   KC_LCBR,      KC_RCBR,      KC_PIPE, KC_QUOT, 
   //--------------------------------------------------------         --------------------------------------------------------
      TO(2),    KC_UNDS,      KC_MINS,        KC_LT,  KC_GT,         KC_LBRC,   KC_LPRN,      KC_RPRN,      KC_RBRC, KC_SLSH, 
   //--------------------------------------------------------         --------------------------------------------------------
                                               KC_LSFT,KC_SPC,         KC_BSPC, XXXXXXX
),
   [2] = LAYOUT_split_3x5_2(
     KC_TRNS,    KC_TRNS,        MS_UP,      KC_TRNS,KC_TRNS,         KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, 
   //--------------------------------------------------------         --------------------------------------------------------
     KC_TRNS,    MS_LEFT,      MS_DOWN,      MS_RGHT,KC_TRNS,         KC_LEFT,   KC_DOWN,        KC_UP,      KC_RGHT,  KC_ENT,
   //--------------------------------------------------------         --------------------------------------------------------
     KC_TRNS,    MS_BTN2,      MS_WHLU,      MS_WHLD,KC_TRNS,         MS_BTN1,   MS_ACL0,      MS_ACL1,      MS_ACL2, KC_TRNS, 
   //--------------------------------------------------------         --------------------------------------------------------
                                               TO(0),KC_LSFT,         KC_BSPC, TO(2)
)
};


#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

