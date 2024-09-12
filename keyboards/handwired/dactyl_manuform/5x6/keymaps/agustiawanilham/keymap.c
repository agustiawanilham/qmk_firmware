#include "features/achordion.h"
#include "features/select_word.h"

#include QMK_KEYBOARD_H

enum layers {
  BASE,
  CURSOR,
  NUMBER,
  FUNCTION,
  SYMBOL,
  MOUSE,
};

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  EXIT,
  SCOPE,
  SELWORD,
  TMUXESC,
  SRCHSEL,
  USRNAME,
  DASH,
  ARROW,
  THMBUP,
  REPEAT,
  REVREP,
  CAPS_WORD,
  LINUX,
  COPY,
  PASTE,
};

// Home row mods for QWERTY layer.
#define QHOME_Z LGUI_T(KC_Z)
#define QHOME_X LALT_T(KC_X)
#define QHOME_C LCTL_T(KC_C)
#define QHOME_V LSFT_T(KC_V)
#define QHOME_B HYPR_T(KC_B)

#define QHOME_M    RSFT_T(KC_M)
#define QHOME_COMM RCTL_T(KC_COMM)
#define QHOME_DOT  RALT_T(KC_DOT)
#define QHOME_SLSH RGUI_T(KC_SLSH)

#define CAPS_WORD QK_CAPS_WORD_TOGGLE

// This keymap uses home row mods. In addition to mods, I have home row
// layer-tap keys for the SYM layer. The key arrangement is a variation on
// "GASC-order" home row mods:
//
//             Left hand                          Right hand
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Gui  |  Alt  | Shift | Ctrl  |   | Ctrl  | Shift |  Alt  |  Gui  |
// +-------+-------+-------+-------+   +-------+-------+-------+-------+


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [BASE] = LAYOUT_5x6(
        KC_EQL,       KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                         KC_6,   KC_7,   KC_8,   KC_9,  KC_0,  KC_MINS,
        KC_TAB,       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                         KC_Y,   KC_U,   KC_I,   KC_O,  KC_P,  KC_BSLS,
        KC_ESC,       KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                         KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT,
        OSM(MOD_LSFT), QHOME_Z,QHOME_X,QHOME_C,QHOME_V,QHOME_B,                      KC_N, QHOME_M,  QHOME_COMM,QHOME_DOT ,QHOME_SLSH,KC_RSFT,
                         KC_PGUP,KC_PGDN,                                                       KC_LBRC, KC_RBRC,
                                            MO(CURSOR),  LT(NUMBER,KC_BSPC),                          LT(MOUSE,KC_SPC), MO(SYMBOL),
                                               KC_LEFT,  KC_ESC,                          KC_ENT, KC_HYPR,
                                               KC_RGHT,  LT(FUNCTION,KC_DEL),                           KC_UP,  KC_DOWN
    ),


    [CURSOR] = LAYOUT_5x6(
        QK_BOOT,_______,_______,_______,_______,DB_TOGG,                          G(KC_C),_______,_______,_______,G(KC_V),_______,
        G(KC_TAB),_______,C(KC_W),_______,_______,_______,                        COPY,    KC_TAB,  S(KC_TAB), G(KC_SPC),S(KC_INS),SELWORD,
        _______,KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,C(KC_F),                          KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT,CAPS_WORD,KC_CAPS,
        _______,_______,_______,_______,_______,_______,                          KC_HOME, KC_PGDN, KC_PGUP,   KC_END,G(KC_TAB),LCTL(KC_A),
                                        G(KC_C),G(KC_V),                           _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______

    ),

    [NUMBER] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,                          KC_TILD,  KC_DLR,   KC_HASH,   KC_AT,   KC_EXLM,    KC_CIRC,
        _______,_______,_______,_______,_______,_______,                          KC_LT,    KC_7,     KC_8,      KC_9,    KC_COLN,    KC_PERC,
        _______,_______,_______,_______,_______,_______,                          KC_GT,    KC_4,     KC_5,      KC_6,    KC_PMNS,    KC_PPLS,
        _______,KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,_______,                       KC_EQL,   KC_1,     KC_2,      KC_3,    KC_PSLS,    KC_PAST,
                                                _______,_______,                                      KC_LPRN,  KC_RPRN,
                                                _______,_______,            _______,KC_0,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______

    ),


    [FUNCTION] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,                          KC_MSEL,  KC_MPLY,   KC_MPRV,    KC_MNXT,   KC_MSTP,    KC_CIRC,
        _______,_______,_______,_______,_______,_______,                          KC_MAIL,  KC_F7,     KC_F8,      KC_F9,     KC_F10,     KC_WSCH,
        _______,_______,_______,_______,_______,_______,                          KC_CALC,  KC_F4,     KC_F5,      KC_F6,     KC_F11,     KC_WFAV,
        _______,KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,_______,                          KC_MYCM,  KC_F1,     KC_F2,      KC_F3,     KC_F12,     KC_PSCR,
                                                _______,_______,                                      KC_APP,  KC_HELP,
                                                _______,_______,            _______,KC_MUTE,
                                                _______,_______,            _______,_______,
                                                _______,_______,            KC_VOLU,KC_VOLD
    ),

    [SYMBOL] = LAYOUT_5x6(
          KC_TILD, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_QUES,                        _______,_______,_______,_______,_______,_______,
          KC_SLSH, KC_LCBR, KC_GRV,  KC_QUOT, KC_RCBR, KC_AT,                         _______,_______,KC_TAB,S(KC_TAB),_______,_______,
          KC_HASH, KC_CIRC, KC_EQL,  KC_UNDS, KC_DLR,  KC_PERC,                        _______,KC_BSPC,KC_DEL,KC_SPC,KC_ENT,_______,
          KC_EXLM, KC_LT,   KC_PIPE, KC_ASTR, KC_GT,   KC_PPLS,                        _______,KC_RSFT,KC_RCTL,KC_RALT,KC_RGUI,_______,
                          KC_AMPR,KC_PIPE,                                    _______ ,_______,
                                                  KC_COLN,KC_ASTR,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    ),
    [MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,                   _______  , _______ , _______ , _______ ,_______ ,_______ ,
        _______,_______,KC_WH_L,KC_MS_U,KC_WH_R,_______,                            _______,_______,_______,_______ ,_______,_______,
        _______,KC_ACL1,KC_MS_L,KC_MS_D,KC_MS_R,_______,                             _______,_______,_______,_______,_______,_______,
        _______,KC_ACL2,KC_ACL0,KC_WH_D,KC_WH_U,_______,                             _______,KC_RSFT,KC_RCTL,KC_RALT,KC_RGUI,_______,
                                      _______,_______,                            _______ ,_______,
                                                KC_BTN1,KC_BTN2,            _______,_______,
                                                _______,KC_BTN3,            _______,_______,
                                                _______,KC_BTN4,            _______,_______

    ),
};


bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_MINS:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    default:
      return 800;  // Use a timeout of 800 ms.
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QHOME_V:
        case QHOME_M:
            return TAPPING_TERM + 50; // Recommended
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_select_word(keycode, record, SELWORD)) { return false; }

    return true;
}

void matrix_scan_user(void) {
  achordion_task();
}
