#include QMK_KEYBOARD_H

/* * QMK Keymap with Lithuanian One-Shot Layer
 * OS Layout: English (US, intl., with dead keys)
 */

enum custom_layers {
    QWERTY,
    SYMB,
    NAV,
    ADJUST,
    LT_L, // Lithuanian Layer
};

enum custom_keycodes { LT_A = SAFE_RANGE, LT_C, LT_E, LT_EE, LT_I, LT_S, LT_U, LT_UU, LT_Z };

// Macro helper to press AltGr + Key then return to QWERTY
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case LT_A:
                register_code(KC_RALT);
                register_code(KC_A);
                unregister_code(KC_A);
                unregister_code(KC_RALT);
                layer_off(LT_L);
                return false;
            case LT_C:
                register_code(KC_RALT);
                register_code(KC_C);
                unregister_code(KC_C);
                unregister_code(KC_RALT);
                layer_off(LT_L);
                return false;
            case LT_E:
                register_code(KC_RALT);
                register_code(KC_E);
                unregister_code(KC_E);
                unregister_code(KC_RALT);
                layer_off(LT_L);
                return false;
            case LT_EE:
                register_code(KC_RALT);
                register_code(KC_V);
                unregister_code(KC_V);
                unregister_code(KC_RALT);
                layer_off(LT_L);
                return false; // Ė (AltGr+V)
            case LT_I:
                register_code(KC_RALT);
                register_code(KC_I);
                unregister_code(KC_I);
                unregister_code(KC_RALT);
                layer_off(LT_L);
                return false;
            case LT_S:
                register_code(KC_RALT);
                register_code(KC_S);
                unregister_code(KC_S);
                unregister_code(KC_RALT);
                layer_off(LT_L);
                return false;
            case LT_U:
                register_code(KC_RALT);
                register_code(KC_U);
                unregister_code(KC_U);
                unregister_code(KC_RALT);
                layer_off(LT_L);
                return false;
            case LT_UU:
                register_code(KC_RALT);
                register_code(KC_W);
                unregister_code(KC_W);
                unregister_code(KC_RALT);
                layer_off(LT_L);
                return false; // Ū (AltGr+W)
            case LT_Z:
                register_code(KC_RALT);
                register_code(KC_Z);
                unregister_code(KC_Z);
                unregister_code(KC_RALT);
                layer_off(LT_L);
                return false;
        }
    }
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT_split_3x6_3(
       KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_B,                                 KC_J, KC_L, KC_U, KC_Y, KC_SCLN, MT(KC_APP, KC_DEL),
       KC_ESC,  KC_A, KC_R, KC_S, KC_T, KC_G,                                 KC_M, KC_N, KC_E, KC_I, KC_O,    KC_LGUI,
       KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V,                                 KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, TT(NAV),
                                  KC_SPC, KC_LALT, KC_LCTL,           KC_BSPC, TT(SYMB), KC_ENT
    ),

    [SYMB] = LAYOUT_split_3x6_3(
        TO(ADJUST), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_LCBR,                 KC_RCBR, KC_PMNS, KC_PLUS, KC_EQL, KC_NO, KC_NO,
        TO(QWERTY), KC_PERC, KC_AMPR, KC_TILD, KC_ASTR, KC_LPRN,               KC_RPRN, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_HYPR,
        KC_LSFT,    KC_UNDS, KC_CIRC, ALGR(KC_5), OSL(LT_L), KC_LBRC,        KC_RBRC, KC_QUOT, KC_DQUO, KC_GRV, KC_NUHS, KC_MEH,
                                             KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [NAV] = LAYOUT_split_3x6_3(
        KC_F12,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                KC_PAST, KC_PLUS, KC_7, KC_8, KC_9, KC_CALC,
        TO(QWERTY), KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,               KC_PSLS, KC_PMNS, KC_4, KC_5, KC_6, KC_DOT,
        KC_TRNS,    KC_APP,  KC_F11,  KC_F12,  KC_F13,  KC_F14,               KC_PERC, KC_0,    KC_1,    KC_2,    KC_3,    KC_PDOT,
                                      KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [ADJUST] = LAYOUT_split_3x6_3(
        XXXXXXX,    KC_WSCH, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        TO(QWERTY), KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MSEL,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, KC_VOLD,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                                      KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [LT_L] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                 XXXXXXX, XXXXXXX, LT_UU,   LT_U,    XXXXXXX, KC_BSPC,
        XXXXXXX, LT_A,    XXXXXXX, LT_S,    XXXXXXX, XXXXXXX,                 XXXXXXX, LT_EE,   LT_E,    LT_I,    XXXXXXX, XXXXXXX,
        KC_LSFT, LT_Z,    XXXXXXX, LT_C,    XXXXXXX, XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    )
};
// clang-format on

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [SYMB] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [NAV] = {ENCODER_CCW_CW(KC_MSTP, KC_MPLY)}, [ADJUST] = {ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)}, [LT_L] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};