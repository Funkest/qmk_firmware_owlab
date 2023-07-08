#pragma once

/* USB Device descriptor parameter */
// #define VENDOR_ID       0x0001
// #define PRODUCT_ID      0x0001
// #define DEVICE_VER      0x0001
// #define MANUFACTURER    Funkest
// #define PRODUCT         Me02

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 16
#define RGB_MATRIX_LED_COUNT 64

//#define MATRIX_COL_PINS { B5, A3, A9, A8, B15, B14, B13, B12, B11, B10, B2, B1, B0, A7, A6 }
//#define MATRIX_ROW_PINS { A1, A2, B3, A15, A10 }

// 1st board
//#define MATRIX_COL_PINS { A4, A3, A2, A1, A0, F1, F0, C15,     A5, A6, A7, B0, B1, B8, B12, B13 }
//#define MATRIX_ROW_PINS { A15, A8, A9, B7 }

// 2nd board
#define MATRIX_COL_PINS { A4, A3, A2, A1, A0, F1, F0, C15,     A5, A6, A7, B0, B1, B2, B12, B13 }
#define MATRIX_ROW_PINS { A15, A8, A9, A10 }

#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

// https://github.com/qmk/qmk_firmware/blob/master/docs/i2c_driver.md
// B10 B11
#define I2C_DRIVER I2CD2
#define I2CD2_SCL_BANK GPIOB
#define I2CD2_SCL 10
#define I2CD2_SDA_BANK GPIOB
#define I2CD2_SDA 11

// Table 15. Alternate functions selected through GPIOB_AFR registers for port B
// B10 B11
#define I2CD2_SCL_PAL_MODE 1
#define I2CD2_SDA_PAL_MODE 1

#define I2CD2_OPMODE OPMODE_I2C
#define I2CD2_CLOCK_SPEED 100000
#define I2CD2_DUTY_CYCLE STD_DUTY_CYCLE

#define OLED_TIMEOUT 10000

#define RGB_DI_PIN B15
#define PORT_WS2812 GPIOB
#define PIN_WS2812 15
#define WS2812_EXTERNAL_PULLUP

#ifdef RGBLIGHT_ENABLE
    #define RGBLED_NUM 64
#endif

#ifdef RGB_MATRIX_ENABLE
  #define DRIVER_LED_TOTAL 64
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#   define RGB_DISABLE_AFTER_TIMEOUT 1000 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10
#endif

#ifdef RGBLIGHT_ENABLE
//  #define RGBLIGHT_SPLIT
//   #define RGBLIGHT_HUE_STEP 8
//   #define RGBLIGHT_SAT_STEP 8
//   #define RGBLIGHT_VAL_STEP 8
   #define RGBLIGHT_LIMIT_VAL 120 /* The maximum brightness level */
//   #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// /*== all animations enable ==*/
// /*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
#endif
