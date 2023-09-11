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
//k2pro
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

    _FN5

};


#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case LAYER_1:
                    rgb_matrix_set_color_all(255,0,0);
                break;
                
            case LAYER_2:
                    rgb_matrix_set_color_all(255,166,166);
                break;
                
            case LAYER_3:
                     rgb_matrix_set_color_all(0,0,255);
                break;
            case LAYER_5:
                     rgb_matrix_set_color_all(0,255,255);
                break;

            case _BT:
                rgb_matrix_set_color_all(88,66,255);
                break;
            case _FN1:
                    rgb_matrix_set_color_all(166,0,155);
                break;
                
            case _FN2:
                    rgb_matrix_set_color_all(166,166,0);
                break;
                
            case _FN3:
                    rgb_matrix_set_color_all(0,166,144);
                break;
                
            case _FN4:
                    rgb_matrix_set_color_all(0,255,0);
                break;
        }
    return false;
}
#endif // RGB_MATRIX_ENABLE

/*LEADER KEY setting */
void leader_start_user(void) {
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_R)) {
        // just save
        tap_code16(LGUI(KC_S));
        
    }else if(leader_sequence_one_key(KC_ESC)) {
        //100% opacity
        tap_code16(KC_V);
        tap_code16(KC_0);
        
    } else if (leader_sequence_two_keys(KC_ESC, KC_ESC)) {
        // 10% opacity
        tap_code16(KC_V);
        tap_code16(KC_1);
        
    } else if (leader_sequence_three_keys(KC_R, KC_R, KC_R)) {
        //screen lock
        tap_code16(G(C(KC_Q)));
        
    } else if (leader_sequence_two_keys(KC_R, KC_R)) {
        // save and close all windows
        tap_code16(LGUI(KC_S));
        tap_code16(LAG(KC_W));
        tap_code16(KC_ENT);

        // function keys
    }else if (leader_sequence_one_key(KC_1)) {
        tap_code16(KC_F1);
    }else if (leader_sequence_one_key(KC_2)) {
        tap_code16(KC_F2);
    }else if (leader_sequence_one_key(KC_3)) {
        tap_code16(KC_F3);
    }else if (leader_sequence_one_key(KC_4)) {
        tap_code16(KC_F4);
    }else if (leader_sequence_one_key(KC_5)) {
        tap_code16(KC_F5);
    }else if (leader_sequence_one_key(KC_6)) {
        tap_code16(KC_F6);
    }else if (leader_sequence_one_key(KC_7)) {
        tap_code16(KC_F7);
    }else if (leader_sequence_one_key(KC_8)) {
        tap_code16(KC_F8);
    }else if (leader_sequence_one_key(KC_9)) {
        tap_code16(KC_F9);
    }else if (leader_sequence_one_key(KC_0)) {
        tap_code16(KC_F10);
    }else if (leader_sequence_one_key(KC_MINS)){
        tap_code16(KC_F11);
    }else if (leader_sequence_one_key(KC_EQL)) {
        tap_code16(KC_F12);
        //input "
    }else if (leader_sequence_one_key(KC_QUOT)) {
        tap_code16(S(KC_QUOT));
        //input :
    }else if (leader_sequence_one_key(KC_SCLN)) {
        tap_code16(S(KC_SCLN));
        //input  ( ) -
    }else if (leader_sequence_one_key(KC_H)) {
        tap_code16(S(KC_9));
    }else if (leader_sequence_one_key(KC_J)) {
        tap_code16(S(KC_0));
    }else if (leader_sequence_one_key(KC_K)) {
        tap_code16(KC_MINS);
        //input !
    }else if (leader_sequence_one_key(KC_N)) {
        tap_code16(S(KC_1));
        // home, end, page up and down
    }else if (leader_sequence_one_key(KC_M)) {
        tap_code16(KC_END);
    }else if (leader_sequence_one_key(KC_COMM)) {
        tap_code16(KC_PGDN);
    }else if (leader_sequence_one_key(KC_DOT)) {
        tap_code16(KC_PGUP);
    }else if (leader_sequence_one_key(KC_SLSH)) {
        tap_code16(KC_HOME);
        // copy and paste
    }else if (leader_sequence_one_key(KC_C)) {
        tap_code16(G(KC_C));
    }else if (leader_sequence_one_key(KC_V)) {
        tap_code16(G(KC_V));

        //numpad 0 to 9
    }else if (leader_sequence_one_key(KC_P0)) {
        tap_code16(KC_P1);
    }else if (leader_sequence_two_keys(KC_P0, KC_P0)) {
        tap_code16(KC_P2);
    }else if (leader_sequence_three_keys(KC_P0, KC_P0, KC_P0)) {
        tap_code16(KC_P3);
        
    }else if (leader_sequence_one_key(KC_P4)) {
        tap_code16(KC_P5);
    }else if (leader_sequence_one_key(KC_P6)) {
        tap_code16(KC_P7);
    }else if (leader_sequence_one_key(KC_P8)) {
        tap_code16(KC_P9);
    }
}

    //tap dance
    enum{
        TD_VL  =  0,
        TD_XZ  =  1,
        TD_KO  =  2,

        TD_MG =   3,
 
        TD_GF =   4,
 

        TD_SLH  = 5,
        TD_F1112 = 6,
        TD_BEA =  7, SOME_OTHER_DANCE
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



td_state_t cur_dance (tap_dance_state_t *state){
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

void x_finished (tap_dance_state_t *state, void *user_data){
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


void dance_cln_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_B);
    unregister_code16(KC_E);
    unregister_code16(A(KC_LCTL));

    unregister_code16(KC_G);
    unregister_code16(KC_M);
    unregister_code16(KC_T);
    unregister_code16(KC_D);

    unregister_code16(KC_K);
    unregister_code16(KC_O);
    unregister_code16(KC_L);
    unregister_code16(KC_V);
    unregister_code16(KC_F);

    unregister_code16(KC_H);
    unregister_code16(KC_SLSH);
    unregister_code16(KC_F11);
    unregister_code16(KC_F12);
};

tap_dance_action_t tap_dance_actions[] = {

    [TD_VL] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_L),
    [TD_XZ] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_Z),
    [TD_KO] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_O),
    [TD_BEA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, dance_cln_reset),

    [TD_MG] =   ACTION_TAP_DANCE_DOUBLE(KC_M, KC_G),
    [TD_GF] =   ACTION_TAP_DANCE_DOUBLE(KC_G, KC_F),
 

    [TD_SLH]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_H),
    [TD_F1112] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12)
};

//k2pro
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_1] = LAYOUT_ansi_84(
      G(C(KC_Q)), KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_F13,     KC_F14,  MO(_BT),
      KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,             KC_MUTE,
      KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,             KC_VOLU,
      KC_LCTL,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,              KC_VOLD,
      KC_LSFT,              KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,    KC_UP,   TG(LAYER_5),
      MO(_FN1),   KC_LALT,  KC_LGUI,                                KC_SPC,                                 MO(_FN1), QK_LEAD,  KC_RCTL,   KC_LEFT,    KC_DOWN, KC_RGHT),

[LAYER_2] = LAYOUT_ansi_84(
      KC_TRNS,    KC_COMM,    KC_DOT,     KC_F3,       KC_F4,     KC_F5,    KC_F6,      KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_TRNS,  KC_TRNS,  KC_TRNS,
      G(KC_Q),    KC_LSFT,    KC_LBRC,    KC_RBRC,     KC_P4,     KC_P6,    KC_P8,      KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,            KC_TRNS,
      KC_TAB,     G(KC_J),    TD(TD_MG),  ALT_T(KC_F1),KC_R,      TD(TD_KO),KC_F13,     KC_F14,   KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_TRNS,
      MO(_FN1),   QK_LEAD,    TD(TD_XZ),  KC_WH_U,     TD(TD_BEA),KC_ESC,   KC_F,       KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_PENT,            KC_TRNS,
      KC_LSFT,                MO(_FN4),   TD(TD_F1112),TD(TD_SLH),TD(TD_VL),KC_P0,      KC_F15,   KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,  KC_UP,    XXXXXXX,
      MO(_FN2),   KC_LALT,    MT(MOD_LGUI,KC_L),                            KC_SPC,                                   MO(_FN4), MO(_FN2), MO(_FN1),  KC_LEFT,  KC_DOWN,  KC_RGHT),

[LAYER_3] = LAYOUT_ansi_84(
      KC_TRNS,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_TRNS,   KC_TRNS,    KC_TRNS,
      KC_ESC,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,               KC_TRNS,
      KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,               KC_TRNS,
 MT(MOD_LCTL,KC_K),KC_A,     KC_S,     KC_D,     TD(TD_GF),KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,                KC_TRNS,
 MT(MOD_LSFT,KC_Y),          KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,   KC_UP,      XXXXXXX,
      MO(_FN3), MT(MOD_LALT,KC_N), MT(MOD_LGUI,KC_L),                KC_GRV,                                 MO(_FN4), MO(_FN2), MO(_FN1),  KC_LEFT,   KC_DOWN,    KC_RGHT),

[LAYER_4] = LAYOUT_ansi_84(
      KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,   RGB_MOD,  MO(_BT),
      KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
      KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
      KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
      KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_LGUI, MO(_FN1),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
//colemak
[LAYER_5] = LAYOUT_ansi_84(
      KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,   KC_TRNS,  MO(_BT),
      KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_TRNS,
      KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_TRNS,
      KC_LCTL,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,            KC_ENT,             KC_TRNS,
      KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    TO(LAYER_1),
      MO(_FN1), KC_LALT,  KC_LGUI,                                KC_SPC,                                 MO(_FN4), MO(_FN2),  MO(_FN1),KC_LEFT,  KC_DOWN,  KC_RGHT),

    
    
[_BT] = LAYOUT_ansi_84(
      XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  BT_HST1,   BT_HST2,  BT_HST3,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            BT_HST1,
      XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            BT_HST2,
      XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,            BT_HST3,
      XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,   XXXXXXX,                                XXXXXXX,                                 XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
                          
[_FN1] = LAYOUT_ansi_84(
      KC_PDOT,    KC_P1,      KC_P2,    KC_P3,    KC_P4,     KC_P5,     KC_P6,      KC_P7,     KC_P8,    KC_P9,     KC_P0,    KC_PMNS,  KC_PPLS,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      KC_TILD,    KC_F1,      KC_F2,    KC_F3,    KC_F4,     KC_F5,     KC_F6,      KC_F7,     KC_F8,    KC_F9,     KC_F10,   KC_F11,   KC_F12,   XXXXXXX,            XXXXXXX,
      TG(LAYER_2),TG(LAYER_3),G(KC_W),  G(KC_E),  G(KC_R),   G(KC_T),   XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,   G(KC_P),  XXXXXXX,  XXXXXXX,  SGUI(KC_4),         XXXXXXX,
      XXXXXXX,    G(KC_K),    G(KC_S),  G(KC_D),  SGUI(KC_Z),G(KC_G),   KC_LEFT,    KC_DOWN,   KC_UP,    KC_RGHT,   XXXXXXX,  XXXXXXX,            KC_PENT,            XXXXXXX,
      XXXXXXX,                G(KC_Z),  G(KC_J),  G(KC_N),   G(KC_COMM),XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_VOLU,  XXXXXXX,
      XXXXXXX,    G(KC_MINS), G(KC_EQL),                                KC_BSPC,                                    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_MPLY),

[_FN2] = LAYOUT_ansi_84(
      XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      KC_P,       XXXXXXX,  G(KC_LBRC),G(KC_RBRC),XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      TO(LAYER_1),XXXXXXX,  G(C(KC_F)),SGUI(KC_I),G(KC_COMM),XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      KC_PENT,    XXXXXXX,  G(KC_1),   KC_WH_D,   G(KC_Z),   KC_U,      XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
      XXXXXXX,              XXXXXXX,   XXXXXXX,   KC_P,      KC_F8,     G(KC_0), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,    XXXXXXX,  XXXXXXX,                                    XXXXXXX,                               XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

[_FN3] = LAYOUT_ansi_84(
      XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
      KC_P,     XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,
      KC_M,     TO(LAYER_1),C(KC_P8), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,
      KC_ENT,   C(KC_P4),   C(KC_P2), C(KC_P6), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,             XXXXXXX,
      KC_H,                 A(KC_H),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,   XXXXXXX,
      XXXXXXX,  XXXXXXX,    XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX),
                          
[_FN4] = LAYOUT_ansi_84(
      XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,
      KC_GRV,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,              XXXXXXX,
      XXXXXXX,    KC_F13,   KC_F14,   KC_F15,   KC_F16,    XXXXXXX,  G(C(KC_Q)),LAG(KC_GRV),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,              XXXXXXX,
      KC_LCTL,    XXXXXXX,  KC_F12,   KC_WH_D,  SGUI(KC_Z),KC_F11,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,              XXXXXXX,
      KC_LSFT,              XXXXXXX,  KC_LCTL,  KC_F9,     KC_F8,    KC_F7,     XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  XXXXXXX,    XXXXXXX,
      XXXXXXX,    XXXXXXX,  XXXXXXX,                                 KC_LGUI,                                   XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX),
                          
[_FN5] = LAYOUT_ansi_84(
      KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TRNS,  KC_TRNS,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  RGB_TOG,
      KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
      RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
      KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
      KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};
