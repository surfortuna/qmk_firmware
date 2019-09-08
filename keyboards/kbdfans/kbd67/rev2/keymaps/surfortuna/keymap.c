/* 
 * KBD67 - surfortuna keymap
 */

#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

// Layer names for readability
#define _BL 0     // base layer
#define _FL 1     // function layer
#define _NL 2     // numpad layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  ^|  \|~ `|Del |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| BS  |PgUp|
   * |----------------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Ent  |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|Win |
   * |----------------------------------------------------------------|
   * |Ctrl| FN |Alt |        Space          |Alt| FN|    |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */

/*  Template for split backspace + no split spacebar or left shift 
 *

[0] = LAYOUT_all(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, \
  _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, \
  _______,XXXXXXX,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, \
  _______, _______, _______,          XXXXXXX,           _______,        XXXXXXX,           _______, _______,XXXXXXX, _______, _______, _______),    

 *
 */ 

[_BL] = LAYOUT_all(
  KC_ESC ,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL, KC_BSLS,KC_GRAVE,  KC_DEL, \
  KC_TAB ,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,  KC_RBRC,     KC_BSPC, KC_PGUP, \
  KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,           KC_ENT, KC_PGDN, \
  KC_LSFT,  XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,         KC_RSFT, KC_UP, KC_RGUI, \
  KC_LCTL,  MO(_FL),   KC_LALT,          XXXXXXX,           KC_SPC,        XXXXXXX,           KC_RALT, MO(_FL),XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT),  

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * |   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|   |Ins|Rset|
   * |----------------------------------------------------------------|
   * |     |Mut|VDn|VUp|   |   |   |   |PSc|SLk|Pau|Up |    |Calc|Home|
   * |----------------------------------------------------------------|
   * |      |Prv|Ply|Nxt|   |   |   |   |Hom|PUp|Lef|Rig|        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |End|PDn|Dow|      |PUp|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |Hom|PDn|End |
   * `----------------------------------------------------------------'
   */

[_FL] = LAYOUT_all(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, _______,RESET,  KC_INS, \
  _______,     KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,   KC_UP, _______,      KC_CALC, KC_HOME, \
  _______,       KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,             _______,  KC_END, \
  _______,XXXXXXX,    _______, _______, _______, _______, _______, _______, _______,  KC_END, KC_PGDN, KC_DOWN,        _______, KC_PGUP, _______, \
  _______, _______, _______,          XXXXXXX,           _______,        XXXXXXX,           _______, _______,XXXXXXX, KC_HOME,  KC_PGDN, KC_END),  

  /* Keymap Numpad Layer
   * ,----------------------------------------------------------------.
   * |_BL|   |   |   |   |   |/  |7  |8  |9  |-  |   |   |   |Del|Rset|
   * |----------------------------------------------------------------|
   * |Tab  |MLC|MUp|MRC|   |   |*  |4  |5  |6  |+  |   |    |BS  |Calc|
   * |----------------------------------------------------------------|
   * |      |MLf|MDw|MRt|   |   |   |1  |2  |3  |ENT|   |Enter   |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |00 |0  |.  |=  |      |Up |    |
   * |----------------------------------------------------------------|
   * |    |    |    |         Space         |   |   |    |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */

[_NL] = LAYOUT_all(
  TG(_NL),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PSLS,   KC_P7,   KC_P8,   KC_P9, KC_PMNS,   KC_NO,   KC_NO,   KC_NO,   RESET,  KC_DEL, \
  KC_TAB ,     KC_BTN1, KC_MS_U, KC_BTN2,   KC_NO,   KC_NO, KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_PPLS,   KC_NO,   KC_NO,      KC_BSPC, KC_CALC, \
    KC_NO,       KC_MS_L, KC_MS_D, KC_MS_R,   KC_NO,   KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3, KC_PENT,   KC_NO,             KC_ENT ,   KC_NO, \
    KC_NO,XXXXXXX,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P0, KC_PDOT, KC_PEQL,          KC_NO, KC_UP  ,   KC_NO, \
  RGB_TOG, BL_TOGG,  BL_STEP,          XXXXXXX,            KC_SPC,        XXXXXXX,             KC_NO,   KC_NO,XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT), 

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
  // set caps lock led pin as output
  DDRD |= (1 << 4);
  // default to off
  PORTD &= ~(1 << 4);
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRD |= (1 << 4); PORTD &= ~(1 << 4);
	} else {
		DDRD &= ~(1 << 4); PORTD &= ~(1 << 4);
	}

}


// combos
enum combo_events {
  LALT_RALT_NL
};

const uint16_t PROGMEM numpad_layer_combo[] = {KC_LALT, KC_RALT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [LALT_RALT_NL] = COMBO_ACTION(numpad_layer_combo)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index){
    case LALT_RALT_NL:
      if (pressed) {
        layer_on(_NL);
      }
      break;
  }
}