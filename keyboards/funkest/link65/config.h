#pragma once

// http://www.neko.ne.jp/~freewing/hardware/qmk_update_program_with_newest_firmware_2022/

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { A1, A2, A3, A4, A5 }
#define MATRIX_COL_PINS { A7, B0, B1, B2, B10, B11, B12, B13, B14, B15, A8, A9, A10, A6, A15 }
#define DIODE_DIRECTION COL2ROW
#define USB_POLLING_INTERVAL_MS 1
#define LED_CAPS_LOCK_PIN A0
#define LED_PIN_ON_STATE	0

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
/* NKRO */
#ifdef NKRO_ENABLE
#    define FORCE_NKRO
#endif
