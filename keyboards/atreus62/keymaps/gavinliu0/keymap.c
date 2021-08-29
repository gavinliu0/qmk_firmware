// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEF 0
#define _NUM 1
#define _SYM 2
#define _NAV 3
#define _GAM 4
#define _NPD 5
#define _RST 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Default / Base

    |ESC/`  | 1 | 2 | 3 | 4  | 5 |        | 6 | 7  | 8 | 9  | 0  | -   |
    |TAB    | Q | W | E | R  | T |        | Y | U  | I | O  | P  |BCK  |
    |CTL/DEL| A | S | D | F  | G |        | H | J  | K | L  | :  | '   |
    |SFT/(  | Z | X | C | V  | B |        | N | M  | , | .  | /  |SFT/)|
    |ALT    |WIN|SPC|   |_SYM|ENT|   |_NAV|SPC|_SYM|   |_GAM|_RST|     |
  */
  [_DEF] = LAYOUT( // 0
    KC_GESC,             KC_1,    KC_2,   KC_3,  KC_4,     KC_5,                    KC_6,   KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS ,
    KC_TAB,              KC_Q,    KC_W,   KC_E,  KC_R,     KC_T,                    KC_Y,   KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC ,
    MT(MOD_LCTL,KC_DEL), KC_A,    KC_S,   KC_D,  KC_F,     KC_G,                    KC_H,   KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT ,
    KC_LSPO,             KC_Z,    KC_X,   KC_C,  KC_V,     KC_B,                    KC_N,   KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC ,
    KC_LALT,             KC_LGUI, KC_SPC, KC_NO, MO(_NUM), KC_ENT, KC_NO, MO(_NAV), KC_SPC, MO(_SYM), TG(_NPD), TO(_GAM), MO(_RST), KC_NO
  ),

  /* Numbers

    |   |   |   |   |   |   |        |   |   |   |   |   |   |
    |   | 1 | 2 | 3 | 4 | 5 |        | 6 | 7 | 8 | 9 | 0 |BCK|
    |BCK| _ | = |   | { | [ |        | ] | } | - | + | | | \ |
    |   |   |   |   |   | < |        | > |   |   |   |   |   |
    |   |   |   |   |   |   |_DEF|   |   |   |   |   |   |   |
  */
  [_NUM] = LAYOUT( // 1
    KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO,                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO ,
    KC_NO,   KC_1,    KC_2,   KC_3,  KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC ,
    KC_BSPC, KC_UNDS, KC_EQL, KC_NO, KC_LCBR, KC_LBRC,                KC_RBRC, KC_RCBR, KC_MINS, KC_PLUS, KC_PIPE, KC_BSLS ,
    KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_LT,                  KC_GT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO ,
    KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, TO(_DEF), KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

   /* Symbols

    |       |   |   |   |   |   |        |   |   |   |   |   |   |
    |~      | ! | @ | # | $ | % |        | ^ | & | * | ( | ) |BCK|
    |CTL/DEL| _ | = |   | { | [ |        | ] | } | - | + | | | \ |
    |       |   |   |   |   | < |        | > |   |   |   |   |   |
    |       |   |   |   |   |   |_DEF|   |   |   |   |   |   |   |
  */
  [_SYM] = LAYOUT( // 2
    KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO ,
    KC_TILD, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC ,
    KC_TRNS, KC_UNDS, KC_EQL, KC_NO,   KC_LCBR, KC_LBRC,                KC_RBRC, KC_RCBR, KC_MINS, KC_PLUS, KC_PIPE, KC_BSLS ,
    KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_LT,                  KC_GT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO ,
    KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO, TO(_DEF), KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

  /* Navigation 

    |   |   |   |   |   |   |        |    |     |    |     |   |   |
    |   |   |   |   |   |   |        |    |PG_UP|UP  |     |   |   |
    |   |   |   |   |   |   |        |HOME|LEFT |DOWN|RIGHT|END|   |
    |   |   |   |   |   |   |        |    |PG_DN|    |     |   |   |
    |   |   |   |   |   |   |_DEF|   |    |     |    |     |   |   |
  */
  [_NAV] = LAYOUT( // 3
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO ,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO,   KC_PGUP, KC_UP,   KC_NO,    KC_NO,  KC_NO ,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_NO ,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO,   KC_PGDN, KC_NO,   KC_NO,    KC_NO,  KC_NO ,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_DEF), KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO
  ),

  /* Gaming

    |ESC| 1 | 2 | 3 | 4 | 5 |        | 6 | 7 | 8 | 9 | 0 | - |
    |TAB| Q | W | E | R | T |        | Y | U | I | O | P |BCK|
    |CTL| A | S | D | F | G |        | H | J | K | L | : | ' |
    |SFT| Z | X | C | V | B |        | N | M | , | . | / |SFT|
    |ALT|WIN|   |   |SPC|ENT|_DEF| ` |SPC|   |   |   |   |   |
  */
  [_GAM] = LAYOUT( // 4
    KC_ESC,  KC_1,    KC_2,  KC_3,  KC_4,   KC_5,                     KC_6,   KC_7,  KC_8,    KC_9,   KC_0,    KC_MINS ,
    KC_TAB,  KC_Q,    KC_W,  KC_E,  KC_R,   KC_T,                     KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC ,
    KC_LCTL, KC_A,    KC_S,  KC_D,  KC_F,   KC_G,                     KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT ,
    KC_LSFT, KC_Z,    KC_X,  KC_C,  KC_V,   KC_B,                     KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT ,
    KC_LALT, KC_LGUI, KC_NO, KC_NO, KC_SPC, KC_ENT, TO(_DEF), KC_GRV, KC_SPC, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO
  ),

  /* Number Pad 

    |   |   |   |   |   |   |         |   |   |   |   |   |   |
    |   |   |   |   |   |   |         |   | 7 | 8 | 9 |   |BCK|
    |   |   |   |   |   |   |         |   | 4 | 5 | 6 |   |   |
    |   |   |   |   |   |   |         |   | 1 | 2 | 3 |   |   |
    |   |   |   |   |   |   |_DEF|_NAV|SPC| 0 |   | . |   |   |
  */
  [_NPD] = LAYOUT( // 5
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO ,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO,  KC_P7, KC_P8,   KC_P9,   KC_NO, KC_BSPC ,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO,  KC_P4, KC_P5,   KC_P6,   KC_NO, KC_NO ,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO,  KC_P1, KC_P2,   KC_P3,   KC_NO, KC_NO ,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_DEF), MO(_NAV), KC_SPC, KC_P0, KC_TRNS, KC_PDOT, KC_NO, KC_NO
  ),

  /* Reset and function keys

    |F12|F1 |F2 |F3 |F4 |F5 |        |F6 |F7 |F8 |F9 |F10|F11  |
    |   |   |   |   |   |   |        |   |   |   |   |   |     |
    |   |   |   |   |   |   |        |   |   |   |   |   |     |
    |   |   |   |   |   |   |        |   |   |   |   |   |     |
    |   |   |   |   |   |   |_DEF|   |   |   |   |   |   |RESET|
  */
  [_RST] = LAYOUT( // 6
    KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11 ,
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO ,
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO ,
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO ,
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_DEF), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  RESET
  )
};
