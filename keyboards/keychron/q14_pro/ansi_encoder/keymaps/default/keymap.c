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
//q14pro
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

        // function keys, home, end, pgdn and pgup, copy and paste
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
        TD_VU  =  0,
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
    unregister_code16(KC_U);
    unregister_code16(KC_V);
    unregister_code16(KC_F);

    unregister_code16(KC_H);
    unregister_code16(KC_SLSH);
    unregister_code16(KC_F11);
    unregister_code16(KC_F12);
};

tap_dance_action_t tap_dance_actions[] = {

    [TD_VU] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_U),
    [TD_XZ] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_Z),
    [TD_KO] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_O),
    [TD_BEA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, dance_cln_reset),

    [TD_MG] =   ACTION_TAP_DANCE_DOUBLE(KC_M, KC_G),
    [TD_GF] =   ACTION_TAP_DANCE_DOUBLE(KC_G, KC_F),
 

    [TD_SLH]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_H),
    [TD_F1112] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12)
};


// clang-format off
//q14pro
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_1] = LAYOUT_105_ansi(
    MO(_FN2),    KC_F13,           KC_F14,   KC_F15,       G(C(KC_Q)),KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   MO(_BT),            TG(LAYER_5),
    KC_LCTL,     MT(MOD_LGUI,KC_L),KC_WH_U,  ALT_T(KC_F1), KC_ESC,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_MUTE,
    MO(_FN2),    KC_R,             KC_ESC,   TD(TD_BEA),   KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_VOLU,
    QK_LEAD,     TD(TD_XZ),        TD(TD_VU),              KC_LCTL,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_VOLD,
    TD(TD_F1112),TD(TD_SLH),       TD(TD_MG), KC_SPC,      KC_LSFT,             KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     QK_LEAD,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
    MO(_FN4),                      MO(_FN3),               MO(_FN1),  KC_LALT,            KC_LGUI,            KC_SPC,   MO(_FN4),           KC_RSFT,            MO(_FN1), QK_LEAD,            KC_LEFT,  KC_DOWN,  KC_RGHT),
    
    [LAYER_2] = LAYOUT_105_ansi(
        KC_MUTE,  KC_F13,   KC_F14,   KC_F15,       KC_TRNS,  KC_COMM,  KC_DOT,   KC_F3,       KC_F4,     KC_F5,     KC_F6,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,            KC_TRNS,
        KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,      G(KC_K),  KC_LSFT,  KC_LBRC,  KC_RBRC,     KC_P4,     KC_P6,     KC_P8,  KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_TRNS,
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS,      KC_TAB,   G(KC_J),  TD(TD_MG),ALT_T(KC_F1),KC_R,      TD(TD_KO), KC_F13, KC_F14,   KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_TRNS,
        KC_P4,    KC_P5,    KC_P6,                  MO(_FN1), QK_LEAD,  TD(TD_XZ),KC_WH_U,     TD(TD_BEA),KC_ESC,            KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_TRNS,
        KC_P1,    KC_P2,    KC_P3,    KC_LCTL,      KC_LSFT,            MO(_FN4), TD(TD_F1112),TD(TD_SLH),TD(TD_VU), KC_P0,  KC_F,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_P0,              KC_PDOT,                MO(_FN2), KC_LALT,          MT(MOD_LGUI,KC_L),        KC_SPC,    MO(_FN4),         KC_TRNS,            KC_TRNS,  KC_TRNS,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LAYER_3] = LAYOUT_105_ansi(
        MO(_FN3), XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_TRNS,      KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,            KC_TRNS,
        KC_HOME,  KC_PSLS   ,  KC_PAST,  KC_PMNS,   KC_ESC,       KC_1,      KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_TRNS,
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS,   KC_TAB,       KC_Q,      KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_TRNS,
        KC_P4,    KC_P5,    KC_P6,           MT(MOD_LCTL,KC_K),KC_A,      KC_S,     KC_D,     TD(TD_GF),KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_TRNS,
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,   MT(MOD_LSFT,KC_Y),       KC_Z,     KC_X,     KC_C,     KC_V,     KC_TRNS,  KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_P0,              KC_PDOT,             MO(_FN3),MT(MOD_LALT,KC_N),MT(MOD_LGUI,KC_L),          KC_GRV,   MO(_FN4),           KC_TRNS,            KC_TRNS,  KC_TRNS,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LAYER_4] = LAYOUT_105_ansi(
        KC_MUTE,  KC_F13,   KC_F14,   KC_F15,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             RGB_MOD,
        KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,   KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_P4,    KC_P5,    KC_P6,               KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_HOME,
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,   KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_P0,              KC_PDOT,             KC_LCTL,  KC_LALT,            KC_LGUI,            KC_SPC,   MO(_FN5),           KC_SPC,             KC_RGUI,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LAYER_5] = LAYOUT_105_ansi(
        TO(LAYER_1), KC_DEL,   KC_PGUP,  KC_PGDN,   KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,            TO(LAYER_1),
        KC_NUM,      KC_PSLS,  KC_PAST,  KC_PMNS,   KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_TRNS,
        KC_P7,       KC_P8,    KC_P9,    KC_PPLS,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_TRNS,
        KC_P4,       KC_P5,    KC_P6,               KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_TRNS,
        KC_P1,       KC_P2,    KC_P3,    KC_PENT,   KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_P0,                 KC_PDOT,             MO(_FN1), KC_TRNS,            KC_LGUI,            KC_SPC,   MO(_FN1),           KC_SPC,             KC_RGUI,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
    
 
    [_BT] = LAYOUT_105_ansi(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  BT_HST1,  BT_HST2,  BT_HST3,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BAT_LVL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,            XXXXXXX,             XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX),
    
    [_FN1] = LAYOUT_105_ansi(
        XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        G(KC_LBRC),XXXXXXX,   XXXXXXX,  G(KC_T),   KC_TILD,    KC_F1,      KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,            XXXXXXX,
        G(KC_RBRC),XXXXXXX,   XXXXXXX,  G(KC_Z),   TG(LAYER_2),TG(LAYER_3),G(KC_W),  G(KC_E),  G(KC_R),  G(KC_T),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  SGUI(KC_4),         XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,             XXXXXXX,    XXXXXXX,    G(KC_S),  G(KC_D),  G(KC_F),  G(KC_G),            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,  KC_BSPC,   XXXXXXX,                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_VOLU,
        G(KC_D),              XXXXXXX,             XXXXXXX,    G(KC_MINS),           G(KC_EQL),          KC_BSPC,  XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,            KC_MUTE,  KC_VOLD, KC_MPLY),
    
    [_FN2] = LAYOUT_105_ansi(
        XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,    KC_F1,    KC_F2,     KC_F3,      KC_F4,     KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,            XXXXXXX,
        XXXXXXX,  KC_F6,     KC_F7,      KC_F9,     KC_P,       XXXXXXX,  G(KC_LBRC),G(KC_RBRC), XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  KC_P0,     KC_P4,      KC_P8,     TO(LAYER_1),G(KC_K),  G(C(KC_F)),SGUI(KC_I), G(KC_COMM),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,   KC_P6,                 KC_PENT,    XXXXXXX,  XXXXXXX,   KC_WH_D,    G(KC_Z),   G(KC_N),            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,   TD(TD_KO),  QK_LEAD,   XXXXXXX,              XXXXXXX,   XXXXXXX,    KC_P,      KC_F8,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,             G(KC_0),               XXXXXXX,   G(KC_0),              G(KC_1),               XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX),
    
    [_FN3] = LAYOUT_105_ansi(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        KC_RBRC,  KC_LBRC,  KC_LSFT,  XXXXXXX,     KC_P,     XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  G(KC_J),     KC_M,     TO(LAYER_1),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        G(KC_1),  KC_UP,    KC_F8,                 KC_PENT,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        KC_LEFT,  KC_DOWN,  KC_RGHT,  G(KC_N),     KC_H,                 XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,            XXXXXXX,               XXXXXXX,  XXXXXXX,              XXXXXXX,            KC_SPC,   XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX),
    
    [_FN4] = LAYOUT_105_ansi(
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   G(KC_K),   KC_WH_D,   G(KC_G),     KC_GRV,   KC_F7,    KC_F8,    KC_F9,    KC_F10,    XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   G(C(KC_F)),SGUI(KC_I),SGUI(KC_Z),  XXXXXXX,  KC_F13,   KC_F14,   KC_F15,   KC_F16,    XXXXXXX,  G(C(KC_Q)),LAG(KC_GRV),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,                KC_LCTL,  XXXXXXX,  XXXXXXX,  KC_WH_D,  SGUI(KC_Z),XXXXXXX,             XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   G(KC_COMM),  KC_LSFT,            XXXXXXX,  KC_LCTL,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,              XXXXXXX,                XXXXXXX,  XXXXXXX,            XXXXXXX,             KC_LGUI,  XXXXXXX,               XXXXXXX,            XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX),
    
    [_FN5] = LAYOUT_105_ansi(
        RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,            RGB_TOG,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  BT_HST1,  BT_HST2,  BT_HST3,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BAT_LVL,  BAT_LVL,  NK_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,            XXXXXXX,             XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX),
 /*   [WIN_BASE] = LAYOUT_105_ansi(
        KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             RGB_MOD,
        KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,   KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_P4,    KC_P5,    KC_P6,               KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_HOME,
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,   KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_P0,              KC_PDOT,             KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,   MO(WIN_FN),                   KC_SPC,             KC_RALT,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
    [WIN_FN] = LAYOUT_105_ansi(
        RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT, KC_MUTE,  KC_VOLD,   KC_VOLU,  XXXXXXX,            RGB_TOG,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  BT_HST1,  BT_HST2,  BT_HST3,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,            XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BAT_LVL,  BAT_LVL,  NK_TOGG,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,            XXXXXXX,             XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,            XXXXXXX,           XXXXXXX,  XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX),
  */
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LAYER_1] = {ENCODER_CCW_CW(TG(LAYER_2), TG(LAYER_2))},
    [LAYER_2] = {ENCODER_CCW_CW(TG(LAYER_3), TG(LAYER_3))},
    [LAYER_3] = {ENCODER_CCW_CW(TO(LAYER_1),TO(LAYER_1))},
    [LAYER_4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER_5] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },

        
    [_FN1] = {ENCODER_CCW_CW(G(KC_Z), SGUI(KC_Z))},
    [_FN2] = {ENCODER_CCW_CW(S(KC_LBRC), S(KC_RBRC))},
    [_FN3] = {ENCODER_CCW_CW(C(KC_P2), C(KC_P8))},
    [_FN4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN5] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
    };
#endif // ENCODER_MAP_ENABLE
