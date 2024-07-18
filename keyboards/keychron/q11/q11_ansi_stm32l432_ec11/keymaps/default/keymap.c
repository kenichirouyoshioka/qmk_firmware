/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

// clang-format off
//q11
enum layers{
        LAYER_1,
        LAYER_2,
        LAYER_3,
        LAYER_4,
        LAYER_5,

        _FN1,
        _FN2,
        _FN3,
       _FN4,
       _FN5

    };


    #ifdef RGB_MATRIX_ENABLE
    bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
            switch (get_highest_layer(layer_state | default_layer_state)) {
                case LAYER_1:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(255,0,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 255,0,0);
                        //rgb_matrix_set_color(0,  255,0,0);
                    }else{
                        // right
                        rgb_matrix_set_color_all(255,0,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 255,0,0);
                    }
                    break;
                    
                case LAYER_2:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(255,166,156);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 188,166,166);
                        //rgb_matrix_set_color(0,  188,166,166);
                    }else{
                        // right
                        rgb_matrix_set_color_all(255,166,156);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 188,166,166);
                    }
                    break;
                    
                case LAYER_3:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(0,66,255);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 0,0,188);
                        //rgb_matrix_set_color(0,  0,0,255);
                    }else{
                        // right
                        rgb_matrix_set_color_all(0,66,255);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 0,0,188);
                         
                    }
                    break;

                case LAYER_4:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(0,255,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 220,200,0);
                        //rgb_matrix_set_color(0,  255,255,0);
                    }else{
                        // right
                        rgb_matrix_set_color_all(0,255,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 220,200,0);
                    }
                    break;
                    
                case LAYER_5:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(255,66,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 0,255,0);
                        //rgb_matrix_set_color(0,  0,255,0);
                    }else{
                        // right
                        rgb_matrix_set_color_all(255,66,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 0,255,0);
                    }
                    break;
 

                    
                case _FN1:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(222,0,155);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 177,0,166);
                        //rgb_matrix_set_color(0,  177,0,166);
                    }else{
                        // right
                        rgb_matrix_set_color_all(222,0,155);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 177,0,166);
                    }
                    break;
                    
                case _FN2:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(255,66,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 220,200,0);
                        //rgb_matrix_set_color(0,  255,255,0);
                    }else{
                        // right
                        rgb_matrix_set_color_all(255,66,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 220,200,0);
                    }
                    break;
                    
                case _FN3:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(0,188,144);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 0,177,155);
                        //rgb_matrix_set_color(0,  0,177,255);
                    }else{
                        // right
                        rgb_matrix_set_color_all(0,188,144);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 0,177,155);
                    }
                    break;
    
                case _FN4:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(255,66,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 220,200,0);
                        //rgb_matrix_set_color(0,  255,255,0);
                    }else{
                        // right
                        rgb_matrix_set_color_all(255,66,0);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 220,200,0);
                    }
                    break;
                case _FN5:
                    if (is_keyboard_left()) {
                        rgb_matrix_set_color_all(0,66,155);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(23, 177,0,166);
                        //rgb_matrix_set_color(0,  177,0,166);
                    }else{
                        // right
                        rgb_matrix_set_color_all(0,66,155);
                        // windowed keycap setting
                        //rgb_matrix_set_color_all(0,0,0);
                        //rgb_matrix_set_color(49, 177,0,166);
                    }
                    break;
   
                default:
                    break;
            }
        return false;
    }
    #endif // RGB_MATRIX_ENABLE





#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
//q11
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_1] = LAYOUT_ansi_91(// NO function keys
        KC_NO,      KC_NO,      KC_NO,         KC_NO,      KC_NO,      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,     KC_NO,      KC_NO,
        KC_GRV,     KC_ESC,     KC_1,          KC_2,       KC_3,       KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,               KC_MUTE,
        TG(LAYER_2),KC_TAB,     KC_Q,          KC_W,       KC_E,       KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,               KC_VOLU,
        KC_PGUP,    KC_LCTL,    KC_A,          KC_S,       KC_D,       KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,                KC_VOLD,
        KC_PGDN,    KC_LSFT,                   KC_Z,       KC_X,       KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,   KC_UP,
        MO(_FN1),   MO(_FN1),   MO(_FN5),      KC_LALT,    KC_LGUI,              KC_SPC,                        KC_RSFT,            MO(_FN1), KC_RCTL,   KC_RGUI,  KC_LEFT,   KC_DOWN,    KC_RGHT),
    
    [LAYER_2] = LAYOUT_ansi_91(
        KC_NO,      KC_NO,      KC_NO,         KC_NO,            KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,     KC_NO,
        KC_TRNS,    KC_F10,     KC_N,          KC_Z,             KC_P,        KC_4,       KC_5,       KC_6,       KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,   KC_BSPC,              KC_TRNS,
        TO(LAYER_1),KC_TAB,     KC_LBRC,       KC_RBRC,          ALT_T(KC_F1),CTL_T(KC_R),KC_1,       KC_Y,       KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC,  KC_BSLS,              KC_TRNS,
        G(KC_RBRC), MO(_FN1),   QK_LEAD,       KC_X,             KC_WH_U,     KC_B,       KC_ESC,     KC_H,       KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,               KC_TRNS,
        G(KC_LBRC), SFT_T(KC_M),               KC_F9,            KC_F11,      KC_K,       KC_V,       KC_E,       KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,   KC_UP,
        KC_LCTL,    MO(_FN2),   MO(_FN5),      ALT_T(KC_SLSH),   GUI_T(KC_L),             KC_SPC,                          KC_TRNS,            KC_TRNS,  KC_TRNS, KC_TRNS,  KC_LEFT,   KC_DOWN,    KC_RGHT),

    [LAYER_3] = LAYOUT_ansi_91(
        KC_TRNS,    KC_TRNS,          KC_F1,      KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_ESC,           KC_1,       KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,   KC_BSPC,               KC_TRNS,
        TO(LAYER_1),KC_TAB,           KC_Q,       KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC,  KC_BSLS,               KC_TRNS,
        G(KC_I),    CTL_T(KC_K),      KC_A,       KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,                KC_TRNS,
        A(KC_H),    SFT_T(KC_Y),                  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,   KC_UP,
        MO(_FN1),   MO(_FN3),XXXXXXX,LALT_T(KC_N),GUI_T(KC_L),                  KC_GRV,                        KC_SPC,             KC_TRNS,  KC_TRNS, KC_TRNS,  KC_LEFT,   KC_DOWN,    KC_RGHT),
    
    [LAYER_4] = LAYOUT_ansi_91( // hacchan
        KC_NO,      KC_NO,      KC_NO,         KC_NO,            KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,     KC_NO,
        KC_TRNS,    XXXXXXX,    XXXXXXX,       KC_NO,            KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,   KC_BSPC,              KC_TRNS,
        TO(LAYER_1),KC_TAB,     KC_LBRC,       KC_RBRC,          ALT_T(KC_F1),CTL_T(KC_R),KC_T,       KC_Y,       KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC,  KC_BSLS,              KC_TRNS,
        G(KC_RBRC), MO(_FN5),   KC_X,          KC_G,             KC_WH_U,     KC_B,       KC_ESC,     KC_H,       KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,               KC_TRNS,
        G(KC_LBRC), SFT_T(KC_M),               XXXXXXX,          XXXXXXX,     KC_H,       KC_V,       KC_E,       KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,   KC_UP,
        KC_LCTL,    MO(_FN4),   MO(_FN5),      ALT_T(KC_SLSH),   GUI_T(KC_L),             KC_SPC,                          KC_TRNS,            KC_TRNS,  KC_TRNS, KC_TRNS,  KC_LEFT,   KC_DOWN,    KC_RGHT),

    [LAYER_5] = LAYOUT_ansi_91(// enable function key, right shift
        KC_NO,      KC_TILD,    KC_F1,         KC_F2,      KC_F3,      KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_F13,    KC_F14,     KC_F15,
        KC_GRV,     KC_ESC,     KC_1,          KC_2,       KC_3,       KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,               KC_MUTE,
        TO(LAYER_1),KC_TAB,     KC_Q,          KC_W,       KC_E,       KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,               KC_VOLU,
        KC_TRNS,    KC_LCTL,    KC_A,          KC_S,       KC_D,       KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,                KC_VOLD,
        KC_TRNS,    KC_LSFT,                   KC_Z,       KC_X,       KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,   KC_UP,
        MO(_FN1),   MO(_FN1),   XXXXXXX,       KC_LALT,    KC_LGUI,              KC_SPC,                        KC_RSFT,            MO(_FN1), KC_RCTL,   KC_RGUI,  KC_LEFT,   KC_DOWN,    KC_RGHT),


    
    [_FN1] = LAYOUT_ansi_91(
        XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,   KC_TILD,     KC_F1,      KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,      KC_F7,     KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   SGUI(KC_4),         XXXXXXX,
        XXXXXXX,   TG(LAYER_2), XXXXXXX,    G(KC_N),   G(KC_E),   G(KC_COMM),G(KC_T),   XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        KC_HOME,   XXXXXXX,     G(KC_K),    G(KC_S),   G(KC_D),   SGUI(KC_Z),G(KC_G),   KC_LEFT,    KC_DOWN,   KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,              KC_PENT,            XXXXXXX,
        KC_END,    XXXXXXX,                 XXXXXXX,   XXXXXXX,   G(KC_J),   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  KC_VOLU,
        XXXXXXX,   XXXXXXX,     XXXXXXX,    G(KC_MINS),G(KC_EQL),            KC_BSPC,                          XXXXXXX,            XXXXXXX,  KC_RCTL,    KC_RGUI,  KC_MUTE,  KC_VOLD,  KC_MPLY),
    
    [_FN2] = LAYOUT_ansi_91(
        XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   KC_NO,      XXXXXXX,   G(C(KC_F)),SGUI(KC_I),KC_F15,    KC_F16,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   KC_PENT,    XXXXXXX,   KC_F7,     KC_WH_D,   G(KC_Z),   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        XXXXXXX,   KC_H,                  XXXXXXX,   XXXXXXX,   KC_F13,    KC_F14,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,
        XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,              KC_F,                          XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
    
    [_FN3] = LAYOUT_ansi_91(
        XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  KC_P,     KC_P1,      KC_P2,    KC_P3,       KC_P4,    KC_P5,     KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0,    XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  KC_M,     XXXXXXX,    XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  KC_ENT,   XXXXXXX,    KC_SLSH,  TO(LAYER_1), XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        A(KC_H),  KC_H,                 XXXXXXX,  XXXXXXX,     KC_PDOT,  KC_HOME,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,               KC_SPC,                        XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [_FN4] = LAYOUT_ansi_91( // hacchan
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_WH_D,  C(KC_Z),   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        XXXXXXX,    KC_H,                   XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,             XXXXXXX,                          XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [_FN5] = LAYOUT_ansi_91( // hacchan,  arrow keys
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UP,      XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RGHT,  C(KC_Y),   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        XXXXXXX,    KC_H,                   XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,             XXXXXXX,                          XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),    
/*
    [_FN6] = LAYOUT_ansi_91(
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
*/
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LAYER_1] = {ENCODER_CCW_CW(TG(LAYER_2), TG(LAYER_2)),        ENCODER_CCW_CW(TG(LAYER_2), TG(LAYER_2))},
    [LAYER_2] = {ENCODER_CCW_CW(TG(LAYER_3), TG(LAYER_3)),        ENCODER_CCW_CW(TG(LAYER_3), TG(LAYER_3))},
    [LAYER_3] = {ENCODER_CCW_CW(TG(LAYER_4), TG(LAYER_4)),        ENCODER_CCW_CW(TG(LAYER_4), TG(LAYER_4))},
    [LAYER_4] = {ENCODER_CCW_CW(TG(LAYER_5), TG(LAYER_5)),        ENCODER_CCW_CW(TG(LAYER_5), TG(LAYER_5))},
    [LAYER_5] = {ENCODER_CCW_CW(TO(LAYER_1), TO(LAYER_1)),        ENCODER_CCW_CW(TO(LAYER_1), TO(LAYER_1)) },

    
    [_FN1] =    {ENCODER_CCW_CW(G(KC_Z), SGUI(KC_Z)),    ENCODER_CCW_CW(G(KC_Z), SGUI(KC_Z))},
    [_FN2] =    {ENCODER_CCW_CW(KC_LBRC, KC_RBRC),       ENCODER_CCW_CW(S(KC_LBRC), S(KC_RBRC))},
    [_FN3] =    {ENCODER_CCW_CW(C(KC_P2), C(KC_P8)),     ENCODER_CCW_CW(C(KC_P4), C(KC_P6))},
    [_FN4] =    {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN5] =    {ENCODER_CCW_CW(RGB_VAD, RGB_VAI),       ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
//    [_FN6] =    {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}

};
#endif // ENCODER_MAP_ENABLE
