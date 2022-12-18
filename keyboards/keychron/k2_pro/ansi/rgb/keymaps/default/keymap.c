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
enum layers{
    LAYER_1,
    LAYER_2,
    LAYER_3,
    _FN1,
    _FN2,
    _FN3
};

/* LEADER KEY setting */
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
    };

    //set layer indicator
    uint8_t layer = biton32(layer_state);
//red, tomato, dodger_blue, purple, orange, spring_green,
    switch (layer){
        case LAYER_1:
            rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
            break;
        case LAYER_2:
            rgb_matrix_set_color_all(0xFF, 0x63, 0x47);
            break;
        case LAYER_3:
            rgb_matrix_set_color_all(0x00, 0x90, 0xFF);
            break;
        case _FN1:
            rgb_matrix_set_color_all(0x80, 0x00, 0x80);
            break;
        case _FN2:
            rgb_matrix_set_color_all(0xFF, 0xA5, 0x00);
            break;
        case _FN3:
            rgb_matrix_set_color_all(0x00, 0xFF, 0x7F);
            break;
    }
};

//tap dance
enum{
    TD_LV  = 1,
    TD_XZ  = 2,
    TD_KO  = 3,
    CT_GUM = 4,
    TD_LNG = 5,
    TD_GF = 6,
    CT_F679 = 7,
    TD_BEA = 8, SOME_OTHER_DANCE
};
void g_u_m (qk_tap_dance_state_t *state, void *user_data);
void g_u_m (qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        register_code16(KC_G);
    } else if(state->count == 2){
        register_code16(KC_U);
    } else {
        register_code16(KC_M);
    }
    
    if (state->count == 2) {
        unregister_code16(KC_G);
    } else if(state->count == 3) {
        unregister_code16(KC_U);
    } else {
        unregister_code16(KC_M);

    }
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
    unregister_code16(KC_U);
    unregister_code16(KC_M);
    unregister_code16(KC_T);
    unregister_code16(KC_D);
    unregister_code16(KC_LNG1);
    unregister_code16(KC_LNG2);
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LNG] = ACTION_TAP_DANCE_DOUBLE(KC_LNG2, KC_LNG1),
    [TD_LV] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_V),
    [TD_XZ] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_Z),
    [TD_KO] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_O),
    [TD_BEA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, dance_cln_reset),
    [CT_F679] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_function, dance_cln_reset),
    [CT_GUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, g_u_m, dance_cln_reset),
    [TD_GF] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_F)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_1] = LAYOUT_ansi_84(
     KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    TD(TD_LNG),C(G(KC_Q)),SGUI(KC_3),
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,              KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,              KC_PGDN,
     KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,               C(KC_UP),
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,   KC_UP,     C(KC_DOWN),
     MO(_FN1), KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_LGUI,  MO(_FN1),TG(LAYER_2),KC_LEFT,   KC_DOWN,   KC_RGHT),

[LAYER_2] = LAYOUT_ansi_84(
     KC_GRV,   KC_F1,     KC_F2,      KC_F3,      KC_F4,     KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    TD(TD_LNG),C(G(KC_Q)),XXXXXXX,
     KC_ESC,   KC_1,      KC_2,       KC_3,       KC_4,      KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,              XXXXXXX,
     KC_TAB,   TD(CT_GUM),TD(CT_F679),ALT_T(KC_R),KC_F1,     TD(TD_KO),KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,              G(KC_EQL),
     MO(_FN1), KC_LEAD,   TD(TD_XZ),  KC_WH_U,    TD(TD_BEA),KC_ESC,   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,               G(KC_MINS),
     KC_LSFT,             KC_LBRC,    KC_RBRC,    KC_SLSH,   KC_V,     G(KC_J),  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,   KC_UP,     KC_F,
     MO(_FN2), KC_LCTL,   MT(MOD_LGUI,KC_L),                           KC_SPC,                                 KC_LGUI,  MO(_FN1),TG(LAYER_3),KC_LEFT,   KC_DOWN,   KC_RGHT),

[LAYER_3] = LAYOUT_ansi_84(
     KC_GRV,      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    TD(TD_LNG),C(G(KC_Q)),SGUI(KC_3),
     KC_ESC,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,              KC_HOME,
     KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,              KC_P9,
MT(MOD_LCTL,KC_K),KC_A,     KC_S,     KC_D,     TD(TD_GF),KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,               S(KC_P7),
MT(MOD_LSFT,KC_Y),          KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,   KC_P8,     KC_PDOT,
     MO(_FN3), MT(MOD_LALT,KC_N), MT(MOD_LGUI,KC_L),                KC_GRV,                                 KC_LGUI,  MO(_FN1),TO(LAYER_1),KC_P4,     KC_P2,     KC_P6),


[_FN1] = LAYOUT_ansi_84(
     KC_TILD,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BT_HST1,
     KC_GRV,   KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,   KC_F12,   KC_DEL,             BT_HST2,
     XXXXXXX,  XXXXXXX,   G(KC_W),  G(KC_E),  G(KC_R),  G(KC_T),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            BT_HST3,
     XXXXXXX,  G(KC_A),   G(KC_S),  G(KC_D),  G(KC_F),  G(KC_G),  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,   XXXXXXX,  XXXXXXX,            KC_PENT,            XXXXXXX,
    SGUI(KC_4),           G(KC_Z),  G(KC_X),  G(KC_C),  G(KC_V),  XXXXXXX,  XXXXXXX,  XXXXXXX,  G(KC_COMM),G(KC_DOT),G(KC_SLSH),         KC_MPLY,  KC_VOLU,  KC_MUTE,
     XXXXXXX,  G(KC_MINS),G(KC_EQL),                              KC_BSPC,                                 XXXXXXX,  XXXXXXX,  KC_MUTE,  KC_MPRV,  KC_VOLD,  KC_MNXT),

[_FN2] = LAYOUT_ansi_84(
     XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     KC_F11,   KC_7,     KC_8,      KC_9,      KC_0,      KC_F5,     KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             XXXXXXX,
     XXXXXXX,  KC_F12,   G(C(KC_F)),SGUI(KC_I),G(KC_COMM),KC_F2,     KC_F3,   KC_F4,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
     XXXXXXX,  XXXXXXX,  G(KC_N),   KC_WH_D,   G(KC_Z),   G(KC_0),   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
     XXXXXXX,            XXXXXXX,   XXXXXXX,   SGUI(KC_Z),KC_F8,     G(KC_K), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  G(KC_T),                                    KC_R,                                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

[_FN3] = LAYOUT_ansi_84(
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
     KC_P,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,             XXXXXXX,
     KC_M,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,
     KC_ENT,   KC_PDOT,  KC_SLSH,  S(KC_P7), KC_HOME,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,             XXXXXXX,
     KC_H,               XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  C(KC_P8),  XXXXXXX,
     XXXXXXX,  KC_P5,    KC_P9,                                  KC_SPC,                                 XXXXXXX,  XXXXXXX,  XXXXXXX,  C(KC_P4), C(KC_P2),  C(KC_P6))
};
