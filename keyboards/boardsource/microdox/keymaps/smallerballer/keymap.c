/*
Copyright 2022 Cole Smith <cole@boadsource.xyz>

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

#include <stdbool.h>
#include "keycodes.h"
#include "oled_driver.h"
#include "progmem.h"
#include QMK_KEYBOARD_H

// Left-hand home row mods
#define GUI_S LGUI_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
#define ALT_G LALT_T(KC_G)

// Right-hand home row mods
#define ALT_H LALT_T(KC_H)
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define GUI_L RGUI_T(KC_L)

// Mac Home row mods
#define CTL_S LCTL_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define GUI_K RGUI_T(KC_K)
#define CTL_L RCTL(KC_L)

// Layer Tap aliases
#define TOG_WIN DF(0)
#define TOG_MAC DF(1)
#define DEL_NAV LT(2, KC_DEL)
#define SLSH_MED LT(3, KC_QUOT)
#define BSPC_SYM LT(4, KC_BSPC)
#define TAB_NUM LT(5, KC_TAB)
#define ESC_FUNC LT(6, KC_ESC)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

enum layers {
    _BASE, // 0
    _MAC, // 1
    _NAV, // 2 - LEFT
    _MEDIA, // 3 - LEFT
    _SYM, // 4 - LEFT
    _NUM, // 5 - RIGHT
    _FUNC, // 6 - RIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,   GUI_S,   CTL_D,   SFT_F,   ALT_G,         ALT_H,   SFT_J,   CTL_K,    GUI_L,  KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  SLSH_MED,
                      ESC_FUNC, TAB_NUM,  KC_SPC,     KC_SPC, BSPC_SYM,  DEL_NAV
  ),

  // 1
  [_MAC] = LAYOUT_split_3x5_3(
    KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,     CTL_S,   GUI_D,  KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,    GUI_K,  CTL_L,  KC_TRNS,
    KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_TRNS
  ),

  // 2 LEFT
  [_NAV] = LAYOUT_split_3x5_3(
    KC_NO,    KC_FIND,   KC_UP,    KC_CUT,   KC_COPY,      QK_RBT,     DB_TOGG,   TOG_MAC,   TOG_WIN,  QK_BOOT,
    KC_NO,    KC_LEFT,   KC_DOWN,  KC_RGHT,  KC_PSTE,      KC_RALT,   KC_RSFT,   KC_RCTL,   KC_RGUI,  CW_TOGG,
    KC_NO,     KC_END,   KC_PGDN,  KC_PGUP,  KC_HOME,      KC_NO,     DT_DOWN,   DT_PRNT,   DT_UP,    KC_NO,
                            KC_ESC,   KC_TAB,   KC_ENT,       KC_SPC,    KC_BSPC,   KC_DEL
  ),

  //3 - LEFT
  [_MEDIA] = LAYOUT_split_3x5_3(
    RM_VALU,   RM_SATU,   RM_HUEU,  RM_TOGG,  RM_NEXT,      QK_RBT,     DB_TOGG,   TOG_MAC,   TOG_WIN,  QK_BOOT,
    KC_VOLD,   KC_VOLU,   KC_MPRV,  KC_MPLY,  KC_MNXT,      KC_RALT,   KC_RSFT,   KC_RCTL,   KC_RGUI,  CW_TOGG,
    KC_NO,     KC_NO,     KC_MUTE,  KC_NO,    KC_NO,        KC_NO,     DT_DOWN,   DT_PRNT,   DT_UP,    KC_NO,
                            KC_ESC,   KC_TAB,   KC_ENT,       KC_SPC,    KC_BSPC,   KC_DEL
  ),

  //4 - LEFT
  [_SYM] = LAYOUT_split_3x5_3(
    KC_PERC,   KC_HASH,   KC_LBRC,  KC_RBRC,  KC_AMPR,      QK_RBT,     DB_TOGG,   TOG_MAC,   TOG_WIN,  QK_BOOT,
    KC_EQL,    KC_RABK,   KC_LPRN,  KC_RPRN,  KC_CIRC,      KC_RALT,   KC_RSFT,   KC_RCTL,   KC_RGUI,  CW_TOGG,
    KC_AT,     KC_EXLM,   KC_LCBR,  KC_RCBR,  KC_DLR,       KC_NO,     DT_DOWN,   DT_PRNT,   DT_UP,    KC_NO,
                            KC_NUBS,  KC_GRV,    KC_ENT,      KC_SPC,   KC_BSPC,   KC_DEL
  ),

  //5 - RIGHT
  [_NUM] = LAYOUT_split_3x5_3(
    QK_BOOT,  TOG_WIN,    TOG_MAC,   DB_TOGG,    QK_RBT,    KC_MINS,   KC_7,  KC_8,  KC_9,  KC_NO,
    KC_CAPS,  KC_GUI,     KC_LCTL,   KC_LSFT,  KC_LALT,     KC_ELQ,    KC_4,  KC_5,  KC_6,  KC_QUOT,
    KC_NO,    DT_UP,      DT_PRNT,   DT_DOWN,    KC_NO,     KC_ASTR,   KC_1,  KC_2,  KC_3,  KC_NO,
                           KC_ESC,    KC_TAB,    KC_SPC,     KC_ENT,    KC_0,  KC_DEL
  ),


  //6 - RIGHT
  [_FUNC] = LAYOUT_split_3x5_3(
    QK_BOOT,  TOG_WIN,    TOG_MAC,   DB_TOGG,    QK_RBT,    KC_F12,   KC_F7,  KC_F8,  KC_F9,  KC_NO,
    CW_TOGG,  KC_GUI,     KC_LCTL,   KC_LSFT,  KC_LALT,     KC_F11,   KC_F4,  KC_F5,  KC_F6,  KC_NO,
    KC_NO,    DT_UP,      DT_PRNT,   DT_DOWN,    KC_NO,     KC_F10,   KC_F1,  KC_F2,  KC_F3,  KC_NO,
                           KC_ESC,    KC_TAB,    KC_SPC,     KC_ENT,    KC_0,  KC_DEL
  ),
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

static void print_mod_status(void) {
    uint8_t mod_state = get_mods();

    oled_write_P(PSTR("Mods: "), false);

    oled_write_P(mod_state & MOD_MASK_CTRL ? PSTR("Ctrl ") : PSTR(""), false);
    oled_write_P(mod_state & MOD_MASK_SHIFT ? PSTR("Sft ") : PSTR(""), false);
    oled_write_P(mod_state & MOD_MASK_ALT ? PSTR("Alt ") : PSTR(""), false);
    oled_write_P(mod_state & MOD_MASK_GUI ? PSTR("GUI ") : PSTR(""), false);
}

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _MAC:
            oled_write_ln_P(PSTR("MAC"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Number"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined Layer"), false);
    }

    oled_write_P(PSTR("---"), false);
    print_mod_status();

    oled_write_P(PSTR("---"), false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("Other state: "), false);
    oled_write_P(led_state.caps_lock ? PSTR("Caps-lock: on") : PSTR("Caps-lock: off"), false);

}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();  // Renders a static logo
        oled_scroll_left();  // Turns on scrolling
    }
    return false;
}
#endif
