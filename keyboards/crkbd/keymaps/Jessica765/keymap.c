/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

enum keymap_layers {
	_ISRT,
	_GAME,
	_NAVI,
	_NUMB,
	_FUNCT
};

#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(LSFT(KC_Z))
#define KC_CUT LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ISRT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Y,    KC_C,    KC_L,    KC_M,    KC_K,                         KC_Z,    KC_F,    KC_U, KC_COMM, KC_QUOT, TG(_GAME),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_I,    KC_S,    KC_R,    KC_T,    KC_G,                         KC_P,    KC_N,    KC_E,    KC_A,    KC_O, KC_LALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Q,    KC_V,    KC_W,    KC_D,    KC_J,                         KC_B,    KC_H, KC_SLSH,  KC_DOT,    KC_X,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(_NAVI), KC_LSFT, KC_BSPC,     KC_SPC,  KC_ENT, MO(_NUMB)
                                      //`--------------------------'  `--------------------------'

  ),

  [_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT,  KC_SPC,    KC_BSPC,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAVI] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_INS, KC_PGUP, KC_PSCR,   KC_UP, KC_CAPS, KC_HOME,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_DEL, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_UNDO,  KC_CUT, KC_COPY, KC_PASTE, KC_REDO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   KC_NO, KC_BSPC,     KC_SPC,   KC_NO, MO(_FUNCT)
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LBRC, KC_RBRC,    KC_7,    KC_8,    KC_9, KC_SCLN,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_COMM,  KC_DOT,    KC_4,    KC_5,    KC_6, KC_MINS,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_GRV, KC_BSLS,    KC_1,    KC_2,    KC_3,  KC_EQL,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       MO(_FUNCT),    KC_0, KC_BSPC,     KC_SPC,   KC_NO, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNCT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SLCK,                      RGB_M_P, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   KC_NO, KC_BSPC,     KC_SPC,   KC_NO,  KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )

};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;
}

void oled_render_status(void) {
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _ISRT:
            oled_write_P(PSTR("\n ISRT"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("\n GAME"), false);
            break;
        case _NAVI:
            oled_write_P(PSTR("\n NAVI"), false);
            break;
        case _NUMB:
            oled_write_P(PSTR("\n NUMB"), false);
            break;
        case _FUNCT:
            oled_write_P(PSTR("\n FUNC"), false);
            break;
        default:
            oled_write_P(PSTR("\n N/A"), false);
    }

	led_t led_state = host_keyboard_led_state();
	oled_write_P(PSTR("\nLock\n"), false);
    oled_write_P(led_state.num_lock ? PSTR("\n NUML") : PSTR("       "), false);
    oled_write_P(led_state.caps_lock ? PSTR("\n CAPL") : PSTR("       "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("\n SCRL") : PSTR("       "), false);
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_status();
    } else {
        oled_render_logo();
    }
}

#endif // OLED_DRIVER_ENABLE
