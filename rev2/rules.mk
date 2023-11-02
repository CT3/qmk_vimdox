# Copyright 2022 splitkb.com <support@splitkb.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Although no rules are defined,
# presence of this file is required for QMK to compile it.
#
#
MCU = RP2040
# Bootloader selection
BOOTLOADER = rp2040

BOARD = GENERIC_RP_RP2040

#BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
ENCODER_MAP_ENABLE = yes
WS2812_DRIVER = vendor
SERIAL_DRIVER = vendor
#EXTRAKEY_ENABLE = yes       # Audio control and System control
