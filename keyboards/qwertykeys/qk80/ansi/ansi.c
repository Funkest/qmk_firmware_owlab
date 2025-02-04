/* 
Copyright 2022 Qwertykeys

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
#include "ansi.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, CS3_SW1,  CS2_SW1,  CS1_SW1},  /* RGB0-ESC ROW0*/
    {0, CS6_SW1,  CS5_SW1,  CS4_SW1},  /* RGB1-F1 */
    {0, CS9_SW1,  CS8_SW1,  CS7_SW1},  /* RGB2-F2 */
    {0, CS12_SW1,  CS11_SW1,  CS10_SW1},  /* RGB3-F3 */
    {0, CS15_SW1,  CS14_SW1,  CS13_SW1},  /* RGB4-F4 */
    {0, CS18_SW1,  CS17_SW1,  CS16_SW1},  /* RGB5-F5 */
    {0, CS21_SW1,  CS20_SW1,  CS19_SW1},  /* RGB6-F6 */
    {0, CS24_SW1,  CS23_SW1,  CS22_SW1},  /* RGB7-F7 */
    {0, CS27_SW1,  CS26_SW1,  CS25_SW1},  /* RGB8-F8 */
    {0, CS30_SW1,  CS29_SW1,  CS28_SW1},  /* RGB9-F9 */
    {0, CS33_SW1,  CS32_SW1,  CS31_SW1},  /* RGB10-F10 */
    {0, CS36_SW1,  CS35_SW1,  CS34_SW1},  /* RGB11-F11 */
    {0, CS39_SW1,  CS38_SW1,  CS37_SW1},  /* RGB12-F12 */
    {0, CS36_SW7,  CS35_SW7,  CS34_SW7},  /* RGB13-F13 */
    {0, CS33_SW7,  CS32_SW7,  CS31_SW7},  /* RGB14-PSc */
    {0, CS33_SW8,  CS32_SW8,  CS31_SW8},  /* RGB15-ScrLk */
    {0, CS33_SW9,  CS32_SW9,  CS31_SW9}, /* RGB16-Pause */

    {0, CS3_SW2,  CS2_SW2,  CS1_SW2},  /* RGB17-~ ----ROW1*/
    {0, CS6_SW2,  CS5_SW2,  CS4_SW2},  /* RGB18-1 */
    {0, CS9_SW2,  CS8_SW2,  CS7_SW2},  /* RGB19-2 */
    {0, CS12_SW2,  CS11_SW2,  CS10_SW2},  /* RGB20-3 */
    {0, CS15_SW2,  CS14_SW2,  CS13_SW2},  /* RGB21-4 */
    {0, CS18_SW2,  CS17_SW2,  CS16_SW2},  /* RGB22-5 */
    {0, CS21_SW2,  CS20_SW2,  CS19_SW2},  /* RGB23-6 */
    {0, CS24_SW2,  CS23_SW2,  CS22_SW2},  /* RGB24-7 */
    {0, CS27_SW2,  CS26_SW2,  CS25_SW2},  /* RGB25-8 */
    {0, CS30_SW2,  CS29_SW2,  CS28_SW2},  /* RGB26-9 */
    {0, CS33_SW2,  CS32_SW2,  CS31_SW2},  /* RGB27-0 */
    {0, CS36_SW2,  CS35_SW2,  CS34_SW2},  /* RGB28--- */
    {0, CS39_SW2,  CS38_SW2,  CS37_SW2},  /* RGB29-+= */
    {0, CS36_SW8,  CS35_SW8,  CS34_SW8},  /* RGB30-BS */
    {0, CS27_SW7,  CS26_SW7,  CS25_SW7},  /* RGB31-Insert */
    {0, CS30_SW7,  CS29_SW7,  CS28_SW7},  /* RGB32-Home */
    {0, CS39_SW5,  CS38_SW5,  CS37_SW5},  /* RGB33-PageUp */

    {0, CS3_SW3,  CS2_SW3,  CS1_SW3},  /* RGB34-TAB ----ROW2*/
    {0, CS6_SW3,  CS5_SW3,  CS4_SW3}, /* RGB35-Q */
    {0, CS9_SW3,  CS8_SW3,  CS7_SW3}, /* RGB36-W */
    {0, CS12_SW3,  CS11_SW3,  CS10_SW3}, /* RGB37-E */
    {0, CS15_SW3,  CS14_SW3,  CS13_SW3}, /* RGB38-R */
    {0, CS18_SW3,  CS17_SW3,  CS16_SW3}, /* RGB39-T */
    {0, CS21_SW3,  CS20_SW3,  CS19_SW3}, /* RGB40-Y */
    {0, CS24_SW3,  CS23_SW3,  CS22_SW3}, /* RGB41-U */
    {0, CS27_SW3,  CS26_SW3,  CS25_SW3}, /* RGB42-I */
    {0, CS30_SW3,  CS29_SW3,  CS28_SW3}, /* RGB43-O */
    {0, CS33_SW3,  CS32_SW3,  CS31_SW3}, /* RGB44-P */
    {0, CS36_SW3,  CS35_SW3,  CS34_SW3}, /* RGB45-[ */
    {0, CS39_SW3,  CS38_SW3,  CS37_SW3}, /* RGB46-] */
    {0, CS36_SW9,  CS35_SW9,  CS34_SW9}, /* RGB47-\ */
    {0, CS27_SW8,  CS26_SW8,  CS25_SW8},  /* RGB48-Delete */
    {0, CS30_SW8,  CS29_SW8,  CS28_SW8},  /* RGB49-End */
    {0, CS33_SW6,  CS32_SW6,  CS31_SW6},  /* RGB50-PageDown */

    {0, CS3_SW4,  CS2_SW4,  CS1_SW4},  /* RGB51-CAPS---ROW3*/
    {0, CS6_SW4,  CS5_SW4,  CS4_SW4},  /* RGB52-A-- */
    {0, CS9_SW4,  CS8_SW4,  CS7_SW4},  /* RGB53-S-- */
    {0, CS12_SW4,  CS11_SW4,  CS10_SW4},  /* RGB54-D */
    {0, CS15_SW4,  CS14_SW4,  CS13_SW4},  /* RGB55-F */
    {0, CS18_SW4,  CS17_SW4,  CS16_SW4},  /* RGB56-G */
    {0, CS21_SW4,  CS20_SW4,  CS19_SW4},  /* RGB57-H */
    {0, CS24_SW4,  CS23_SW4,  CS22_SW4},  /* RGB58-J */
    {0, CS27_SW4,  CS26_SW4,  CS25_SW4},  /* RGB59-K */
    {0, CS30_SW4,  CS29_SW4,  CS28_SW4},  /* RGB60-L */
    {0, CS33_SW4,  CS32_SW4,  CS31_SW4},  /* RGB61-;: */
    {0, CS36_SW4,  CS35_SW4,  CS34_SW4},  /* RGB62-'" */
    {0, CS39_SW4,  CS38_SW4,  CS37_SW4},  /* RGB63-ENTER */

    {0, CS3_SW5,  CS2_SW5,  CS1_SW5},  /* RGB64-LSF --ROW4*/
    {0, CS6_SW5,  CS5_SW5,  CS4_SW5},  /* RGB65-Z */
    {0, CS9_SW5,  CS8_SW5,  CS7_SW5},  /* RGB66-X */
    {0, CS12_SW5,  CS11_SW5,  CS10_SW5},  /* RGB67-C */
    {0, CS15_SW5,  CS14_SW5,  CS13_SW5},  /* RGB68-V */
    {0, CS18_SW5,  CS17_SW5,  CS16_SW5},  /* RGB69-B */
    {0, CS21_SW5,  CS20_SW5,  CS19_SW5},  /* RGB70-N */
    {0, CS24_SW5,  CS23_SW5,  CS22_SW5},  /* RGB71-M */
    {0, CS27_SW5,  CS26_SW5,  CS25_SW5},  /* RGB72-,< */
    {0, CS30_SW5,  CS29_SW5,  CS28_SW5},  /* RGB73->. */
    {0, CS33_SW5,  CS32_SW5,  CS31_SW5},  /* RGB74-?/ */
    {0, CS36_SW5,  CS35_SW5,  CS34_SW5},  /* RGB75-RSF */
    {0, CS36_SW6,  CS35_SW6,  CS34_SW6},  /* RGB76-UP */

    {0, CS3_SW6, CS2_SW6, CS1_SW6}, /* RGB77-lct-- ROW5*/
    {0, CS6_SW6, CS5_SW6, CS4_SW6}, /* RGB78-lwin */
    {0, CS9_SW6, CS8_SW6, CS7_SW6}, /* RGB79-lalt */
    {0, CS15_SW6, CS14_SW6, CS13_SW6}, /* RGB80-sp */
    {0, CS24_SW6, CS23_SW6, CS22_SW6}, /* RGB81-ralt */
    {0, CS27_SW6, CS26_SW6, CS25_SW6}, /* RGB82-rwin */
    {0, CS30_SW6, CS29_SW6, CS28_SW6}, /* RGB83-rct */
    {0, CS39_SW6, CS38_SW6, CS37_SW6}, /* RGB84-left */
    {0, CS27_SW9, CS26_SW9, CS25_SW9}, /* RGB85-down */
    {0, CS30_SW9, CS29_SW9, CS28_SW9}  /* RGB86-right */
};

led_config_t g_led_config = { {
    { 0,  1,  2,  3,     4,  5,     6,      7,     8,      9,  10, 11,    12,  13, 14  },
    { 17, 18, 19, 20,    21, 22,    23,     24,    25,     26, 27, 28,    29,  30, 15  },
    { 34, 35, 36, 37,    38, 39,    40,     41,    42,     43, 44, 45,    46,  47, 16  },
    { 51, 52, 53, 54,    55, 56,    57,     58,    59,     60, 61, 62,    63,  31, 32  },
    { 64, 65, 66, 67,    68, 69,    70,     71,    72,     73, 74, 75,    33,  48, 49  },
    { 77, 78, 79, NO_LED,80, NO_LED,NO_LED, 81,    82,     83, 50, 76,    84,  85, 86  }
}, {
    // LED Index to Physical Position
    { 0, 0 },  { 14, 0 },  { 28, 0 },  { 42, 0 },  { 56, 0 },  { 70, 0 },  { 84, 0 },  { 98, 0 },   { 112, 0 },  { 126, 0 },  { 140, 0 },  { 154, 0 },  { 168, 0 },  { 182, 0 },  { 196, 0 },  { 210, 0 }, { 224, 0 }, 
    { 0, 13 }, { 14, 13 }, { 28, 13 }, { 42, 13 }, { 56, 13 }, { 70, 13 }, { 84, 13},  { 98, 13 },  { 112, 13 }, { 126, 13 }, { 140, 13 }, { 154, 13 }, { 168, 13 }, { 182, 13 }, { 196, 13 }, { 210, 13 },{ 224, 13 }, 
    { 0, 26 }, { 14, 26 }, { 28, 26 }, { 42, 26 }, { 56, 26 }, { 70, 26 }, { 84, 26 }, { 98, 26 },  { 112, 26 }, { 126, 26 }, { 140, 26 }, { 154, 26 }, { 168, 26 }, { 182, 26 }, { 196, 26 }, { 210, 26 },{ 224, 26 }, 
    { 0, 39 }, { 14, 39 }, { 28, 39 }, { 42, 39 }, { 56, 39 }, { 70, 39 }, { 84, 39 }, { 98, 39 },  { 112, 39 }, { 126, 39 }, { 140, 39 }, { 154, 39 },              { 182, 39 }, 
    { 0, 52 }, { 14, 52 }, { 28, 52 }, { 42, 52 }, { 56, 52 }, { 70, 52 }, { 84, 52 }, { 98, 52 },  { 112, 52 }, { 126, 52 }, { 140, 52 },                           { 182, 52 },              { 210, 52 }, 
    { 0, 64 }, { 14, 64 }, { 28, 64 },                         { 70, 64 },                                       { 126, 64 }, { 140, 64 },                           { 182, 64 }, { 196, 64 }, { 210, 64 },{ 224, 64 }
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,       1,    1,
    1, 1, 1,       4,          1, 1,       1, 1, 1, 1
    }
};




bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
        
        case KC_F14:
        rgb_matrix_toggle(); 
        break;

        case KC_F15:
        rgb_matrix_step(); 
        break;

        case KC_F16:  
        rgb_matrix_step_reverse();  
        break;

        case KC_F17:
        rgb_matrix_increase_hue();  //Increase the hue for effect range LEDs
        break;

        case KC_F18:
        rgb_matrix_decrease_hue(); //Decrease the hue for effect range LEDs
        break;

        case KC_F19:
        rgb_matrix_increase_sat(); //Increase the saturation for effect range LEDs
        break;

        case KC_F20:
        rgb_matrix_decrease_sat(); //Decrease the saturation for effect range LEDs
        break;

        case KC_F21:
        rgb_matrix_increase_val(); //Increase the value for effect range LEDs
        break;

        case KC_F22:
        rgb_matrix_decrease_val();//Decrease the value for effect range LEDs
        break;

   
        default:
        break;
    }
  }
  return process_record_user(keycode, record);
}

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

__attribute__ ((weak))
void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(51, 0xFF, 0xFF, 0xFF);
    }
}

#endif