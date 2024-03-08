#pragma once
#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 5
#define SPLIT_LAYER_STATE_ENABLE
// `SPLIT_HAND_PIN` can currently be defined in `info.json`,
// but can't yet be given a value
// #define SPLIT_HAND_PIN F4

// Not yet available in `info.json`
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define SPLIT_OLED_ENABLE
#endif
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
// Not yet available in `info.json`
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#    define RGB_MATRIX_LED_COUNT 54
#    define RGB_MATRIX_SPLIT \
        { 27, 27 }
#    define SPLIT_TRANSPORT_MIRROR
#endif
