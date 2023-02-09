/* Copyright 2022 Mantas Jurkuvenas

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
// #define VENDOR_ID 0x4D44  // "MD"
// #define PRODUCT_ID 0x5244 // "RD"
// #define DEVICE_VER 0x0100
// #define MANUFACTURER Mantastic
// #define PRODUCT TheVimdoxKeyboard

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS \
    { D1, D0, B2, B6 }

// wiring of each half
#define MATRIX_COL_PINS \
    { D4, C6, D7, E6, B4, B5 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
#define RGBLIGHT_LIMIT_VAL 250
#define LED_DISABLE_WHEN_USB_SUSPENDED
/* define if matrix has ghost */
// #define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D2

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN F4

#define RGBLED_NUM 21 // Number of LEDs
#define RGBLIGHT_LAYERS
#define RGBLIGHT_SPLIT // sync LEDs between RIGHT and LEFT hand

#define ENCODERS_PAD_A \
    { F5 }
#define ENCODERS_PAD_B \
    { F6 }

#define ENCODER_RESOLUTION 2
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
