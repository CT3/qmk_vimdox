#pragma once

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SERIAL_PIN GP1

// Not yet available in `info.json`
#ifdef OLED_ENABLE
#    define OLED_FONT_H "keyboards/splitkb/aurora/corne/glcdfont.c"
#endif
