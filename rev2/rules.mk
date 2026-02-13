# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# Board design
BOARD = GENERIC_RP_RP2040

# Build options
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
SPLIT_KEYBOARD = yes        # Enable split keyboard support
ENCODER_MAP_ENABLE = yes
WS2812_DRIVER = vendor
SERIAL_DRIVER = vendor
UNICODE_COMMON = yes
UNICODE_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control
LED_CAPS_LOCK_ENABLE = no   # Disable Caps Lock LED
BACKLIGHT_ENABLE = no       # Disable backlight
