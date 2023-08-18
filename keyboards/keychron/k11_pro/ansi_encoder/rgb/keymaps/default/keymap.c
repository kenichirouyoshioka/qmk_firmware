/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

enum layers{
    LAYER_1,
    LAYER_2,
    LAYER_3,
    LAYER_4,
    LAYER_5,
    
    _BT,
    _FN1,
    _FN2,
    _FN3,
    _FN4,

    _FN6,
    _FN7

};


#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case LAYER_1:
                    rgb_matrix_set_color_all(66,0,0);
                break;
                
            case LAYER_2:
                    rgb_matrix_set_color_all(86,66,66);
                break;
                
            case LAYER_3:
                     rgb_matrix_set_color_all(0,0,66);
                break;
            case LAYER_4:
                     rgb_matrix_set_color_all(66,66,0);
                break;

            case _BT:
                rgb_matrix_set_color_all(88,66,255);
                break;
            case _FN1:
                    rgb_matrix_set_color_all(66,0,55);
                break;
                
            case _FN2:
                    rgb_matrix_set_color_all(66,66,0);
                break;
                
            case _FN3:
                    rgb_matrix_set_color_all(0,66,44);
                break;
                
            case _FN4:
                    rgb_matrix_set_color_all(0,66,0);
                break;
        }
    return false;
}
#endif // RGB_MATRIX_ENABLE

/*LEADER KEY setting */
LEADER_EXTERNS();
void matrix_scan_user(void) {
    
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        
        SEQ_ONE_KEY(KC_ESC){
            register_code(KC_V);
            unregister_code(KC_V);
            register_code(KC_0);
            unregister_code(KC_0);
        }
        SEQ_TWO_KEYS(KC_ESC, KC_ESC) {
            register_code(KC_V);
            unregister_code(KC_V);
            register_code(KC_1);
            unregister_code(KC_1);
        }
        
        SEQ_ONE_KEY(KC_R){
            register_code16(G(KC_S));
            unregister_code16(G(KC_S));
           register_code16(LAG(KC_W));
          unregister_code16(LAG(KC_W));
            register_code(KC_ENT);
          unregister_code(KC_ENT);
        }
        
    };
};


    //tap dance
    enum{
        TD_VU  =  0,
        TD_XZ  =  1,
        TD_KO  =  2,
        TD_F679 = 3,
        TD_MG =   4,
        TD_LNG =  5,
        TD_GF =   6,
        TD_F15F = 7,
        TD_F134 = 8,
        TD_SLH  = 9,
        TD_F1112 = 10,
        TD_BEA =  11, SOME_OTHER_DANCE
    };


void triple_function (qk_tap_dance_state_t *state, void *user_data);
void triple_function (qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        register_code16(KC_F6);
    } else if(state->count == 2){
        register_code16(KC_F7);
    } else {
        register_code16(KC_F9);
    }
    
    if (state->count == 2) {
        unregister_code16(KC_F6);
    } else if(state->count == 3) {
        unregister_code16(KC_F7);
    } else {
        unregister_code16(KC_F9);

    }
};

typedef enum{
    TD_NONE,
 TD_SINGLE_TAP ,
 TD_SINGLE_HOLD,
 TD_DOUBLE_TAP,
 TD_DOUBLE_HOLD,
// TD_DOUBLE_SINGLE_TAP

}td_state_t;

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


void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_B);
    unregister_code16(KC_E);
    unregister_code16(A(KC_LCTL));
    unregister_code16(KC_F6);
    unregister_code16(KC_F7);
    unregister_code16(KC_F9);
    unregister_code16(KC_G);
    unregister_code16(KC_M);
    unregister_code16(KC_T);
    unregister_code16(KC_D);
    unregister_code16(KC_LNG1);
    unregister_code16(KC_LNG2);
    unregister_code16(KC_K);
    unregister_code16(KC_O);
    unregister_code16(KC_U);
    unregister_code16(KC_V);
    unregister_code16(KC_F);
    unregister_code16(KC_F13);
    unregister_code16(KC_F14);
    unregister_code16(KC_F15);
    unregister_code16(KC_H);
    unregister_code16(KC_SLSH);
    unregister_code16(KC_F11);
    unregister_code16(KC_F12);
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LNG] = ACTION_TAP_DANCE_DOUBLE(KC_LNG2, KC_LNG1),
    [TD_VU] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_U),
    [TD_XZ] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_Z),
    [TD_KO] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_O),
    [TD_BEA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, dance_cln_reset),
    [TD_F679] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_function, dance_cln_reset),
    [TD_MG] =   ACTION_TAP_DANCE_DOUBLE(KC_M, KC_G),
    [TD_GF] =   ACTION_TAP_DANCE_DOUBLE(KC_G, KC_F),
    [TD_F15F] = ACTION_TAP_DANCE_DOUBLE(KC_F15, KC_F),
    [TD_F134] = ACTION_TAP_DANCE_DOUBLE(KC_F13, KC_F14),
    [TD_SLH]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_H),
    [TD_F1112] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12)
};



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPTN, KC_LCMMD,          KC_SPC,           MO(MAC_FN1), MO(FN2),       KC_SPC,            KC_RCMMD,           KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           MO(WIN_FN1), MO(FN2),       KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, _______, _______, _______,  _______, _______, _______, KC_INS,   KC_PGUP,  _______,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,           _______, _______, _______, KC_SNAP,  KC_PGDN,  KC_END,   _______,          _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [WIN_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, _______, _______, _______,  _______, KC_APP,  KC_SCRL, KC_INS,   KC_PGUP,  _______,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,           _______, _______, _______, KC_PSCR,  KC_PGDN,  KC_END,   _______,          _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [FN2] = LAYOUT_69_ansi(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, BAT_LVL,  BAT_LVL, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LAYER_1] = {ENCODER_CCW_CW(TG(LAYER_2), TG(LAYER_2))},
    [LAYER_2] = {ENCODER_CCW_CW(TG(LAYER_3), TG(LAYER_3))},
    [LAYER_3] = {ENCODER_CCW_CW(TO(LAYER_1),TO(LAYER_1))},
    [LAYER_4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_5] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    
    [_FN1] = {ENCODER_CCW_CW(G(KC_Z), SGUI(KC_Z))},
    [_FN2] = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)},
    [_FN3] = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)},
    [_FN4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},

    [_FN6]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN7]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE
