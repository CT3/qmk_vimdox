#include QMK_KEYBOARD_H

/* * Updated QMK Layout matching ZMK logic
 * 1. LOWER layer (F-keys & Numpad)
 * 2. RAISE layer (Symbols & Navigation with Euro)
 * 3. POWER layer (System, RGB, and Reset)
 */

enum custom_layers {
    QWERTY,
    LOWER,
    RAISE,
    POWER,
};

enum custom_keycodes {
    MC_EURO = SAFE_RANGE,
};

// Macro logic for Euro Symbol (€) via Right Alt + 5 (for US-International layout)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_EURO:
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code(KC_5);
                unregister_code(KC_RALT);
            }
            return false;
    }
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_TAB,  KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,                                  KC_J,  KC_L,  KC_U,  KC_Y,  KC_SCLN, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_ESC,  KC_A,  KC_R,  KC_S,  KC_T,  KC_G,                                  KC_M,  KC_N,  KC_E,  KC_I,  KC_O,    KC_LGUI,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,                                  KC_K,  KC_H,  KC_COMM, KC_DOT, KC_SLSH, MO(LOWER),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_SPC, KC_LALT, KC_LCTL,                     KC_BSPC, MO(RAISE), KC_ENT
        //`--------------------------'  `--------------------------'
    ),

    [LOWER] = LAYOUT_split_3x6_3(
        /* ------------------------- LOWER (NUMPAD / F-KEYS) ------------------------ */
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_TAB,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                             KC_ASTR, KC_PLUS, KC_7,   KC_8,   KC_9,   KC_CALC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           EE_CLR,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,                            KC_SLSH, KC_MINS, KC_4,   KC_5,   KC_6,   KC_DOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_LSFT, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                             KC_PERC, KC_0,    KC_1,   KC_2,   KC_3,   KC_TRNS,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [RAISE] = LAYOUT_split_3x6_3(
        /* ------------------------- RAISE (SYMBOLS / NAV) -------------------------- */
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           TO(POWER), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LCBR,                     KC_RCBR, KC_MINS, KC_PAST, KC_LPRN, KC_RPRN, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           TO(QWERTY),KC_PERC, KC_AMPR, KC_TILD, KC_ASTR, KC_LPRN,                     KC_RPRN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, LS(LG(KC_GRV)),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_LSFT, KC_UNDS, KC_CIRC, MC_EURO, KC_TRNS, KC_LBRC,                       KC_RBRC, KC_QUOT, KC_DQUO, KC_GRV,  KC_BSLS, KC_TILD,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [POWER] = LAYOUT_split_3x6_3(
        /* ------------------------- POWER/SYSTEM & RGB ----------------------------- */
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           QK_RBT,  KC_WSCH, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX,                       RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_K, RGB_M_G,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           TO(QWERTY), KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MSEL,                    RGB_HUI, RGB_HUD, RGB_VAI, RGB_VAD, RGB_SAI, RGB_SAD,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           RGB_MOD, RGB_TOG, KC_LGUI, KC_SLEP, KC_VOLU, KC_VOLD,                       RGB_MOD, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, QK_BOOT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS
    )
};
// clang-format on

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [QWERTY] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LOWER]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [RAISE]  = {ENCODER_CCW_CW(KC_MSTP, KC_MPLY), ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
    [POWER]  = {ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)},
};

// LED Segment Definitions
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 3, HSV_CYAN});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 3, HSV_RED});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 3, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 3, HSV_BLUE});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, POWER));
    return state;
}
