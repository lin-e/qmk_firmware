/*
Copyright 2019 Ryota Goto

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
#define VENDOR_ID       0xA103 // ai03
#define PRODUCT_ID      0x0013
#define DEVICE_VER      0x0001
#define MANUFACTURER    lin-e
#define PRODUCT         KBD67-MKII
#define DESCRIPTION     65% Keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { B3, D0, D1, D2, D3 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, C7, C6, B6, B5, B4, D7, D6, D4, D5 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN B7
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_BREATHING
#define BACKLIGHT_LEVELS 3
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define TAPPING_TERM 200

#define DYNAMIC_MACRO_NO_NESTING

#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MAX_SPEED 1
#define MOUSEKEY_TIME_TO_MAX 40

#define MOUSEKEY_WHEEL_MAX_SPEED 1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80