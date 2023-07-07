/* Copyright 2018-2019 eswai <@eswai>
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

#pragma once

void kana_type(void);
void kana_clear(void);
void compress_buffer(int nt);
bool kana_lookup(int nt, bool shifted);

bool process_modifier(uint16_t, keyrecord_t *);

//void kana_on(void);
void kana_on(bool r_sft_pressing, bool use_fn);
//void kana_off(void);
void kana_off(bool l_sft_pressing, bool use_fn);
void kana_on_keep_ime(void);
void kana_off_keep_ime(void);
bool kana_state(void);

bool process_kana(uint16_t, keyrecord_t *);
void set_kana(uint8_t);

typedef enum kana_keycodes {
  KN_Q = SAFE_RANGE,
  KN_W,
  KN_E,
  KN_R,
  KN_T,
  KN_Y,
  KN_U,
  KN_I,
  KN_O,
  KN_P,

  KN_A,
  KN_S,
  KN_D,
  KN_F,
  KN_G,
  KN_H,
  KN_J,
  KN_K,
  KN_L,
  KN_SCLN,

  KN_Z,
  KN_X,
  KN_C,
  KN_V,
  KN_BL,
  KN_BR,
  KN_N,
  KN_M,
  KN_COMM,
  KN_DOT,

  KN_SHFT,
} NGKEYS;

#define KN_SAFE_RANGE SAFE_RANGE+31
