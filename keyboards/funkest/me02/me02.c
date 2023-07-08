/* Copyright 2020 ai03
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "me02.h"

// void matrix_init_kb(void) {
// 	// Initialize indicator LEDs to output
//     
//     //setPinOutput(B7); // Caps
// 	//setPinOutput(A5); // Slck
// 
// 	matrix_init_user();
// }
// 
// bool led_update_kb(led_t led_state) {
// 
//     bool res = led_update_user(led_state);
// 
//     if(res) {
//         // writePin(B7, !led_state.caps_lock);
//         // writePin(A5, !led_state.scroll_lock);
//     }
//     return res;
// }

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
// Key Matrix to LED Index
{
    { 39, 38, 37, 36, 35, 34, 33, 32   , 0, 1, 2, 3, 4, 5, 6, 7 }
  , { 40, 41, 42, 43, 44, 45, 46 ,47   , 15, 14, 13, 12, 11, 10, 9, 8 }
  , { 55, 54, 53, 52, 51, 50, 49 ,48   , 16, 17, 18, 19, 20, 21, 22, 23 }
  , { 56, 57, 58, 59, 60, 61, 62, 63   , 31, 30, 29, 28, 27, 26, 25, 24 } }
// LED Index to Physical Position
, {
    // right side
    { 119, 0 } , { 134, 0 } , { 149, 0 } , { 164, 0 } , { 179, 0 } , { 184, 0 } , { 199, 0 } , { 224, 0 }
  , { 224, 10 }, { 199, 10 }, { 184, 10 }, { 179, 10 }, { 164, 10 }, { 149, 10 }, { 134, 10 }, { 119, 10 }
  , { 119, 20 } , { 134, 20 } , { 149, 20 } , { 164, 20 } , { 179, 20 } , { 184, 20 } , { 199, 20 } , { 224, 20 }
  , { 224, 30 }, { 199, 30 }, { 184, 30 }, { 179, 30 }, { 164, 30 }, { 149, 30 }, { 134, 30 }, { 119, 30 }
    // left side
  , { 104, 0 } , { 89, 0 } , { 74, 0 } , { 59, 0 } , { 44, 0 } , { 29, 0 } , { 14, 0 } , {  0, 0 }
  , { 0, 10 } , { 14, 10 } , { 29, 10 } , { 44, 10 } , { 59, 10 } , { 74, 10 } , { 89, 10 } , {  104, 10 }
  , { 104, 20 } , { 89, 20 } , { 74, 20 } , { 59, 20 } , { 44, 20 } , { 29, 20 } , { 14, 20 } , {  0, 20 }
  , { 0, 30 } , { 14, 30 } , { 29, 30 } , { 44, 30 } , { 59, 30 } , { 74, 30 } , { 89, 30 } , {  104, 30 }
}
// LED Index to Flag
, {
    4, 4, 4, 4, 4, 4, 4, 4     , 4, 4, 4, 4, 4, 4, 4, 4
  , 4, 4, 4, 4, 4, 4, 4, 4     , 4, 4, 4, 4, 4, 4, 4, 4
  , 4, 4, 4, 4, 4, 4, 4, 4     , 4, 4, 4, 4, 4, 4, 4, 4
  , 4, 4, 4, 4, 4, 4, 4, 4     , 4, 4, 4, 4, 4, 4, 4, 4 }
};
#endif


void matrix_init_kb(void) {

#ifdef RGB_MATRIX_ENABLE
    //rgb_matrix_mode(RGB_MODE_BREATHE);
    //rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    //rgb_matrix_set_color_all(0, 0, 0);
#endif
    matrix_init_user();
}

// void keyboard_pre_init_kb(void) {
//     keyboard_pre_init_user();
// }
//
void i2c_init(void)
{
  setPinInput(B10); // Try releasing special pins for a short time
  setPinInput(B11);
  wait_ms(500); // Wait for the release to happen

  palSetPadMode(GPIOB, 10, PAL_MODE_ALTERNATE(1) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP); // Set B10 to I2C function
  palSetPadMode(GPIOB, 11, PAL_MODE_ALTERNATE(1) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP); // Set B11 to I2C function
}
