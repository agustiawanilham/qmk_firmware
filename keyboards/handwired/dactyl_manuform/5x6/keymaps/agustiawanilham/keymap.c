#include "features/achordion.h"

#include QMK_KEYBOARD_H

enum layers {
  WIN,
  MAC,
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
};

// Home row mods for QWERTY layer for windows and linux
#define QHOME_Z LGUI_T(KC_Z)
#define QHOME_X LALT_T(KC_X)
#define QHOME_C LCTL_T(KC_C)
#define QHOME_V LSFT_T(KC_V)
#define QHOME_B HYPR_T(KC_B)

#define QHOME_N    HYPR_T(KC_N)
#define QHOME_M    RSFT_T(KC_M)
#define QHOME_COMM LCTL_T(KC_COMM)
#define QHOME_DOT  RALT_T(KC_DOT)
#define QHOME_SLSH LGUI_T(KC_SLSH)

#define CAPS_WORD QK_CAPS_WORD_TOGGLE

// For windows and linux
//             Left hand                          Right hand
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Gui  |  Alt  | Ctrl  | Shift |   | Shift | Ctrl  |  Alt  |  Gui  |
// +-------+-------+-------+-------+   +-------+-------+-------+-------+


// For mac
//             Left hand                          Right hand
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Ctrl  |  Alt  | Gui  | Shift |   | Shift |  Gui |  Alt  |  Ctrl  |
// +-------+-------+-------+-------+   +-------+-------+-------+-------+

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [WIN] = LAYOUT_5x6(
        KC_EQL,        KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                         KC_6,   KC_7,   KC_8,   KC_9,  KC_0,  KC_MINS,
        KC_TAB,        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                         KC_Y,   KC_U,   KC_I,   KC_O,  KC_P,  KC_BSLS,
        KC_ESC,        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                         KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT,
        OSM(MOD_LSFT), QHOME_Z,QHOME_X,QHOME_C,QHOME_V,QHOME_B,                      QHOME_N, QHOME_M,  QHOME_COMM,QHOME_DOT ,QHOME_SLSH,KC_RSFT,
                         KC_PGUP,KC_PGDN,                                                       KC_LBRC, KC_RBRC,
                                            MO(CURSOR),  LT(NUMBER,KC_BSPC),                          LT(MOUSE,KC_SPC), MO(SYMBOL),
                                               KC_LEFT,  KC_ESC,                                        KC_ENT, OSM(MOD_LSFT),
                                               KC_RGHT,  LT(FUNCTION,KC_DEL),                           KC_UP,  KC_DOWN
    ),

    [CURSOR] = LAYOUT_5x6(
        QK_BOOT,CG_LSWP,CG_LNRM,_______,_______,DB_TOGG,                          _______,_______,_______,_______,_______,_______,
        RGUI(KC_TAB),_______,RCTL(KC_W),_______,_______,_______,                        RCTL(KC_INS), KC_TAB,  S(KC_TAB),RGUI(KC_SPC),S(KC_INS),_______,
        _______,_______,_______,_______,RCTL(KC_F),_______,                          KC_LEFT,   KC_DOWN, KC_UP,     KC_RGHT,  CAPS_WORD,KC_CAPS,
        _______,KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,_______,                          KC_HOME,   KC_PGDN, KC_PGUP,   KC_END,   _______, LCTL(KC_A),
                                        RGUI(KC_C),RGUI(KC_V),                           _______,_______,
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
        _______,KC_ACL0,KC_MS_L,KC_MS_D,KC_MS_R,_______,                             _______,_______,_______,_______,_______,_______,
        _______,KC_ACL1,KC_ACL2,KC_WH_D,KC_WH_U,_______,                             _______,KC_RCTL,KC_RSFT,KC_RALT,KC_RGUI,_______,
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

        // Ring fingers
        case QHOME_X:
        case QHOME_DOT:
            return TAPPING_TERM + 200;

        // Pinkies
        case QHOME_Z:
        case QHOME_SLSH:
            return TAPPING_TERM + 50;

        // Middle fingers
        case QHOME_C:
        case QHOME_COMM:
            return TAPPING_TERM - 30;

        // Index fingers
        case QHOME_V:
        case QHOME_M:
            return TAPPING_TERM + 50;

        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case QHOME_N:
    case QHOME_M:
    case QHOME_X:
    case QHOME_C:
    case QHOME_V:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }

    return true;
}

void matrix_scan_user(void) {
  achordion_task();
}
