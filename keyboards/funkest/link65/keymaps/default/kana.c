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

#include QMK_KEYBOARD_H
#include "kana.h"

#if !defined(__AVR__)
  #include <string.h>
#endif

#define NGBUFFER 10 // キー入力バッファのサイズ

//#ifdef KANA_TATEGAKI
//  #define NGUP X_UP
//  #define NGDN X_DOWN
//  #define NGLT X_LEFT
//  #define NGRT X_RIGHT
//  #define NGKUP KC_UP
//  #define NGKDN KC_DOWN
//  #define NGKLT KC_LEFT
//  #define NGKRT KC_RIGHT
//#endif
//#ifdef KANA_YOKOGAKI
//  #define NGUP X_LEFT
//  #define NGDN X_RIGHT
//  #define NGLT X_UP
//  #define NGRT X_DOWN
//  #define NGKUP KC_LEFT
//  #define NGKDN KC_RIGHT
//  #define NGKLT KC_UP
//  #define NGKRT KC_DOWN
//#endif

static uint8_t ng_chrcount = 0; // 文字キー入力のカウンタ
static bool is_kana = false; // kana がオンかオフか
static uint8_t kana_layer = 0; // KN_*を配置しているレイヤー番号
static uint32_t keycomb = 0UL; // 同時押しの状態を示す。32bitの各ビットがキーに対応する。

// 31キーを32bitの各ビットに割り当てる
#define B_Q    (1UL<<0)
#define B_W    (1UL<<1)
#define B_E    (1UL<<2)
#define B_R    (1UL<<3)
#define B_T    (1UL<<4)

#define B_Y    (1UL<<5)
#define B_U    (1UL<<6)
#define B_I    (1UL<<7)
#define B_O    (1UL<<8)
#define B_P    (1UL<<9)

#define B_A    (1UL<<10)
#define B_S    (1UL<<11)
#define B_D    (1UL<<12)
#define B_F    (1UL<<13)
#define B_G    (1UL<<14)

#define B_H    (1UL<<15)
#define B_J    (1UL<<16)
#define B_K    (1UL<<17)
#define B_L    (1UL<<18)
#define B_SCLN (1UL<<19)

#define B_Z    (1UL<<20)
#define B_X    (1UL<<21)
#define B_C    (1UL<<22)
#define B_V    (1UL<<23)
#define B_BL   (1UL<<24)

#define B_BR   (1UL<<25)
#define B_N    (1UL<<26)
#define B_M    (1UL<<27)
#define B_COMM (1UL<<28)
#define B_DOT  (1UL<<29)

#define B_SHFT (1UL<<30)

// 文字入力バッファ
static uint16_t ninputs[NGBUFFER];

// キーコードとキービットの対応
// メモリ削減のため配列はKN_Qを0にしている
const uint32_t ng_key[] = {
  [KN_Q    - KN_Q] = B_Q,
  [KN_W    - KN_Q] = B_W,
  [KN_E    - KN_Q] = B_E,
  [KN_R    - KN_Q] = B_R,
  [KN_T    - KN_Q] = B_T,

  [KN_Y    - KN_Q] = B_Y,
  [KN_U    - KN_Q] = B_U,
  [KN_I    - KN_Q] = B_I,
  [KN_O    - KN_Q] = B_O,
  [KN_P    - KN_Q] = B_P,

  [KN_A    - KN_Q] = B_A,
  [KN_S    - KN_Q] = B_S,
  [KN_D    - KN_Q] = B_D,
  [KN_F    - KN_Q] = B_F,
  [KN_G    - KN_Q] = B_G,

  [KN_H    - KN_Q] = B_H,
  [KN_J    - KN_Q] = B_J,
  [KN_K    - KN_Q] = B_K,
  [KN_L    - KN_Q] = B_L,
  [KN_SCLN - KN_Q] = B_SCLN,

  [KN_Z    - KN_Q] = B_Z,
  [KN_X    - KN_Q] = B_X,
  [KN_C    - KN_Q] = B_C,
  [KN_V    - KN_Q] = B_V,
  [KN_BL   - KN_Q] = B_BL,

  [KN_BR   - KN_Q] = B_BR,
  [KN_N    - KN_Q] = B_N,
  [KN_M    - KN_Q] = B_M,
  [KN_COMM - KN_Q] = B_COMM,
  [KN_DOT  - KN_Q] = B_DOT,

  [KN_SHFT - KN_Q] = B_SHFT,
};

// 順序なし
typedef struct {
  uint32_t key;
  char kana[7];
} kana_keymap;

// 順序なしロング
typedef struct {
  uint32_t key;
  char kana[15];
} kana_keymap_long;

// 順序なしUNICODE
typedef struct {
  uint32_t key;
  char kana[10];
} kana_keymap_unicode;

const PROGMEM kana_keymap ngmap[] = {
    {.key = B_SHFT|B_H          , .kana = ","       } // 、
  , {.key = B_P                 , .kana = "."       } // 。
  , {.key = B_SHFT|B_G          , .kana = "."       } // 。
  , {.key = B_SHFT|B_BR         , .kana = "a"       } // あ
  , {.key = B_F                 , .kana = "i"       } // い
  , {.key = B_J                 , .kana = "i"       } // い
  , {.key = B_SHFT|B_T          , .kana = "lu"      } // ぅ
  , {.key = B_S                 , .kana = "u"       } // う
  , {.key = B_SHFT|B_M          , .kana = "e"       } // え
  , {.key = B_SHFT|B_I          , .kana = "o"       } // お
  , {.key = B_L                 , .kana = "ka"      } // か
  , {.key = B_U                 , .kana = "ga"      } // が
  , {.key = B_R                 , .kana = "ki"      } // き
  , {.key = B_X                 , .kana = "ku"      } // く
  , {.key = B_SHFT|B_F          , .kana = "ke"      } // け
  , {.key = B_COMM              , .kana = "ko"      } // こ
  , {.key = B_SHFT|B_E          , .kana = "sa"      } // さ
  , {.key = B_D                 , .kana = "si"      } // し
  , {.key = B_O                 , .kana = "su"      } // す
  , {.key = B_SHFT|B_S          , .kana = "se"      } // せ
  , {.key = B_SHFT|B_L          , .kana = "so"      } // そ
  , {.key = B_BL                , .kana = "ta"      } // た
  , {.key = B_SHFT|B_W          , .kana = "ti"      } // ち
  , {.key = B_A                 , .kana = "ltu"     } // っ
  , {.key = B_G                 , .kana = "tu"      } // つ
  , {.key = B_V                 , .kana = "te"      } // て
  , {.key = B_M                 , .kana = "de"      } // で
  , {.key = B_N                 , .kana = "to"      } // と
  , {.key = B_BR                , .kana = "na"      } // な
  , {.key = B_C                 , .kana = "ni"      } // に
  , {.key = B_SHFT|B_Y          , .kana = "nu"      } // ぬ
  , {.key = B_SHFT|B_U          , .kana = "ne"      } // ね
  , {.key = B_I                 , .kana = "no"      } // の
  , {.key = B_H                 , .kana = "ha"      } // は
  , {.key = B_T                 , .kana = "hi"      } // ひ
  , {.key = B_Q                 , .kana = "hu"      } // ふ
  , {.key = B_SHFT|B_Q          , .kana = "hu"      } // ふ
  , {.key = B_DOT               , .kana = "he"      } // へ
  , {.key = B_Y                 , .kana = "ho"      } // ほ
  , {.key = B_SCLN              , .kana = "ma"      } // ま
  , {.key = B_SHFT|B_P          , .kana = "mi"      } // み
  , {.key = B_SHFT|B_X          , .kana = "mu"      } // む
  , {.key = B_SHFT|B_A          , .kana = "me"      } // め
  , {.key = B_E                 , .kana = "mo"      } // も
  , {.key = B_SHFT|B_SCLN       , .kana = "ya"      } // や
  , {.key = B_SHFT|B_N          , .kana = "lyu"     } // ゅ
  , {.key = B_SHFT|B_D          , .kana = "lyo"     } // ょ
  , {.key = B_SHFT|B_C          , .kana = "yo"      } // よ
  , {.key = B_SHFT|B_R          , .kana = "ra"      } // ら
  , {.key = B_SHFT|B_J          , .kana = "ri"      } // り
  , {.key = B_W                 , .kana = "ru"      } // る
  , {.key = B_SHFT|B_O          , .kana = "re"      } // れ
  , {.key = B_SHFT|B_BL         , .kana = "ro"      } // ろ
  , {.key = B_SHFT|B_COMM       , .kana = "wa"      } // わ
  , {.key = B_SHFT|B_K          , .kana = "wo"      } // を
  , {.key = B_K                 , .kana = "nn"      } // ん
  , {.key = B_SHFT|B_V          , .kana = "-"       } // ー
  , {.key = B_Z|B_BR            , .kana = "la"      } // ぁ
  , {.key = B_Z|B_F             , .kana = "li"      } // ぃ
  , {.key = B_Z|B_J             , .kana = "li"      } // ぃ
  , {.key = B_Z|B_S             , .kana = "lu"      } // ぅ
  , {.key = B_Z|B_M             , .kana = "le"      } // ぇ
  , {.key = B_Z|B_I             , .kana = "lo"      } // ぉ
  , {.key = B_Z|B_SCLN          , .kana = "lya"     } // ゃ
  , {.key = B_Z|B_N             , .kana = "yu"      } // ゆ
  , {.key = B_Z|B_COMM          , .kana = "lwa"     } // ゎ
  , {.key = B_SHFT|B_Z          , .kana = "vu"      } // ゔ
  , {.key = B_J|B_A             , .kana = "vu"      } // ゔ
  , {.key = B_J|B_R             , .kana = "gi"      } // ぎ
  , {.key = B_J|B_X             , .kana = "gu"      } // ぐ
  , {.key = B_J|B_F             , .kana = "ge"      } // げ
  , {.key = B_F|B_COMM          , .kana = "go"      } // ご
  , {.key = B_J|B_E             , .kana = "za"      } // ざ
  , {.key = B_J|B_D             , .kana = "zi"      } // じ
  , {.key = B_F|B_O             , .kana = "zu"      } // ず
  , {.key = B_J|B_S             , .kana = "ze"      } // ぜ
  , {.key = B_F|B_L             , .kana = "zo"      } // ぞ
  , {.key = B_J|B_BL            , .kana = "da"      } // だ
  , {.key = B_J|B_W             , .kana = "di"      } // ぢ
  , {.key = B_J|B_G             , .kana = "du"      } // づ
  , {.key = B_F|B_N             , .kana = "do"      } // ど
  , {.key = B_F|B_H             , .kana = "ba"      } // ば
  , {.key = B_Z|B_H             , .kana = "pa"      } // ぱ
  , {.key = B_J|B_T             , .kana = "bi"      } // び
  , {.key = B_Z|B_T             , .kana = "pi"      } // ぴ
  , {.key = B_J|B_Q             , .kana = "bu"      } // ぶ
  , {.key = B_Z|B_Q             , .kana = "pu"      } // ぷ
  , {.key = B_F|B_DOT           , .kana = "be"      } // べ
  , {.key = B_Z|B_DOT           , .kana = "pe"      } // ぺ
  , {.key = B_F|B_Y             , .kana = "bo"      } // ぼ
  , {.key = B_Z|B_Y             , .kana = "po"      } // ぽ
  , {.key = B_D|B_M             , .kana = "she"     } // しぇ
  , {.key = B_W|B_M             , .kana = "che"     } // ちぇ
  , {.key = B_W|B_SCLN          , .kana = "cha"     } // ちゃ
  , {.key = B_C|B_SCLN          , .kana = "nya"     } // にゃ
  , {.key = B_T|B_SCLN          , .kana = "hya"     } // ひゃ
  , {.key = B_P|B_SCLN          , .kana = "mya"     } // みゃ
  , {.key = B_J|B_R|B_SCLN      , .kana = "gya"     } // ぎゃ
  , {.key = B_J|B_D|B_M         , .kana = "je"      } // じぇ
  , {.key = B_J|B_D|B_SCLN      , .kana = "ja"      } // じゃ
  , {.key = B_J|B_W|B_M         , .kana = "dya"     } // ぢぇ
  , {.key = B_J|B_W|B_SCLN      , .kana = "dya"     } // ぢゃ
  , {.key = B_J|B_T|B_SCLN      , .kana = "bya"     } // びゃ
  , {.key = B_N|B_T|B_SCLN      , .kana = "pya"     } // ぴゃ
  , {.key = B_N|B_S|B_F         , .kana = "wi"      } // うぃ
  , {.key = B_N|B_S|B_M         , .kana = "we"      } // うぇ
  , {.key = B_N|B_S|B_I         , .kana = "ulo"     } // うぉ
  , {.key = B_N|B_X|B_BR        , .kana = "kwa"     } // くぁ
  , {.key = B_N|B_X|B_F         , .kana = "kuli"    } // くぃ
  , {.key = B_N|B_X|B_M         , .kana = "kule"    } // くぇ
  , {.key = B_N|B_X|B_I         , .kana = "kulo"    } // くぉ
  , {.key = B_N|B_X|B_COMM      , .kana = "kulwa"   } // くゎ
  , {.key = B_N|B_G|B_BR        , .kana = "tsa"     } // つぁ
  , {.key = B_N|B_G|B_F         , .kana = "tsi"     } // つぃ
  , {.key = B_N|B_G|B_M         , .kana = "tse"     } // つぇ
  , {.key = B_N|B_G|B_I         , .kana = "tso"     } // つぉ
  , {.key = B_N|B_V|B_F         , .kana = "thi"     } // てぃ
  , {.key = B_V|B_M|B_J         , .kana = "dhi"     } // でぃ
  , {.key = B_V|B_N|B_S         , .kana = "twu"     } // とぅ
  , {.key = B_N|B_Q|B_BR        , .kana = "fa"      } // ふぁ
  , {.key = B_N|B_Q|B_F         , .kana = "fi"      } // ふぃ
  , {.key = B_N|B_Q|B_M         , .kana = "fe"      } // ふぇ
  , {.key = B_N|B_Q|B_I         , .kana = "fo"      } // ふぉ
  , {.key = B_J|B_S|B_BR        , .kana = "va"      } // ゔぁ
  , {.key = B_J|B_S|B_F         , .kana = "vi"      } // ゔぃ
  , {.key = B_J|B_S|B_M         , .kana = "ve"      } // ゔぇ
  , {.key = B_J|B_S|B_I         , .kana = "vo"      } // ゔぉ
  , {.key = B_J|B_X|B_BR        , .kana = "gwa"     } // ぐぁ
  , {.key = B_J|B_X|B_F         , .kana = "gwi"     } // ぐぃ
  , {.key = B_J|B_X|B_M         , .kana = "gwe"     } // ぐぇ
  , {.key = B_J|B_X|B_I         , .kana = "gwo"     } // ぐぉ
  , {.key = B_J|B_X|B_COMM      , .kana = "gulwa"   } // ぐゎ
  , {.key = B_F|B_N|B_S         , .kana = "dwu"     } // どぅ
  // 追加
  //, {.key = B_SHFT            , .kana = " "}
  //, {.key = B_Q               , .kana = ""}
};

  // enter+シフト(連続シフト)
  // {.key = B_SHFT|B_V|B_N    , .kana = SS_TAP(X_ENTER)},

// kana のレイヤー、シフトキーを設定
void set_kana(uint8_t layer) {
  kana_layer = layer;
}

// kana をオン
void kana_on(bool r_sft_pressing, bool use_fn) {
  is_kana = true;
  keycomb = 0UL;
  kana_clear();
  layer_on(kana_layer);

  //bool is_RSHFT_pressed = (get_mods() & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT);
  if (r_sft_pressing){
      unregister_code(KC_RSFT); }
  // Doesn't work and causes unexpected action. (Re-conert confirmed word.)
  tap_code(KC_LNG1); // Mac (On Win also worked. 2022.07 https://docs.microsoft.com/ja-jp/windows-hardware/design/component-guidelines/keyboard-japan-ime)

  // International4
  // USB#07008a is used as Japanese Henkan (Convert) key.
  // tap_code(KC_INT4); // Win (Not worked. 2022.07)
  // tap_code(KC_HENK); // Win (Not worked. 2022.07)

  // register_code(KC_RSFT);
  // tap_code(KC_SPACE);
  // unregister_code(KC_RSFT);

  if (use_fn) {
      tap_code(KC_F23); }

  if (r_sft_pressing){
      register_code(KC_RSFT); }
}

// kana をオフ
void kana_off(bool l_sft_pressing, bool use_fn) {
  is_kana = false;
  keycomb = 0UL;
  kana_clear();
  layer_off(kana_layer);

  //bool is_LSHFT_pressed = (get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT);
  if (l_sft_pressing){
      unregister_code(KC_LSFT); }

  tap_code(KC_LNG2); // Mac (On Win also worked. 2022.07 https://docs.microsoft.com/ja-jp/windows-hardware/design/component-guidelines/keyboard-japan-ime)

  // International5
  // USB#07008b is used as Japanese Muhenkan (No-convert) key.
  // tap_code(KC_INT5); // Win (Not worked. 2022.07)
  // tap_code(KC_MHEN); // Win (Not worked. 2022.07)

  // register_code(KC_LSFT);
  // tap_code(KC_SPACE);
  // unregister_code(KC_LSFT);
  if (use_fn) {
      tap_code(KC_F24); }

  if (l_sft_pressing){
      register_code(KC_LSFT); }
}

// kana のon/off状態を返す
bool kana_state(void) {
  return is_kana;
}

void kana_on_keep_ime(void) {
  is_kana = true;
  keycomb = 0UL;
  kana_clear();
  layer_on(kana_layer);
}

void kana_off_keep_ime(void) {
  is_kana = false;
  keycomb = 0UL;
  kana_clear();
  layer_off(kana_layer);
}

// OSのかな/英数モードをキーボードに合わせる
void makesure_mode(void) {
  if (is_kana) {
    tap_code(KC_LNG1); // Mac
    //tap_code(KC_HENK); // Win
    tap_code(KC_INT4); // Win
  } else {
    tap_code(KC_LNG2); // Mac
    //tap_code(KC_MHEN); // Win
    tap_code(KC_INT5); // Win
  }
}

// バッファをクリアする
void kana_clear(void) {
  for (int i = 0; i < NGBUFFER; i++) {
    ninputs[i] = 0;
  }
  ng_chrcount = 0;
}

// バッファから先頭n文字を削除する
void compress_buffer(int n) {
  if (ng_chrcount == 0) return;
  for (int j = 0; j < NGBUFFER; j++) {
    if (j + n < NGBUFFER) {
      ninputs[j] = ninputs[j + n];
    } else {
      ninputs[j] = 0;
    }
  }
  ng_chrcount -= n;
}


// modifierが押されたらkana レイヤーをオフしてベースレイヤーに戻す
// get_mods()がうまく動かない
static int n_modifier = 0;

bool process_modifier(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LCTL:
    case KC_LSFT:
    case KC_LALT:
    case KC_LGUI:
    case KC_RCTL:
    case KC_RSFT:
    case KC_RALT:
    case KC_RGUI:
      if (record->event.pressed) {
        n_modifier++;
        layer_off(kana_layer);
      } else {
        n_modifier--;
        if (n_modifier == 0) {
          layer_on(kana_layer);
        }
      }
      return true;
      break;
  }
  return false;
}

// kana の入力処理
bool process_kana(uint16_t keycode, keyrecord_t *record) {
  if (!is_kana) return true;

  if (process_modifier(keycode, record))
    return true;

  if (record->event.pressed) {
    switch (keycode) {
      case KN_Q ... KN_SHFT:
        ninputs[ng_chrcount] = keycode; // キー入力をバッファに貯める
        ng_chrcount++;
        keycomb |= ng_key[keycode - KN_Q]; // キーの重ね合わせ
        // バッファが一杯になったら処理を開始
        if (ng_chrcount >= NGBUFFER) {
          kana_type();
        }
        return false;
        break;
    }
  } else { // key release
    switch (keycode) {
      case KN_Q ... KN_SHFT:
        // どれかキーを離したら処理を開始する
        keycomb &= ~ng_key[keycode - KN_Q]; // キーの重ね合わせ
        if (ng_chrcount > 0) {
          kana_type();
        }
        return false;
        break;
    }
  }
  return true;
}

// キー入力を文字に変換して出力する
void kana_type(void) {
  // バッファの最初からnt文字目までを検索キーにする。
  // 一致する組み合わせがなければntを減らして=最後の1文字を除いて再度検索する。
  int nt = ng_chrcount;

  while (nt > 0) {
    if (kana_lookup(nt, true)) return; // 連続シフト有効で探す
    if (kana_lookup(nt, false)) return; // 連続シフト無効で探す
    nt--; // 最後の1キーを除いて、もう一度仮名テーブルを検索する
  }
  compress_buffer(1);
}

const PROGMEM kana_keymap_long ngmapl[] = {
};

// バッファの頭からnt文字の範囲を検索キーにしてテーブル検索し、文字に変換して出力する
// 検索に成功したらtrue、失敗したらfalseを返す
bool kana_lookup(int nt, bool shifted) {
  kana_keymap bngmap; // PROGMEM buffer
  kana_keymap_long bngmapl; // PROGMEM buffer
  // comment out by me 2020.02.13
  //kana_keymap_unicode bngmapu; // PROGMEM buffer

  // keycomb_bufはバッファ内のキーの組み合わせ、keycombはリリースしたキーを含んでいない
  uint32_t keycomb_buf = 0UL;

  // バッファ内のキーを組み合わせる
  for (int i = 0; i < nt; i++) {
    keycomb_buf |= ng_key[ninputs[i] - KN_Q];
  }

  if (shifted) {
    // 連続シフトを有効にする
    if ((keycomb & B_SHFT) == B_SHFT) keycomb_buf |= B_SHFT;

    // 編集モードを連続する
    //if ((keycomb & (B_D | B_F))    == (B_D | B_F))    keycomb_buf |= (B_D | B_F);
    //if ((keycomb & (B_C | B_V))    == (B_C | B_V))    keycomb_buf |= (B_C | B_V);
    //if ((keycomb & (B_J | B_K))    == (B_J | B_K))    keycomb_buf |= (B_J | B_K);
    //if ((keycomb & (B_M | B_COMM)) == (B_M | B_COMM)) keycomb_buf |= (B_M | B_COMM);

    // 濁音、半濁音を連続する
    if ((keycomb & B_F) == B_F) keycomb_buf |= B_F;
    if ((keycomb & B_J) == B_J) keycomb_buf |= B_J;
    if ((keycomb & B_V) == B_V) keycomb_buf |= B_V;
    if ((keycomb & B_M) == B_M) keycomb_buf |= B_M;
  }

  switch (keycomb_buf) {
    // send_stringできないキー、長すぎるマクロはここで定義
    //case B_F|B_G:
    //  kana_off();
    //  compress_buffer(nt);
    //  return true;
    //  break;
    //case B_J|B_K|B_D: // wheel up
    //  for (int i = 0; i < 5; i++)
    //    tap_code(KC_MS_WH_UP);
    //  compress_buffer(nt);
    //  return true;
    //  break;
    //case B_J|B_K|B_F: // wheel down
    //  for (int i = 0; i < 5; i++)
    //    tap_code(KC_MS_WH_DOWN);
    //  compress_buffer(nt);
    //  return true;
    //  break;

    default:

      // キーから仮名に変換して出力する

      // 通常の仮名
      for (int i = 0; i < sizeof ngmap / sizeof bngmap; i++) {
        memcpy_P(&bngmap, &ngmap[i], sizeof(bngmap));
        if (keycomb_buf == bngmap.key) {
          unregister_code(KC_LSFT);
          unregister_code(KC_RSFT);
          send_string(bngmap.kana);
          compress_buffer(nt);
          return true;
        }
      }
      // 仮名ロング
      for (int i = 0; i < sizeof ngmapl / sizeof bngmapl; i++) {
        memcpy_P(&bngmapl, &ngmapl[i], sizeof(bngmapl));
        if (keycomb_buf == bngmapl.key) {
          unregister_code(KC_LSFT);
          unregister_code(KC_RSFT);
          send_string(bngmapl.kana);
          compress_buffer(nt);
          return true;
        }
      }
  }
  return false;
}
