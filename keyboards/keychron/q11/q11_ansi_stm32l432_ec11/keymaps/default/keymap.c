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
        LAYER_6,
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

//tap dance
typedef enum{
    TD_NONE,
 TD_SINGLE_TAP ,
 TD_SINGLE_HOLD,
 TD_DOUBLE_TAP,
 TD_DOUBLE_HOLD,
// TD_DOUBLE_SINGLE_TAP
}td_state_t;

enum{
    BEAC = 0,
    VF8 =  1,
    TXG  = 2,
    TGF  =  3,
    F1112 = 4,
    T02  = 5,
    T1U  = 6,
    TKO = 7,
    F910 = 8,
    TNP  = 9,
    T9Z  = 10,
    F46  = 11,
    SOME_OTHER_DANCE
};


typedef struct { bool is_press_action;
  td_state_t  state; } td_tap_t;

td_state_t cur_dance (qk_tap_dance_state_t *state){
 if(state -> count == 1){
   if (state -> interrupted || !state -> pressed) return TD_SINGLE_TAP;
     else return TD_SINGLE_HOLD;
 }else  if (state -> count == 2 ){
  if(state -> interrupted) return TD_DOUBLE_TAP;
  else if (state -> pressed) return  TD_DOUBLE_HOLD;
  else return TD_DOUBLE_TAP;
     
 }else if (state->count == 3) {
           if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
           else return TD_DOUBLE_HOLD;
       }
    return 0;
}

static td_tap_t xtap_state = {
 .is_press_action = true,
 .state = TD_NONE
};

void x_finished (qk_tap_dance_state_t *state, void *user_data){
 xtap_state.state = cur_dance(state);
  switch (xtap_state.state){
   case TD_SINGLE_TAP:  register_code16(KC_B); break;
   case TD_SINGLE_HOLD: register_code16(A(KC_LCTL)); break;
   case TD_DOUBLE_TAP:  register_code16(KC_E); break;
      case TD_DOUBLE_HOLD: register_code16(A(KC_LCTL));
//   case TD_DOUBLE_SINGLE_TAP: register_code(KC_E); unregister_code(KC_E); register_code(KC_E);
   case TD_NONE: unregister_code16(KC_LALT);
  }
    xtap_state.state = TD_NONE;
}

// 0 to 2  TD02
void triple_numpad (qk_tap_dance_state_t *state, void *user_data);
void triple_numpad(qk_tap_dance_state_t *state, void *user_data) {
 if (state->count == 2) {
        register_code16(KC_P2);
    } else if(state->count == 3){
        register_code(KC_P3);
    } else {
        register_code(KC_P0);
    }
 if (state->count == 2) {
        unregister_code16(KC_P2);
    } else if(state->count == 3) {
        unregister_code(KC_P3);
    } else {
        unregister_code(KC_P0);
    }
};

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_B);
    unregister_code16(KC_E);
    unregister_code16(A(KC_LCTL));
    unregister_code16(KC_V);
    unregister_code16(KC_X);
    unregister_code16(KC_G);
    unregister_code16(KC_F);
    unregister_code16(KC_F4);
    unregister_code16(KC_F6);
    unregister_code16(KC_F8);
    unregister_code16(KC_F9);
    unregister_code16(KC_F10);
    unregister_code16(KC_F12);
    unregister_code16(KC_F11);
    unregister_code16(KC_P0);
    unregister_code16(KC_P1);
    unregister_code16(KC_P2);
    unregister_code16(KC_P3);
    unregister_code16(KC_U);
    unregister_code16(KC_K);
    unregister_code16(KC_O);
    unregister_code16(KC_9);
    unregister_code16(KC_Z);
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [BEAC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, dance_cln_reset),
    [VF8] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_F8),
    [TXG] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_G),
    [TGF] =   ACTION_TAP_DANCE_DOUBLE(KC_G, KC_F),
    [F1112] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12),
    [T02] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_numpad, dance_cln_reset),
    [T1U]  = ACTION_TAP_DANCE_DOUBLE(KC_P1, KC_U),
    [TKO]  = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_O),
    [F910] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F10),
    [TNP] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_P),
    [T9Z] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_Z),
    [F46] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F6),
    
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
//q11
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_1] = LAYOUT_ansi_91(// NO function keys
        KC_NO,      KC_NO,      KC_NO,         KC_NO,      KC_NO,      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,     KC_NO,      KC_MUTE,
        KC_GRV,     KC_ESC,     KC_1,          KC_2,       KC_3,       KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,               TG(LAYER_5),
        TG(LAYER_2),KC_TAB,     KC_Q,          KC_W,       KC_E,       KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,               TG(LAYER_6),
        TG(LAYER_4),KC_LCTL,    KC_A,          KC_S,       KC_D,       KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,                TG(LAYER_2),
        MO(_FN5),   KC_LSFT,                   KC_Z,       KC_X,       KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,   KC_UP,
        MO(_FN1),   MO(_FN1),   MO(_FN5),      KC_LALT,    KC_LGUI,              KC_SPC,                        KC_RSFT,            MO(_FN1), KC_RCTL,   KC_RGUI,  KC_LEFT,   KC_DOWN,    KC_RGHT),
    
    [LAYER_2] = LAYOUT_ansi_91(
        KC_NO,      KC_NO,      KC_NO,         KC_NO,            KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,     KC_TRNS,
        KC_TRNS,    KC_NO,      KC_9,          KC_Z,             TD(TNP),     TD(F46),    KC_5,       KC_6,       KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,   KC_BSPC,              KC_TRNS,
        TO(LAYER_1),KC_TAB,     G(KC_S),       KC_RBRC,          ALT_T(KC_F1),CTL_T(KC_R),TD(T1U),    KC_Y,       KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC,  KC_BSLS,              KC_TRNS,
        MO(_FN5),   MO(_FN1),   KC_LBRC ,      TD(TXG),          KC_WH_U,     TD(BEAC),   KC_ESC,     KC_H,       KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,               TG(LAYER_3),
        MO(_FN5),   SFT_T(KC_M),               TD(F910),         TD(F1112),   TD(TKO),    TD(VF8),    TD(T02),    KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,   KC_UP,
        KC_LCTL,    MO(_FN2),   MO(_FN5),      ALT_T(KC_SLSH),   GUI_T(KC_L),             KC_SPC,                          KC_TRNS,            KC_TRNS,  KC_TRNS, KC_TRNS,  KC_LEFT,   KC_DOWN,    KC_RGHT),

    [LAYER_3] = LAYOUT_ansi_91(
        KC_TRNS,    KC_TRNS,          KC_F1,      KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_ESC,           KC_1,       KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,   KC_BSPC,               KC_TRNS,
        TO(LAYER_1),KC_TAB,           KC_Q,       KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC,  KC_BSLS,               KC_TRNS,
        G(KC_I),    CTL_T(KC_K),      KC_A,       KC_S,     KC_D,     TD(TGF),  KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,                TG(LAYER_4),
        A(KC_H),    SFT_T(KC_Y),                  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,   KC_UP,
        MO(_FN1),   MO(_FN3),XXXXXXX,LALT_T(KC_N),GUI_T(KC_L),                  KC_GRV,                        KC_SPC,             KC_TRNS,  KC_TRNS, KC_TRNS,  KC_LEFT,   KC_DOWN,    KC_RGHT),
    
    [LAYER_4] = LAYOUT_ansi_91( // hacchan
        KC_NO,      KC_NO,      KC_NO,         KC_NO,            KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,     KC_TRNS,
        KC_TRNS,    XXXXXXX,    KC_1,          KC_2,             KC_3,        KC_4,       KC_5,       KC_6,       KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,   KC_BSPC,              KC_TRNS,
        TO(LAYER_1),KC_TAB,     XXXXXXX,       XXXXXXX,          ALT_T(KC_F1),KC_R,       KC_T,       KC_Y,       KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC,  KC_BSLS,              KC_TRNS,
        KC_NO,      MO(_FN5),   KC_X,          KC_G,             KC_WH_U,     TD(BEAC),   KC_NO,      KC_H,       KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,               TG(LAYER_5),
        KC_NO,      SFT_T(KC_M),               KC_Z,             KC_X,        KC_C,       KC_V,       KC_B,       KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,   KC_UP,
        KC_LCTL,    MO(_FN4),   MO(_FN5),      ALT_T(KC_SLSH),   GUI_T(KC_L),             KC_SPC,                          KC_TRNS,            KC_TRNS,  KC_TRNS, KC_TRNS,  KC_LEFT,   KC_DOWN,    KC_RGHT),

    [LAYER_5] = LAYOUT_ansi_91(// enable function key, right shift
        KC_NO,      KC_TILD,    KC_F1,         KC_F2,      KC_F3,      KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_F13,    KC_F14,     KC_F15,
        KC_GRV,     KC_ESC,     KC_1,          KC_2,       KC_3,       KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,               TO(LAYER_1),
        TO(LAYER_1),KC_TAB,     KC_Q,          KC_W,       KC_E,       KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,               KC_TRNS,
        KC_TRNS,    KC_LCTL,    KC_A,          KC_S,       KC_D,       KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,                TG(LAYER_6),
        KC_TRNS,    KC_LSFT,                   KC_Z,       KC_X,       KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,   KC_UP,
        MO(_FN1),   MO(_FN1),   XXXXXXX,       KC_LALT,    KC_LGUI,              KC_SPC,                        KC_RSFT,            MO(_FN1), KC_RCTL,   KC_RGUI,  KC_LEFT,   KC_DOWN,    KC_RGHT),
    [LAYER_6] = LAYOUT_ansi_91( // temporally disable keyboard
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            TO(LAYER_1),
        TO(LAYER_1),XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            TO(LAYER_1),
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            TO(LAYER_1),
        XXXXXXX,    XXXXXXX,                XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,             XXXXXXX,                          XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    
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
        XXXXXXX,   TO(LAYER_1),XXXXXXX,   G(C(KC_F)),SGUI(KC_I),KC_F15,    KC_F16,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
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
        XXXXXXX,    TO(LAYER_1),XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_WH_D,  C(KC_Z),   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        XXXXXXX,    KC_H,                   XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,             XXXXXXX,                          XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [_FN5] = LAYOUT_ansi_91( // hacchan,  arrow keys
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,    KC_F4,     KC_F5,      KC_F6,     KC_F7,      KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   SGUI(KC_4),         XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UP,      XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RGHT,  C(KC_Y),   TO(LAYER_1),XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        XXXXXXX,    KC_H,                   XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,             XXXXXXX,                           XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
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
    [LAYER_5] = {ENCODER_CCW_CW(TG(LAYER_6), TG(LAYER_6)),        ENCODER_CCW_CW(TG(LAYER_6), TG(LAYER_6))},
    [LAYER_6] = {ENCODER_CCW_CW(TO(LAYER_1), TO(LAYER_1)),        ENCODER_CCW_CW(TO(LAYER_1), TO(LAYER_1))},
    
    [_FN1] =    {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN2] =    {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN3] =    {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN4] =    {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN5] =    {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
//    [_FN6] =    {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}

};
#endif // ENCODER_MAP_ENABLE


//LEADER KEY setting
/*
void leader_start_user(void) {
}

void leader_end_user(void) {
    if(leader_sequence_one_key(KC_ESC)) {
        //100% opacity
        tap_code16(KC_V);
        tap_code16(KC_0);
        
    } else if (leader_sequence_two_keys(KC_ESC, KC_ESC)) {
        // 10% opacity
        tap_code16(KC_V);
        tap_code16(KC_1);
        
    }
};
*/
