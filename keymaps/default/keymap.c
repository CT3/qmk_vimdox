#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    SYMB,
    NAV,
    ADJUST,
};

// Shortcut to make keymap more readable
#define MY_BSPC LT(0, KC_BSPC)
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B,                                 KC_J, KC_L, KC_U, KC_Y, KC_SCLN,  MT(MOD_LGUI, KC_DEL),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G,                                           KC_M, KC_N, KC_E, KC_I, KC_O, KC_UNDS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V,                                          KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, TT(_NAV),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_SPC, TT(_SYMB), KC_LCTL,                     KC_LALT, MY_BSPC, KC_ENT
        //`--------------------------'  `--------------------------'

        ),

    [_SYMB] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TO(_ADJUST), KC_EXLM, KC_AT, KC_NUHS, KC_AMPR, KC_LCBR,                            KC_RCBR, KC_PMNS, KC_PLUS, KC_EQL, KC_BTN1, KC_BTN2,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TO(_QWERTY), KC_PERC, KC_DLR, KC_HASH, KC_ASTR, KC_LPRN,                        KC_RPRN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_INT4, KC_CIRC, KC_GRV, KC_INT3, KC_LBRC,                              KC_RBRC, KC_QUOT, KC_DQUO, KC_TILD, KC_NUBS, KC_PGDN,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS
        //`--------------------------'  `--------------------------'
        ),

    [_NAV] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                      KC_PAST, KC_PLUS, KC_7, KC_8, KC_9, KC_CALC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TO(_QWERTY), KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                                KC_PSLS, KC_PMNS, KC_4, KC_5, KC_6, KC_DOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, KC_APP, KC_F11, KC_F12, KC_F13, KC_F14,                              KC_PERC, KC_0, KC_1, KC_2, KC_3, KC_PDOT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS
        //`--------------------------'  `--------------------------'
        ),

    [_ADJUST] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_WSCH, XXXXXXX, KC_SLEP, KC_WAKE, KC_PWR,                           RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_K, RGB_M_G,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TO(_QWERTY), KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MSEL,                      RGB_HUI, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_TOG, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS,KC_TRNS, KC_TRNS,                   KC_TRNS,KC_TRNS,KC_TRNS 
        //`--------------------------'  `--------------------------'
        )};
// clang-format on
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state | default_layer_state) > 0) {
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    } else { /* Layer 0 */
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_MS_WH_DOWN);
            } else {
                tap_code(KC_MS_WH_UP);
            }
        }
    }

    return false;
}

// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_CYAN});
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 3, HSV_RED});
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 3, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 3, HSV_WHITE});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(my_layer1_layer, // Overrides caps lock layer
                                                                               my_layer2_layer, // Overrides other layers
                                                                               my_layer3_layer, // Overrides other layers
                                                                               my_layer4_layer  // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYMB));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}

// Helper for implementing tap vs. long-press keys. Given a tap-hold
// key event, replaces the hold function with `long_press_keycode`.
static bool process_tap_or_long_press_key(keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count == 0) { // Key is being held.
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
        }
        return false; // Skip default handling.
    }
    return true; // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MY_BSPC: // Comma on tap, Ctrl+C on long press.
            return process_tap_or_long_press_key(record, C(KC_BSPC));
    }

    return true;
}
