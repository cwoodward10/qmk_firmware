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
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Mac Home row mods
#define CTL_A LCTL_T(KC_A)
#define GUI_F LGUI_T(KC_F)
#define GUI_J RGUI_T(KC_J)
#define CTL_SCLN RCTL(KC_SCLN)

// Layer Tap aliases
#define TOG_WIN DF(0)
#define TOG_MAC DF(1)
#define TAB_NAV LT(2, KC_TAB)
#define ESC_MED LT(3, KC_ESC)
#define BSPC_NUM LT(4, KC_BSPC)
#define DEL_SYM LT(5, KC_ENT)
#define SLSH_FUNC LT(6, KC_SLSH)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

enum layers {
    _BASE, // 0
    _MAC, // 1
    _NAV, // 2
    _MEDIA, // 3
    _NUM, // 4
    _SYM, // 5
    _FUNC, // 6
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    GUI_A,   ALT_S,   SFT_D,   CTL_F,   KC_G,         KC_H,   CTL_J,   SFT_K,    ALT_L,  GUI_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  SLSH_FUNC,
                      ESC_MED,  KC_ENT, TAB_NAV,     KC_SPC, BSPC_NUM,  DEL_SYM
  ),

  [_MAC] = LAYOUT_split_3x5_3(
    KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    CTL_A,     KC_TRNS,   KC_TRNS,  GUI_F,     KC_TRNS,        KC_TRNS,   GUI_J,    KC_TRNS,  KC_TRNS,  CTL_SCLN,
    KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS
  ),

  [_NAV] = LAYOUT_split_3x5_3(
    QK_BOOT,  TOG_WIN,    TOG_MAC,   KC_NO,    KC_NO,           S(KC_UNDO),   KC_PSTE,  KC_COPY,  KC_CUT,  KC_UNDO,
    KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,  KC_NO,          CW_TOGG,      KC_LEFT,   KC_DOWN,  KC_UP,  KC_RIGHT,
    KC_NO,     DT_UP,   DT_PRNT,   DT_DOWN,    KC_NO,         KC_INS,       KC_HOME,   KC_PGUP,  KC_PGDN,  KC_END,
                           KC_TRNS,   KC_TRNS,  KC_TRNS,        KC_ENT,       KC_BSPC,   KC_DEL
  ),

  [_MEDIA] = LAYOUT_split_3x5_3(
    QK_BOOT,  TOG_WIN,    TOG_MAC,   KC_NO,    KC_NO,         RGB_TOG,    RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,
    KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,  KC_NO,        KC_MYCM,    KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPRV,
    KC_NO,     DT_UP,   DT_PRNT,   DT_DOWN,    KC_NO,       KC_WSCH,    KC_WBAK,   KC_WSTP,  KC_WREF,  KC_WFWD,
                           KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_MSTP,   KC_MPLY,   KC_MUTE
  ),

  [_NUM] = LAYOUT_split_3x5_3(
    KC_SCLN,   KC_7,      KC_8,      KC_9,     KC_EQL,       KC_NO,     KC_NO,    TOG_MAC,   TOG_WIN,  QK_BOOT,
    KC_LBRC,   KC_4,      KC_5,      KC_6,     KC_RBRC,      KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,  KC_RGUI,
    KC_GRV,    KC_1,      KC_2,      KC_3,     KC_BSLS,      KC_NO,     DT_DOWN,  DT_PRNT,   DT_UP,    KC_NO,
                           KC_DOT,    KC_0,     KC_MINS,      KC_TRNS,   KC_TRNS,  KC_TRNS
  ),

  [_SYM] = LAYOUT_split_3x5_3(
    KC_COLN,   KC_AMPR,   KC_ASTR,   KC_LPRN,  KC_PLUS,      KC_NO,     KC_NO,    TOG_MAC,   TOG_WIN,  QK_BOOT,
    KC_LCBR,   KC_DLR,    KC_PERC,   KC_CIRC,  KC_RCBR,      KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,  KC_RGUI,
    KC_TILD,   KC_EXLM,   KC_AT,     KC_HASH,  KC_PIPE,      KC_NO,     DT_DOWN,  DT_PRNT,   DT_UP,    KC_NO,
                           KC_LPRN,   KC_RPRN,  KC_UNDS,      KC_TRNS,   KC_TRNS,  KC_TRNS
  ),

  [_FUNC] = LAYOUT_split_3x5_3(
    KC_F12,   KC_F7,    KC_F8,      KC_F9,     KC_PSCR,       KC_NO,     KC_NO,    TOG_MAC,   TOG_WIN,  QK_BOOT,
    KC_F11,   KC_F4,    KC_F5,      KC_F6,     KC_SCRL,      KC_NO,     KC_RSFT,   KC_RCTL,   KC_RALT,  KC_RGUI,
    KC_F10,   KC_F1,    KC_F2,      KC_F3,     KC_PAUS,      KC_NO,     DT_DOWN,  DT_PRNT,   DT_UP,    KC_NO,
                         KC_APP,    KC_SPC,     KC_TAB,      KC_TRNS,   KC_TRNS,  KC_TRNS
  )
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

static void print_mod_status(void) {
    uint8_t mod_state = get_mods();

    oled_write_P(PSTR("Mods: "), false);

    oled_write_P(mod_state & MOD_MASK_CTRL ? PSTR("C ") : PSTR("_ "), false);
    oled_write_P(mod_state & MOD_MASK_SHIFT ? PSTR("S ") : PSTR("_ "), false);
    oled_write_P(mod_state & MOD_MASK_ALT ? PSTR("A ") : PSTR("_ "), false);
    oled_write_P(mod_state & MOD_MASK_GUI ? PSTR("G ") : PSTR("_ "), false);
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
        case _NUM:
            oled_write_ln_P(PSTR("Number"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined Layer"), false);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("State: "), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM-LOCK ") : PSTR(""), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS-LOCK ") : PSTR(""), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCROLL-LOCK") : PSTR(""), false);

    print_mod_status();
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
