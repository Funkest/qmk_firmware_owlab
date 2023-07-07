#include QMK_KEYBOARD_H
#include <string.h>

// kana
#include "kana.h"
NGKEYS kana_keys;
// kana

enum layer_names {
      _ALPHABET = 0
    , _QWT
    , _QWT2
    , _LOWER
    , _RAISE
    , _ALT_WIN
    , _ALT_WIN_B
    , _FN
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
#define KC_____     _______
#define KC_XXXX     KC_NO

#define KC_BR_PR    KC_PARENTHESIS
#define KC_BR_SQ    KC_SQ_BRACKETS
#define KC_RBT      QK_RBT

enum custom_keycodes {
      //BASE = SAFE_RANGE
      // kana
      KC_QWT = KN_SAFE_RANGE
      // kana
    , KC_QWT2
    , KN_LSFT
    , KN_RSFT
    , KC_ALPH
    , KC_LOFF
    , KC_ALLUP
    , KC_LOWER
    , KC_RAISE
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
};

#define KC_OVR_TGL QK_KEY_OVERRIDE_TOGGLE
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

  [_ALPHABET] = LAYOUT_kc( \
      BSPC      , D         , R         , N         , A         , Q             , ____      , Y         , S         , H         , J         , K         , L             , DEL       , OVR_TGL
    , TAB       , U         , O         , I         , E         , G             , BSPC      , P         , E         , T         , W         , SCLN      , QUOT          , SLSH      , TGL_IME_FN
    , MN_C      , X         , V         , F         , L         , Z             , UNDS      , B         , C         , M         , COMM      , DOT                       , ENTER     , NUM
    , LALT      , xLSFT     , CTL_ESC   , xLSFT     , LOWER     , LAST          , LAST      , RAISE     , xRSFT     , CTL_QOT   , xRSFT     , RALT                      , UP        , LOFF
    , LCTL, LGUI, LALT, SPC, RALT, RCTL, LEFT, DOWN, RBT
)

, [_QWT] = LAYOUT_kc( \
      ESC       , 1         , 2         , 3         , 4         , 5             , 6         , 7         , 8         , 9         , 0         , MINS      , EQL           , BSPC      , DEL
    , TAB       , Q         , W         , E         , R         , T             , Y         , U         , I         , O         , P         , LBRC      , RBRC          , BSLS      , PGUP
    , LCTL      , A         , S         , D         , F         , G             , H         , J         , K         , L         , SCLN      , QUOT                      , ENT       , PGDN
    , LSFT      , Z         , X         , C         , V         , B             , N         , M         , COMM      , DOT       , SLSH      , RSFT                      , UP        , B
    , QWT2, LGUI, LALT, SPC, RALT, RCTL, LEFT, DOWN, RGHT
)

, [_QWT2] = LAYOUT_kc(
      GRV       , F1       , F2         , F3        , F4        , F5            , F6        , F7        , F8        , F9        , F10       , F11       , F12           , ____      , ____
    , ____      , ____      , ____      , ____      , ____      , ____          , ____      , ____      , ____      , ____      , ____      , ____      , ____          , ____      , HOME
    , ____      , ____      , ____      , ____      , ____      , ____          , ____      , ____      , ____      , ____      , ____      , ____                      , ____      , END
    , ____      , ____      , ____      , ____      , ____      , ____          , ____      , ____      , ____      , ____      , ____      , ____                      , ____      , ____
    , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____
)

, [_KANA] = LAYOUT_all( \
      _______   , KN_Q      , KN_W      , KN_E      , KN_R      , KN_T          , _______   , KN_Y      , KN_U      , KN_I      , KN_O      , KN_P      , _______       , _______   , _______
    , _______   , KN_A      , KN_S      , KN_D      , KN_F      , KN_G          , _______   , KN_H      , KN_J      , KN_K      , KN_L      , KN_SCLN   , KN_Z          , _______   , _______
    , _______   , KN_Z      , KN_X      , KN_C      , KN_V      , KN_BL         , _______   , KN_BR     , KN_N      , KN_M      , KN_COMM   , KN_DOT                    , KC_SLSH   , _______
    , _______   , _______   , N_CTRL    , KN_LSFT   , N_LOWER   , KC_BSPC       , KC_DEL    , N_RAISE   , KN_RSFT   , N_CTRL    , _______   , _______                   , _______   , _______
    , _______, _______, _______, _______, _______, _______, _______, _______, _______
 )
// MS_BTN3 : mid, MS_BTN4 : browser_back, MS_BTN5 : browser_forward (KC_WBAK, KC_WFWD not work on win)
//  https://www.autohotkey.com/docs/KeyList.htm#mouse-advanced
, [_LOWER] = LAYOUT_kc( \
      ____      , 1         , 2         , 3         , 4         , 5             , MINS      , DOT       , 6         , 7         , 8         , 9         , 0             , ____      , ____
    , ____      , DEL       , CIRC      , LBRC      , RBRC      , SLSH          , MS_BTN4   , LEFT      , DOWN      , UP        , RGHT      , BSLS      , QUOT          , ____      , ____
    , ____      , LEFT      , DOWN      , UP        , RGHT      , FN_EX         , DEL       , BSPC      , HOME      , END       , PGUP      , PGDN                      , GRV       , ____
    , ENTER     , XXXX      , ____      , ____      , ____      , ____          , ____      , XXXX      , ____      , ____      , ____      , ____                      , ____      , ____
    , ____, ____, ____, ____, ____, ____, ____, ____, ____
)
//  ____ causes Kana-off when BSPC on _LOWER with mis-touching this key (send RAISE tapping) .
, [_RAISE] = LAYOUT_kc( \
      ____      , 1         , 2         , 3         , 4         , 5             , MINS      , DOT       , 6         , 7         , 8         , 9         , 0             , PSCR      , ____
    , ____      , ____      , ____      , LBRC      , RBRC      , SLSH          , PPLS      , EQL       , LCBR      , RCBR      , DLR       , BSLS      , DQUO          , ____      , ____
    , ____      , ____      , ____      , BR_PR     , BR_SQ     , MINUS         , WIN_EX    , FN_EX     , LPRN      , RPRN      , BSPC      , GRV                       , ____      , ____
    , ____      , QWT       , ____      , ____      , ____      , ____          , ____      , ____      , ____      , ____      , ____      , ____                      , ____      , ____
    , ____ , ____ , ____ , ____, ____, ____, ____, ____, ____
)

, [_ALT_WIN] = LAYOUT_kc( \
      ____      , Q         , W         , E         , R         , T             , Y         , U         , I         , O         , P         , XXXX      , ____          , ____      , ____
    , ____      , A         , S         , D         , F         , G             , H         , J         , K         , L         , SCLN      , XXXX      , ____          , ____      , ____
    , ____      , ____      , Z         , X         , C         , V             , B         , N         , M         , COMM      , DOT       , SLSH                      , ____      , ____
    , LOFF      , TAB       , XXXX      , ____      , LOWER     , RAISE         , ____      , ____      , ____      , XXXX      , XXXX      , XXXX                      , ____      , ____
    , ____, ____, ____, ____, ____, ____, ____, ____, ____
)

, [_ALT_WIN_B] = LAYOUT_kc( \
      ____      , D         , R         , N         , A         , Q             , ____      , Y         , S         , H         , J         , K         , L             , ____      , ____
    , ____      , U         , O         , I         , E         , G             , ____      , P         , E         , T         , W         , SCLN      , QUOT          , ____      , ____
    , ____      , X         , V         , F         , L         , Z             , ____      , B         , C         , M         , COMM      , DOT                       , ____      , ____
    , LOFF      , TAB       , ____      , ____      , LOWER     , ____          , ____      , RAISE     , ____      , ____      , ____      , ____                      , ____      , ____
    , ____, ____, ____, ____, ____, ____, ____, ____, ____
)

, [_FN] = LAYOUT_kc( \
      F1        , F2        , F3        , F4        , F5        , F6            , F1        , F2        , F3        , F4        , F5        , F6        , ____          , ____      , ____
    , F7        , F8        , F9        , F10       , F11       , F12           , F7        , F8        , F9        , F10       , F11       , F12       , ____          , ____      , ____
    , XXXX      , XXXX      , LALT      , XXXX      , XXXX      , XXXX          , ALLUP     , XXXX      , XXXX      , RALT      , XXXX      , XXXX                      , ____      , ____
    , ____      , ____      , ____      , ____      , ____      , ____          , ____      , ____      , ____      , ____,      ____       , ____                      , ____      , ____
    , ____, ____, ____, ____, ____, ____, ____, ____, ____
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

const uint16_t TAP_TIME = 200;

void clear_all_flags(void) {
    raise_interrupted       = true;
    lower_interrupted       = true;
    ctrl_l_interrupted      = true;
    ctrl_r_interrupted      = true;
    sft_l_x_interrupted     = true;
    sft_r_x_interrupted     = true;
    delayed_l_sfted_keypressed= true;
    delayed_r_sfted_keypressed= true;
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

// main

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // shift in kana layer

    if (record->event.pressed){
        if (keycode != KC_LAST && keycode < KN_SAFE_RANGE){
            last_pressed_key = keycode; }
    // set_timelog();
    //
        switch (keycode){
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
        case KC_QWT2:
            if (record->event.pressed){
                layer_on(_QWT2); }
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
        // kana
        case KC_LOFF:
            if (record->event.pressed) {
                // kana
                kana_off(! sft_l_x_interrupted, use_fn_for_ime_toggle);
                // kana
                layer_off(_QWT);
                layer_off(_FN);
                layer_off(_ALT_WIN);
                layer_off(_ALT_WIN_B);
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
        // kana
        case N_OFF_K:
            if (record->event.pressed) {
                //kana_off_keep_ime(); }
                kana_off(! sft_l_x_interrupted, use_fn_for_ime_toggle); }
            return false;
        // kana
        default:
            if (keycode < KN_SAFE_RANGE){
              // kana
              if (!process_kana(keycode, record))
                return false; }

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

