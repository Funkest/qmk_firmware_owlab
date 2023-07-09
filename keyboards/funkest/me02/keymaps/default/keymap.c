#include QMK_KEYBOARD_H
#include <string.h>

// For register_button()
//#include "quantum.h"

// kana
#include "kana.h"
NGKEYS kana_keys;
// kana

//
// Main
//

enum layer_names {
      _ALPHABET = 0
    , _QWT
    , _LOWER
    , _RAISE
    , _ONLY_NUMBERS
    , _ONE_SIDE
    , _ALT_WIN
    , _ALT_WIN_B
    , _FN
    , _RGB
    // kana
    , _KANA
    // kana
};

#define TAB         KC_TAB
// for KC_C_() --> C()     KC_S_() --> S()
#define KC_C_       C
#define KC_S_       S
#define KC_LOWER    LOWER
#define KC_RAISE    RAISE
// #define KC_RESET    RESET // Doesn't work on stm32f072 (Done interrupting, but never returns...)
#define KC_____     KC_TRNS
#define KC_XXXX     KC_NO

#define KC_RGB_MODE_BREATHE     RGB_MODE_BREATHE
#define KC_RGB_TOG              RGB_TOG
#define KC_RGB_MOD              RGB_MOD

#define KC_BR_PR    KC_PARENTHESIS
#define KC_BR_SQ    KC_SQ_BRACKETS
#define KC_EPR_RST  QK_CLEAR_EEPROM

enum custom_keycodes {
      //BASE = SAFE_RANGE
      // kana
      KC_QWT = KN_SAFE_RANGE
    , KC_KANA_ON
    , KC_KANA_OFF
      // kana
    , KN_LSFT
    , KN_RSFT
    , KC_ALPH
    , KC_L_NUM
    , KC_ASIDE
    , KC_LOFF
    , KC_ALLUP
    , KC_LOWER
    , KC_RAISE
    , KC_RGB
    , N_LOWER
    , N_RAISE
    , N_OFF_K
    , N_CTRL
    , KC_CTL_QOT
    , KC_CTL_ESC
    , KC_ALT_EX
    , KC_WIN_EX
    , KC_WIN_EX_B
    , KC_FN_EX
    , KC_xRSFT
    , KC_xLSFT
    , KC_PARENTHESIS
    , KC_SQ_BRACKETS
    , KC_MN_C
    , KC_TGL_IME_FN
    , KC_LAST
    , RGB1
    , RGB2
    , RGB3
    , RGBRST
    , RGBOFF
};

//
// Combo settings (with COMBO_COUNT and COMBO_TERM in ../../config.h)
//

enum combos {
      ENTER_1
    , ESC_1
    , KANA_ON_1
    , KANA_OFF_1
};
const uint16_t PROGMEM combo_enter_1[] = {KC_T, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc_1[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo_kana_on_1[] = {KC_E, KC_C, COMBO_END};
const uint16_t PROGMEM combo_kana_off_1[] = {KC_E, KC_M, COMBO_END};
combo_t key_combos[] = {
      [ENTER_1] = COMBO(combo_enter_1, KC_ENTER)
    , [ESC_1] = COMBO(combo_esc_1, KC_ESC)
    , [KANA_ON_1] = COMBO(combo_kana_on_1, KC_KANA_ON)
    , [KANA_OFF_1] = COMBO(combo_kana_off_1, KC_KANA_OFF)
};

//
// Main
//

#define KC_TGL_OVR_FN QK_KEY_OVERRIDE_TOGGLE
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_key_overrides.md

#include "keymap_jp.h"
const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, JP_AT);          // +2 to @
const key_override_t circ_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, JP_CIRC);      // +6 to ^
const key_override_t ampr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, JP_AMPR);      // +7 to &
const key_override_t astr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, JP_ASTR);      // +8 to *
const key_override_t lprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, JP_LPRN);      // +9 to (
const key_override_t rprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, JP_RPRN);      // +0 to )
const key_override_t unds_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, JP_UNDS);  // +- to _
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, JP_PLUS);    // += to +
const key_override_t lcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, JP_LCBR);   // +[ to {
const key_override_t rcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, JP_RCBR);   // +] to }
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE);   // +\ to |
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);   // +; to :
const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO);   // +' to " (= +2 not work)
const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, JP_TILD);    // +' to ~
const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0, KC_EQL, JP_EQL, ~0, (uint8_t) MOD_MASK_SHIFT);       // = to =
const key_override_t lbrc_key_override          = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, ~0, (uint8_t) MOD_MASK_SHIFT);    // [ to [
const key_override_t rbrc_key_override          = ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, ~0, (uint8_t) MOD_MASK_SHIFT);    // ] to ]
const key_override_t bsls_key_override          = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, ~0, (uint8_t) MOD_MASK_SHIFT);    // backslash to backslash
const key_override_t quot_key_override          = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_QUOT, ~0, (uint8_t) MOD_MASK_SHIFT);    // ' to ' (= +7 not work)
const key_override_t grv_key_override           = ko_make_with_layers_and_negmods(0, KC_GRV , JP_GRV , ~0, (uint8_t) MOD_MASK_SHIFT);    // ` to `
// Followings may cause some unexpected result. 2022.1109
const key_override_t unds_direct_key_override   = ko_make_with_layers_and_negmods(0, KC_UNDS, JP_UNDS, ~0, (uint8_t) MOD_MASK_SHIFT);    // _ to _
const key_override_t circ_direct_key_override   = ko_make_with_layers_and_negmods(0, KC_CIRC, JP_CIRC, ~0, (uint8_t) MOD_MASK_SHIFT);    // ^ to ^
const key_override_t lprn_direct_key_override   = ko_make_with_layers_and_negmods(0, KC_LPRN, JP_LPRN, ~0, (uint8_t) MOD_MASK_SHIFT);    // ( to (
const key_override_t rprn_direct_key_override   = ko_make_with_layers_and_negmods(0, KC_RPRN, JP_RPRN, ~0, (uint8_t) MOD_MASK_SHIFT);    // ) to )
const key_override_t lcbr_direct_key_override   = ko_make_with_layers_and_negmods(0, KC_LCBR, JP_LCBR, ~0, (uint8_t) MOD_MASK_SHIFT);    // { to {
const key_override_t rcbr_direct_key_override   = ko_make_with_layers_and_negmods(0, KC_RCBR, JP_RCBR, ~0, (uint8_t) MOD_MASK_SHIFT);    // } to }
const key_override_t ppls_direct_key_override   = ko_make_with_layers_and_negmods(0, KC_PPLS, JP_PLUS, ~0, (uint8_t) MOD_MASK_SHIFT);    // + to +
const key_override_t dquo_direct_key_override   = ko_make_with_layers_and_negmods(0, KC_DQUO, JP_DQUO, ~0, (uint8_t) MOD_MASK_SHIFT);    // " to "

const key_override_t **key_overrides = (const key_override_t *[]){
      &at_key_override
    , &circ_key_override
    , &ampr_key_override
    , &astr_key_override
    , &lprn_key_override
    , &rprn_key_override
    , &unds_key_override
    , &plus_key_override
    , &lcbr_key_override
    , &rcbr_key_override
    , &pipe_key_override
    , &coln_key_override
    , &dquo_key_override
    , &tild_key_override
    , &eql_key_override
    , &lbrc_key_override
    , &rbrc_key_override
    , &bsls_key_override
    , &quot_key_override
    , &grv_key_override
    , &unds_direct_key_override
    , &circ_direct_key_override
    , &lprn_direct_key_override
    , &rprn_direct_key_override
    , &lcbr_direct_key_override
    , &rcbr_direct_key_override
    , &ppls_direct_key_override
    , &dquo_direct_key_override
    , NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALPHABET] = LAYOUT_kc(
      BSPC      , D         , R         , N         , A         , Q         , Y         , L_NUM         , TGL_OVR_FN, Q         , Y         , S         , H         , J         , K         , L
    , TAB       , U         , O         , I         , E         , G         , P         , DOT           , TGL_IME_FN, G         , P         , E         , T         , W         , SCLN      , QUOT
    , LWIN      , MN_C      , X         , V         , F         , L         , Z         , SPACE         , UNDS      , B         , C         , M         , COMM      , DOT       , SLSH      , RGB_TOG
    , TAB       , LOFF      , LALT      , xLSFT     , CTL_ESC   , xLSFT     , LOWER     , LAST          , LAST      , RAISE     , xRSFT     , CTL_QOT   , xRSFT     , RALT      , EPR_RST   , ENTER
)
, [_QWT] = LAYOUT_kc(
      BSPC      , Q         , W         , E         , R         , T         , Y         , XXXX          , R         , T         , Y         , U         , I         , O         , P         , XXXX
    , TAB       , A         , S         , D         , F         , G         , H         , DOT           , F         , G         , H         , J         , K         , L         , SCLN      , TAB
    , SPACE     , MN_C      , Z         , X         , C         , V         , B         , MINUS         , V         , B         , N         , M         , COMM      , DOT       , SLSH      , RGB_TOG
    , TAB       , LOFF      , LALT      , xLSFT     , CTL_ESC   , xLSFT     , LOWER     , SLSH          , ENTER     , RAISE     , xRSFT     , CTL_QOT   , xRSFT     , RALT      , XXXX      , ENTER
)
, [_KANA] = LAYOUT_all(
      _______   , KN_Q      , KN_W      , KN_E      , KN_R      , KN_T      , _______   , _______       , _______   , _______   , KN_Y      , KN_U      , KN_I      , KN_O      , KN_P      , _______
    , _______   , KN_A      , KN_S      , KN_D      , KN_F      , KN_G      , _______   , _______       , _______   , _______   , KN_H      , KN_J      , KN_K      , KN_L      , KN_SCLN   , KN_Z
    , _______   , _______   , KN_Z      , KN_X      , KN_C      , KN_V      , KN_BL     , _______       , _______   , KN_BR     , KN_N      , KN_M      , KN_COMM   , KN_DOT    , KC_SLSH   , _______
    , _______   , _______   , _______   , _______   , N_CTRL    , KN_LSFT   , N_LOWER   , N_LOWER       , N_RAISE   , N_RAISE   , KN_RSFT   , N_CTRL    , _______   , _______   , _______   , _______
 )
// MS_BTN3 : mid, MS_BTN4 : browser_back, MS_BTN5 : browser_forward (KC_WBAK, KC_WFWD not work on win)
//  https://www.autohotkey.com/docs/KeyList.htm#mouse-advanced
// !@#%&* should be added to one-hand position.
, [_LOWER] = LAYOUT_kc(
      ____      , 1         , 2         , 3         , 4         , 5         , MINUS     , MS_BTN3       , ____      , DOT       , 6         , 7         , 8         , 9         , 0         , ____
    , ____      , DEL       , CIRC      , LBRC      , RBRC      , SLSH      , DOT       , WBAK          , ____      , EQL       , LEFT      , DOWN      , UP        , RGHT      , BSLS      , ____
    , ____      , LEFT      , DOWN      , UP        , RGHT      , FN_EX     , MINUS     , MS_BTN5       , DEL       , BSPC      , HOME      , END       , PGUP      , PGDN      , GRV       , L_NUM
    , ENTER     , XXXX      , ____      , ____      , ____      , ____      , ____      , ____          , ____      , XXXX      , ____      , ____      , ____      , ____      , ____      , ____
)
//  ____ causes Kana-off when BSPC on _LOWER with mis-touching this key (send RAISE tapping) .
, [_RAISE] = LAYOUT_kc(
      ____      , 1         , 2         , 3         , 4         , 5         , MINUS     , ____          , ____      , DOT       , 6         , 7         , 8         , 9         , 0         , PSCR
    , ____      , ____      , ____      , LBRC      , RBRC      , SLSH      , DOT       , ____          , ____      , PPLS      , EQL       , LCBR      , RCBR      , DLR       , BSLS      , DQUO
    , ____      , ____      , ____      , BR_PR     , BR_SQ     , MINUS     , MINUS     , ____          , ____      , WIN_EX    , FN_EX     , LPRN      , RPRN      , BSPC      , GRV       , ____
    , ____      , QWT       , ____      , ____      , ____      , ____      , ____      , ____          , ____      , ____      , ____      , ____      , ____      , ____      , ____      , ____
)

, [_ONLY_NUMBERS] = LAYOUT_kc(
      ____      , 1         , 2         , 3         , 4         , 5         , MINUS     , LOFF          , ____      , DOT       , 6         , 7         , 8         , 9         , 0         , ____
    , ____      , 6         , 7         , 8         , 9         , 0         , DOT       , ____          , ____      , EQL       , LEFT      , DOWN      , UP        , RGHT      , BSLS      , ____
    , ____      , MINUS     , DOT       , COMM      , DEL       , BSPC      , FN_EX     , MINUS         , ____      , ____      , ____      , ____      , ____      , ____      , ____      , ____
    , ____      , ____      , ____      , ____      , ____      , ____      , ____      , ____          , ____      , ____      , ____      , ____      , ____      , ____      , ____      , ____
)

, [_ONE_SIDE] = LAYOUT_kc(
      ____      , 1         , 2         , 3         , 4         , 5         , MINUS     , ____          , ____      , DOT       , 6         , 7         , 8         , 9         , 0         , ____
    , ____      , DEL       , RGHT      , UP        , DOWN      , LEFT      , DOT       , LOFF          , TAB       , EQL       , LEFT      , DOWN      , UP        , RGHT      , BSLS      , ____
    , ____      , BSPC      , PGDN      , PGUP      , END       , HOME      , SPACE     , ____          , SPACE     , BSPC      , HOME      , END       , PGUP      , PGDN      , GRV       , ____
    , ____      , ____      , ____      , ____      , ____      , ____      , ____      , ____          , ____      , ____      , ____      , ____      , ____      , ____      , ____      , ____
)

, [_ALT_WIN] = LAYOUT_kc(
      ____      , Q         , W         , E         , R         , T         , Y         , XXXX          , R         , T         , Y         , U         , I         , O         , P         , XXXX
    , ____      , A         , S         , D         , F         , G         , H         , XXXX          , F         , G         , H         , J         , K         , L         , SCLN      , XXXX
    , ____      , ____      , Z         , X         , C         , V         , B         , N             , V         , B         , N         , M         , COMM      , DOT       , SLSH      , XXXX
    , LOFF      , TAB       , XXXX      , ____      , ____      , ____      , LOWER     , XXXX          , XXXX      , RAISE     , ____      , ____      , XXXX      , XXXX      , XXXX      , ENTER
)

, [_ALT_WIN_B] = LAYOUT_kc(
      ____      , D         , R         , N         , A         , Q         , ____      , ____          , ____      , ____      , Y         , S         , H         , J         , K         , L
    , ____      , U         , O         , I         , E         , G         , ____      , ____          , ____      , ____      , P         , E         , T         , W         , SCLN      , ____
    , ____      , ____      , X         , V         , F         , L         , Z         , ____          , ____      , B         , C         , M         , COMM      , DOT       , SLSH      , ____
    , LOFF      , TAB       , ____      , ____      , ____      , ____      , LOWER     , ____          , ____      , RAISE     , ____      , ____      , ____      , ____      , ____      , ENTER
)

, [_FN] = LAYOUT_kc(
      ____      , F1        , F2        , F3        , F4        , F5        , F6        , ____          , ____      , F1        , F2        , F3        , F4        , F5        , F6        , ____
    , ____      , F7        , F8        , F9        , F10       , F11       , F12       , ____          , ____      , F7        , F8        , F9        , F10       , F11       , F12       , ____
    , ____      , XXXX      , XXXX      , LALT      , XXXX      , XXXX      , XXXX      , ____          , ____      , ALLUP     , XXXX      , XXXX      , RALT      , XXXX      , XXXX      , ____
    , ____      , ____      , ____      , ____      , ____      , ____      , ____      , ____          , ____      , ____      , ____      , ____      , ASIDE     , ____      , ____      , KANA_ON
)

, [_RGB] = LAYOUT_all(
      RGBRST    , RGB_HUI   , RGB_MOD   , _______   , _______   , _______   , _______   , _______       , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______
    , RGB1      , RGB_VAI   , RGBOFF    , KC_F8     , KC_F9     , KC_LOFF   , _______   , _______       , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______
    , RGB2      , RGB_VAD   , KC_F4     , KC_F5     , KC_F6     , KC_F12    , _______   , _______       , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______
    , RGB3      , KC_F10    , KC_F1     , KC_F2     , KC_F3     , KC_F11    , _______   , _______       , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______
)

// need BACKSLASH (removed for comment)
// , [_EUCALYN] = LAYOUT_kc(
//       ____, ____, Q   , W   , COMM, DOT  , SCLN, ____            , ____ , M   , R    , D    , Y   , P   , XXXX, ____
//     , ____, XXXX, A   , O   , E   , I    , U   , LOFF            , ____ , G   , T    , K    , S   , N   , XXXX, ____
//     , ____, ____, Z   , X   , C   , V    , F   , ____            , ____ , B   , H    , J    , L   , SLSH, XXXX, ____
//     , ____, ____, ____, ____, ____, ____ , ____, ____            , ____ , ____, ____ , ____ , ____, ____, ____, ____
// )
};

void matrix_init_user(void) {
    // default is ON.
    key_override_off();

    // kana
    set_kana(_KANA);
    #ifdef kana_EDIT_MAC
    set_unicode_input_mode(UC_OSX);
    #endif
    #ifdef kana_EDIT_WIN
    set_unicode_input_mode(UC_WINC);
    #endif
    // kana
    set_single_persistent_default_layer(_ALPHABET);
}

static bool lower_interrupted   = false;
static bool raise_interrupted   = false;
static bool ctrl_l_interrupted  = false;
static bool ctrl_r_interrupted  = false;
static bool sft_l_x_interrupted = true;
static bool sft_r_x_interrupted = true;
static bool kana_i_pressed = false;
static bool kana_o_pressed = false;
static bool kana_k_pressed = false;
static bool kana_l_pressed = false;
static bool kana_j_pressed = false;
static bool kana_m_pressed = false;
static bool kana_n_pressed = false;
static bool suppress_kana = false;
static bool delayed_l_sfted_keypressed = true;
static bool delayed_r_sfted_keypressed = true;
static bool just_ime_toggled    = false;
static bool use_fn_for_ime_toggle   = false;
// kana
static bool keep_kana       = false;
static bool is_just_kana_on = false;
// kana

uint16_t last_mod_pressed_t     = 0;
uint16_t last_pressed_shf_x_l   = 0;
uint16_t last_pressed_shf_x_r   = 0;
uint16_t last_pressed_ctrl_l    = 0;
uint16_t last_pressed_ctrl_r    = 0;
uint16_t last_pressed_raise     = 0;
uint16_t last_pressed_lower     = 0;
uint16_t last_pressed_key       = 0;
uint16_t last_pressed_kana_i    = 0;
uint16_t last_pressed_kana_o    = 0;
uint16_t last_pressed_kana_k    = 0;
uint16_t last_pressed_kana_l    = 0;
uint16_t last_pressed_kana_j    = 0;
uint16_t last_pressed_kana_m    = 0;
uint16_t last_pressed_kana_n    = 0;

const uint16_t TAP_TIME = 200;

bool RGBAnimation = false; //Flag for LED Layer color Refresh.

void clear_all_flags(void) {
    raise_interrupted       = true;
    lower_interrupted       = true;
    ctrl_l_interrupted      = true;
    ctrl_r_interrupted      = true;
    sft_l_x_interrupted     = true;
    sft_r_x_interrupted     = true;
    delayed_l_sfted_keypressed= true;
    delayed_r_sfted_keypressed= true;
    kana_i_pressed = false;
    kana_o_pressed = false;
    kana_k_pressed = false;
    kana_l_pressed = false;
    kana_j_pressed = false;
    suppress_kana = false;
    kana_m_pressed = false;
    kana_n_pressed = false;
}
void up_all_modKeys(void) {
    unregister_code(KC_LSFT);
    unregister_code(KC_RSFT);
    unregister_code(KC_LCTL);
    unregister_code(KC_RCTL);
    unregister_code(KC_LALT);
    unregister_code(KC_RALT);
    unregister_code(KC_LWIN);
    unregister_code(KC_RWIN);
    set_single_persistent_default_layer(_ALPHABET);
}
void layer_switch_with_tapping(uint16_t layercode, uint16_t tapkey, bool *is_interrupted, uint16_t *timestamp, keyrecord_t *record, uint16_t keycode) {

    if (record->event.pressed){
        (*timestamp) = timer_read();
        (*is_interrupted) = false;
        // for IME toggle with AHK lsft space / lsfr lctrl space (To toggle not 'on up' but 'on push'.)
        // if (layercode == _RAISE && (! sft_l_x_interrupted || ! sft_r_x_interrupted || (! sft_l_x_interrupted && ! ctrl_l_interrupted))) {
        // for IME toggle with AHK lsft space / rsfr space (To toggle not 'on up' but 'on push'.)

        //if (layercode == _RAISE && is_LSHFT_pressed){
        if (layercode == _RAISE && ! sft_l_x_interrupted){
            kana_off(! sft_l_x_interrupted, use_fn_for_ime_toggle);
            just_ime_toggled = true; }
            // tap_code(tapkey); // With AHK LSHIFT + SPACE.
        //if (layercode == _LOWER && is_RSHFT_pressed){
        if (layercode == _LOWER && ! sft_r_x_interrupted){
            kana_on(! sft_r_x_interrupted, use_fn_for_ime_toggle);
            is_just_kana_on = true;
            just_ime_toggled = true; }
        // kana
        if (keycode == N_LOWER || keycode == N_RAISE){
            kana_off_keep_ime();
            keep_kana = true; }
        // kana
        layer_on(layercode);
    }
    else {
        // kana
        if (keep_kana && (keycode == N_LOWER || keycode == N_RAISE)){
            kana_on_keep_ime(); }
        keep_kana = false;
        // kana
        layer_off(layercode);
        if (! (*is_interrupted)){
            if (! just_ime_toggled && timer_elapsed(*timestamp) < TAP_TIME) {
                // kana
                if (is_just_kana_on){
                    is_just_kana_on = false;
                    return; }
                // kana
                if (! sft_l_x_interrupted || ! sft_r_x_interrupted){
                    return;}
                tap_code(tapkey); }
            else {
                just_ime_toggled = false;
                is_just_kana_on = false; } } }
}
void modifier_key_with_tapping(uint16_t modkey, uint16_t tapkey, bool *is_interrupted, uint16_t *timestamp, keyrecord_t *record) {
    if (record->event.pressed) {
        (*timestamp) = timer_read();
        (*is_interrupted) = false;
        register_code(modkey); }
    else {
        unregister_code(modkey);
        if (! (*is_interrupted)) {
            bool shiftIsActive = ! sft_l_x_interrupted || ! sft_r_x_interrupted;
            clear_all_flags();
            if (timer_elapsed(*timestamp) < TAP_TIME) {
                // not work. -> process_key_override(tapkey, record);
                if (key_override_is_enabled()){
                    if (tapkey == KC_QUOT){
                        if (shiftIsActive){
                            tap_code(KC_2); }
                        else {
                            tap_code16(S(KC_7)); } }
                    else {
                        tap_code(tapkey); } }
                else {
                    tap_code(tapkey); }
            } } }
}

void modifier_key_with_tapping_ng(uint16_t modkey, uint16_t tapkey, bool *is_interrupted, uint16_t *timestamp, keyrecord_t *record) {

    if (record->event.pressed) {
        (*timestamp) = timer_read();
        (*is_interrupted) = false;
        register_code(modkey);

        if (kana_state()){
            keep_kana = true;
            kana_off_keep_ime(); } }
    else {
        if (keep_kana){
            keep_kana = false;
            unregister_code(modkey);
            kana_on_keep_ime();
            register_code(modkey); }

        unregister_code(modkey);
        if (! (*is_interrupted)) {
            clear_all_flags();
            if (timer_elapsed(*timestamp) < TAP_TIME) {
                tap_code(tapkey); } } }
}

// この関数で mod keys に関して bug 発生するかも

void send_key_set(uint16_t key, uint16_t l_key, uint16_t r_key, keyrecord_t *record) {
    if (! record->event.pressed){
        tap_code16(l_key);
        tap_code16(r_key);
        clear_mods();
        clear_all_flags();
        tap_code(KC_LEFT); }
}

//int combined_key_to_led[] =
//{
//   0,1,2,3,4,5,6,7
//  ,1514,13,12,11,10,9,8
//  ,16,17,18,19,20,21,22,23
//  ,31,30,29,28,27,26,25,24
//};

#ifdef RGBLIGHT_ENABLE

struct keybuf {
  char col, row;
  char frame;
};
struct keybuf keybufs[256];
unsigned char keybuf_begin, keybuf_end;

#ifndef MAX
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#endif
#ifndef MIN
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#endif

int col, row;
unsigned char rgb[7][5][3];
void led_ripple_effect(char r, char g, char b) {
    static int scan_count = -10;
    static int keys[] = { 6, 6, 6, 7, 7 };
    static int keys_sum[] = { 0, 6, 12, 18, 25 };

    if (scan_count == -1) {
      rgblight_enable_noeeprom();
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    } else if (scan_count >= 0 && scan_count < 5) {
      for (unsigned char c=keybuf_begin; c!=keybuf_end; c++) {
        int i = c;
        // FIXME:

        int y = scan_count;
        int dist_y = abs(y - keybufs[i].row);
        for (int x=0; x<keys[y]; x++) {
          int dist = abs(x - keybufs[i].col) + dist_y;
          if (dist <= keybufs[i].frame) {
            int elevation = MAX(0, (8 + dist - keybufs[i].frame)) << 2;
            if (elevation) {
              if ((rgb[x][y][0] != 255) && r) { rgb[x][y][0] = MIN(255, elevation + rgb[x][y][0]); }
              if ((rgb[x][y][1] != 255) && g) { rgb[x][y][1] = MIN(255, elevation + rgb[x][y][1]); }
              if ((rgb[x][y][2] != 255) && b) { rgb[x][y][2] = MIN(255, elevation + rgb[x][y][2]); }
            }
          }
        }
      }
    } else if (scan_count == 5) {
      for (unsigned char c=keybuf_begin; c!=keybuf_end; c++) {
        int i = c;
        if (keybufs[i].frame < 18) {
          keybufs[i].frame ++;
        } else {
          keybuf_begin ++;
        }
      }
    } else if (scan_count >= 6 && scan_count <= 10) {
      int y = scan_count - 6;
      for (int x=0; x<keys[y]; x++) {
        int at = keys_sum[y] + ((y & 1) ? x : (keys[y] - x - 1));
        led[at].r = rgb[x][y][0];
        led[at].g = rgb[x][y][1];
        led[at].b = rgb[x][y][2];
      }
      rgblight_set();
    } else if (scan_count == 11) {
      memset(rgb, 0, sizeof(rgb));
    }
    scan_count++;
    if (scan_count >= 12) { scan_count = 0; }
}
#endif

// main

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    #ifdef RGBLIGHT_ENABLE
        //rgblight_enable_noeeprom();
        //
        //rgblight_set();
        //rgblight_set_effect_range(0, 2);
        //rgblight_mode((uint8_t)RGB_MODE_PLAIN);
        //rgblight_mode((uint8_t)RGB_MODE_PLAIN);
        //
    //        col = record->event.key.col;
    //        row = record->event.key.row;
    //        if (record->event.pressed) {
    //            int end = keybuf_end;
    //            keybufs[end].col = col;
    //            keybufs[end].row = row % 5;
    //            keybufs[end].frame = 0;
    //            keybuf_end ++; }
    //        led_ripple_effect(0, 255, 255);

            //switch (keycode) {
            //    case KC_R:
            //        //setrgb(0, 255, 0, (LED_TYPE *)&led[0]);
            //        //rgblight_set();
            //        rgblight_setrgb_at(0, 255, 0, 0);
            //        rgblight_set_effect_range(0, 1);
            //        rgblight_mode((uint8_t)RGB_MODE_RAINBOW);
            //        break;
            //    case KC_T:
            //        //rgblight_set();
            //        rgblight_setrgb_at(255, 255, 0, 1);
            //        rgblight_set_effect_range(1, 1);
            //        rgblight_mode((uint8_t)RGB_MODE_PLAIN);
            //        break;
            //    default:
            //        break; }
    #endif

    // shift in kana layer

    if (record->event.pressed){
        if (keycode != KC_LAST && keycode < KN_SAFE_RANGE){
            last_pressed_key = keycode; }
    // set_timelog();
    //
        switch (keycode){
            // process KC_MS_BTN1~8 by myself
            // See process_action() in quantum/action.c for details.
            //case KC_MS_BTN1 ... KC_MS_BTN8: {
            //    extern void register_mouse(bool, enum mouse_buttons);
            //    register_mouse(record->event.pressed, MOUSE_BTN_MASK(keycode - KC_MS_BTN1));
            //    return false;
            //}
            case KC_xLSFT:
                sft_l_x_interrupted = false;
                last_pressed_shf_x_l = timer_read();
                register_code(KC_LSFT);
                break;
            case KN_LSFT:
                sft_l_x_interrupted = false;
                register_code(KC_LSFT);
                keycode = KN_SHFT;
                break;
            case KC_xRSFT:
                sft_r_x_interrupted = false;
                last_pressed_shf_x_r = timer_read();
                register_code(KC_RSFT);
                break;
            case KN_RSFT:
                sft_r_x_interrupted = false;
                register_code(KC_RSFT);
                keycode = KN_SHFT;
                break;
            case N_RAISE:
                if (! sft_l_x_interrupted){
                    kana_off(! sft_l_x_interrupted, use_fn_for_ime_toggle);
                    return false; };
                break;
            // Safety net
            default:
               sft_l_x_interrupted = (get_mods() & MOD_BIT(KC_LSFT)) != MOD_BIT(KC_LSFT);
               sft_r_x_interrupted = (get_mods() & MOD_BIT(KC_RSFT)) != MOD_BIT(KC_RSFT);
               break; }
    } else {
        switch (keycode){
            case KC_xLSFT:
                unregister_code(KC_LSFT);
                delayed_l_sfted_keypressed = false;
                sft_l_x_interrupted = true;
                break;
            case KN_LSFT:
                unregister_code(KC_LSFT);
                sft_l_x_interrupted = true;
                keycode = KN_SHFT;
                break;
            case KC_xRSFT:
                unregister_code(KC_RSFT);
                delayed_r_sfted_keypressed = false;
                sft_r_x_interrupted = true;
                break;
            case KN_RSFT:
                unregister_code(KC_RSFT);
                sft_r_x_interrupted = true;
                keycode = KN_SHFT;
                break;
            // Safety net
            default:
               sft_l_x_interrupted = (get_mods() & MOD_BIT(KC_LSFT)) != MOD_BIT(KC_LSFT);
               sft_r_x_interrupted = (get_mods() & MOD_BIT(KC_RSFT)) != MOD_BIT(KC_RSFT);
               break; } }

    switch (keycode) {
        case KC_QWT:
            if (record->event.pressed){
                layer_on(_QWT); }
            return false;
            break;
        case KC_LOWER:
            layer_switch_with_tapping(_LOWER, KC_SPC, &lower_interrupted, &last_pressed_lower, record, keycode);
            return false;
            break;
        case KC_RAISE:
            layer_switch_with_tapping(_RAISE, KC_SPC, &raise_interrupted, &last_pressed_raise, record, keycode);
            return false;
            break;
        case N_LOWER:
            layer_switch_with_tapping(_LOWER, KC_SPC, &lower_interrupted, &last_pressed_lower, record, keycode);
            return false;
            break;
        case N_RAISE:
            layer_switch_with_tapping(_RAISE, KC_SPC, &raise_interrupted, &last_pressed_raise, record, keycode);
            return false;
            break;
        // kana
        case N_CTRL:
//            if (record->event.pressed) {
//                register_code(KC_LCTL);
//                if (kana_state()){
//                    keep_kana = true;
//                    kana_off_keep_ime(); }
//                layer_on(_QWT); }
//            else {
//                layer_off(_LOWER);
//                if (keep_kana){
//                    keep_kana = false;
//                    kana_on(); }
//                unregister_code(KC_LCTL); }
            modifier_key_with_tapping_ng(KC_LCTL, KC_ESC, &ctrl_l_interrupted, &last_pressed_ctrl_l, record);
            return false;
        // kana
        case KC_CTL_QOT:
            modifier_key_with_tapping(KC_RCTL, KC_QUOT, &ctrl_r_interrupted, &last_pressed_ctrl_r, record);
            return false;
        case KC_CTL_ESC:
            modifier_key_with_tapping(KC_LCTL, KC_ESC, &ctrl_l_interrupted, &last_pressed_ctrl_l, record);
            return false;
        case KC_PARENTHESIS:
            send_key_set(keycode, RSFT(KC_9), LSFT(KC_0), record);
            return false;
        case KC_SQ_BRACKETS:
            send_key_set(keycode, KC_LBRC, KC_RBRC, record);
            return false;
        case KC_MN_C:
            if (record->event.pressed){
                if (! ctrl_l_interrupted || get_mods() & MOD_MASK_CTRL){
                    tap_code16(KC_C); }
                else {
                    tap_code(KC_MINUS);
                    last_pressed_key = KC_MINUS; } }
            return false;
        case KC_ALT_EX:
            if (record->event.pressed){
                register_code(KC_LALT);
                layer_on(_ALT_WIN); }
            else {
                layer_off(_ALT_WIN);
                unregister_code(KC_LALT); }
            return false;
        case KC_WIN_EX:
            if (! layer_state_is(_QWT)) {
                if (record->event.pressed){
                    register_code(KC_LWIN);
                    layer_on(_ALT_WIN_B); }
                else {
                    layer_off(_ALT_WIN_B);
                    unregister_code(KC_LWIN); } }
            else {
                if (record->event.pressed){
                    register_code(KC_LWIN);
                    layer_on(_ALT_WIN); }
                else {
                    layer_off(_ALT_WIN);
                    unregister_code(KC_LWIN); } }
            return false;
            break;
        case KC_ALPH:
            if (record->event.pressed) {
                layer_on(_ALPHABET); }
            break;
        case KC_L_NUM:
            if (record->event.pressed) {
                layer_on(_ONLY_NUMBERS); }
            break;
        case KC_ASIDE:
            if (record->event.pressed) {
                layer_on(_ONE_SIDE); }
            break;
        case KC_RGB:
            if (record->event.pressed) {
                layer_on(_RGB); }
            break;
        case KC_LAST:
            if (record->event.pressed) {
                tap_code(last_pressed_key); }
            return false;
            break;
        case KC_FN_EX:
            if (record->event.pressed){
                layer_on(_FN); }
            else {
                layer_off(_FN); }
            return false;
            break;
        case KC_ALLUP:
            clear_all_flags();
            up_all_modKeys();
            break;
        case KC_KANA_ON:
            if (record->event.pressed) {
                kana_on(! sft_r_x_interrupted, use_fn_for_ime_toggle);
            }
            break;
        case KC_KANA_OFF:
            if (record->event.pressed) {
                kana_off(! sft_l_x_interrupted, use_fn_for_ime_toggle);
            }
            break;
        // kana
        case KC_LOFF:
            if (record->event.pressed) {
                // kana
                kana_off(! sft_l_x_interrupted, use_fn_for_ime_toggle);
                // kana
                layer_off(_QWT);
                layer_off(_RGB);
                layer_off(_FN);
                layer_off(_ALT_WIN);
                layer_off(_ALT_WIN_B);
                layer_off(_ONE_SIDE);
                layer_off(_ONLY_NUMBERS);
                layer_off(_RAISE);
                layer_off(_LOWER);
                set_single_persistent_default_layer(_ALPHABET); }
            return false;
        case KC_TGL_IME_FN:
            if (record->event.pressed) {
                if (use_fn_for_ime_toggle) {
                    use_fn_for_ime_toggle = false; }
                else {
                    use_fn_for_ime_toggle = true; } }
            return false;
        case RGBRST:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    eeconfig_update_rgblight_default();
                    rgblight_enable();
                    RGBAnimation = false; }
            #endif
            break;
        case RGBOFF:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    // doesn't work...
                    rgblight_disable(); }
            #endif
            break;
        case RGB1:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    RGBAnimation = true;
                    rgblight_mode(RGB_MODE_RAINBOW_MOOD); }
            #endif
            break;
        case RGB2:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    RGBAnimation = true;
                    rgblight_mode(RGB_MODE_RAINBOW_SWIRL + 1); } // additional number
            #endif
            break;
        case RGB3:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    RGBAnimation = true;
                    rgblight_mode(RGB_MODE_KNIGHT); }
            #endif
            break;
        // kana
        case N_OFF_K:
            if (record->event.pressed) {
                //kana_off_keep_ime(); }
                kana_off(! sft_l_x_interrupted, use_fn_for_ime_toggle);
            }
            return false;
        default:
            // kana
            if (keycode < KN_SAFE_RANGE) {
                if (record->event.pressed) {
                    switch (keycode) {
                        case KN_I: kana_i_pressed = true; last_pressed_kana_i = timer_read(); break;
                        case KN_O: kana_o_pressed = true; last_pressed_kana_o = timer_read(); break;
                        case KN_K: kana_k_pressed = true; last_pressed_kana_k = timer_read(); break;
                        case KN_L: kana_l_pressed = true; last_pressed_kana_l = timer_read(); break;
                        case KN_J: kana_j_pressed = true; last_pressed_kana_j = timer_read(); break;
                        case KN_M: kana_m_pressed = true; last_pressed_kana_m = timer_read(); break;
                        case KN_N: kana_n_pressed = true; last_pressed_kana_n = timer_read(); break;
                        default: break;
                    }
                    // KN_J + KN_M: kana off
                    if (kana_j_pressed && kana_m_pressed && abs(timer_elapsed(last_pressed_kana_j) - timer_elapsed(last_pressed_kana_m)) < COMBO_TERM) {
                        kana_off(! sft_l_x_interrupted, use_fn_for_ime_toggle);
                        suppress_kana = true;
                    }
                    // KN_J + KN_N: Do nothing (kana on)
                    else if (kana_j_pressed && kana_n_pressed && abs(timer_elapsed(last_pressed_kana_j) - timer_elapsed(last_pressed_kana_n)) < COMBO_TERM) {
                        suppress_kana = true;
                    }
                    // KN_I + KN_O: KC_ESC
                    else if (kana_i_pressed && kana_o_pressed && abs(timer_elapsed(last_pressed_kana_i) - timer_elapsed(last_pressed_kana_o)) < COMBO_TERM) {
                        suppress_kana = true;
                        tap_code16(KC_ESC);
                    }
                    // KN_K + KN_L: KC_ENTER
                    else if (kana_k_pressed && kana_l_pressed && abs(timer_elapsed(last_pressed_kana_k) - timer_elapsed(last_pressed_kana_l)) < COMBO_TERM) {
                        suppress_kana = true;
                        tap_code16(KC_ENTER);
                    }
                }
                else {
                    switch (keycode) {
                        case KN_I: kana_i_pressed = false; break;
                        case KN_O: kana_o_pressed = false; break;
                        case KN_K: kana_k_pressed = false; break;
                        case KN_L: kana_l_pressed = false; break;
                        case KN_J: kana_j_pressed = false; break;
                        case KN_M: kana_m_pressed = false; break;
                        case KN_N: kana_n_pressed = false; break;
                        default: break;
                    }
                    if (suppress_kana) {
                        // Reset kana buffers.
                        if (kana_state()) kana_on(! sft_r_x_interrupted, use_fn_for_ime_toggle);
                        suppress_kana = false;
                        return false;
                    }
                }

                // Output kana
                if (suppress_kana || ! process_kana(keycode, record)) {
                    return false;
                }
            }
            // kana

            if (record->event.pressed) {
                //if (sft_l_x_interrupted) {
                //    clear_all_flags();
                //    sft_r_x_interrupted = false; }
                //else if (sft_r_x_interrupted) {
                //    clear_all_flags();
                //    sft_r_x_interrupted = false; }
                //else {
                //    clear_all_flags();
                //    sft_l_x_interrupted = false;
                //    sft_r_x_interrupted = false; }

                // Delayed shifted key press:
                // Shift key will sometimes hung with 'last_pressed_shf_x = 0' without delayed_sfted_keypressed.

                // get_mods() & MOD_BIT(KC_LSFT) // check left shift state (bool)

                // Consecutive register_code(KC_LSFT) causes keymap bugs, which needs reinsering usb.

                if (timer_elapsed(last_pressed_shf_x_l) < TAP_TIME && ! delayed_l_sfted_keypressed) {
                    //if (sft_l_x_interrupted && ! (get_mods() & MOD_MASK_SHIFT)) {
                    if (sft_l_x_interrupted) {
                        register_code(KC_LSFT);
                        register_code(keycode);
                        unregister_code(KC_LSFT);
                        clear_all_flags();
                        return false; } }
                    // never reached here now... but works 2021/01
                if (timer_elapsed(last_pressed_shf_x_r) < TAP_TIME && ! delayed_r_sfted_keypressed) {
                    //if (sft_l_x_interrupted && ! (get_mods() & MOD_MASK_SHIFT)) {
                    if (sft_l_x_interrupted) {
                        //else if (sft_r_x_interrupted && ! (get_mods() & MOD_MASK_SHIFT)) {
                        if (sft_r_x_interrupted) {
                            register_code(KC_RSFT);
                            register_code(keycode);
                            unregister_code(KC_RSFT);
                            clear_all_flags();
                            return false; }
                        else {
                            clear_all_flags();
                            return true; } } }

                clear_all_flags();
            }
            else {
                unregister_code(keycode);
            }
            break; }

    return true;
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

void oled_task_user(void) {
    // Host Keyboard Layer Status
    //oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _ALPHABET:
            oled_write_P(PSTR("me\n"), false);
            break;
        case _QWT:
            oled_write_P(PSTR("QWT\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("Fn\n"), false);
            break;
        case _KANA:
            oled_write_P(PSTR("kana\n"), false);
            break;
        case _ONLY_NUMBERS:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _ONE_SIDE:
            oled_write_P(PSTR("One side\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_write_ln_P(PSTR(""), false);

    // Host Keyboard LED Status
    //led_t led_state = host_keyboard_led_state();
    //oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    //oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    //oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    //oled_write_P(PSTR("key: "), false);

    // 機能していない...
    //oled_write_P((! sft_l_interrupted || ! sft_r_interrupted) ? PSTR("+") : PSTR(""), false);
    //oled_write_P((! ctrl_l_interrupted || ! ctrl_r_interrupted) ? PSTR("^") : PSTR(""), false);

    switch (last_pressed_key) {
        case KC_A: oled_write_P(PSTR("A\n"), false); break;
        case KC_B: oled_write_P(PSTR("B\n"), false); break;
        case KC_C: oled_write_P(PSTR("C\n"), false); break;
        case KC_D: oled_write_P(PSTR("D\n"), false); break;
        case KC_E: oled_write_P(PSTR("E\n"), false); break;
        case KC_F: oled_write_P(PSTR("F\n"), false); break;
        case KC_G: oled_write_P(PSTR("G\n"), false); break;
        case KC_H: oled_write_P(PSTR("H\n"), false); break;
        case KC_I: oled_write_P(PSTR("I\n"), false); break;
        case KC_J: oled_write_P(PSTR("J\n"), false); break;
        case KC_K: oled_write_P(PSTR("K\n"), false); break;
        case KC_L: oled_write_P(PSTR("L\n"), false); break;
        case KC_M: oled_write_P(PSTR("M\n"), false); break;
        case KC_N: oled_write_P(PSTR("N\n"), false); break;
        case KC_O: oled_write_P(PSTR("O\n"), false); break;
        case KC_P: oled_write_P(PSTR("P\n"), false); break;
        case KC_Q: oled_write_P(PSTR("Q\n"), false); break;
        case KC_R: oled_write_P(PSTR("R\n"), false); break;
        case KC_S: oled_write_P(PSTR("S\n"), false); break;
        case KC_T: oled_write_P(PSTR("T\n"), false); break;
        case KC_U: oled_write_P(PSTR("U\n"), false); break;
        case KC_V: oled_write_P(PSTR("V\n"), false); break;
        case KC_W: oled_write_P(PSTR("W\n"), false); break;
        case KC_X: oled_write_P(PSTR("X\n"), false); break;
        case KC_Y: oled_write_P(PSTR("Y\n"), false); break;
        case KC_Z: oled_write_P(PSTR("Z\n"), false); break;
        case KC_DOT: oled_write_P(PSTR(". (dot)\n"), false); break;
        case KC_COMM: oled_write_P(PSTR(", (comma)\n"), false); break;
        case KC_BSLS: oled_write_P(PSTR("\\ (backslash)\n"), false); break;
        case KC_GRV: oled_write_P(PSTR("` (backquote)\n"), false); break;
        case KC_LBRC: oled_write_P(PSTR("[\n"), false); break; case KC_RBRC: oled_write_P(PSTR("]\n"), false); break;
        case KC_LSFT: oled_write_P(PSTR("LSFT\n"), false); break; case KC_RSFT: oled_write_P(PSTR("RSFT\n"), false); break;
        case KC_LCTL: oled_write_P(PSTR("LCTRL\n"), false); break; case KC_RCTL: oled_write_P(PSTR("RCTRL\n"), false); break;
        case KC_LALT: oled_write_P(PSTR("LALT\n"), false); break; case KC_RALT: oled_write_P(PSTR("RALT\n"), false); break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    //oled_write_ln_P(PSTR("==============="), false);

}
#endif
