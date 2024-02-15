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
//v10
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
    _FN5,
    _FN6
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

            case _FN6:
                    rgb_matrix_set_color_all(166,166,0);
                break;
        }
    return false;
}
#endif // RGB_MATRIX_ENABLE

/*LEADER KEY setting */
void leader_start_user(void) {
}

void leader_end_user(void) {
    
    if (leader_sequence_one_key(KC_F1)) {
        // F1 to U
        tap_code16(KC_U);

    }else if (leader_sequence_one_key(KC_X)) {
        // X to M
        tap_code16(KC_M);
    } else if (leader_sequence_two_keys(KC_X, KC_X)) {
        // X to G
        tap_code16(KC_G);
        
    }else if (leader_sequence_one_key(KC_V)) {
        // M to K
        tap_code16(KC_K);
    } else if (leader_sequence_two_keys(KC_V, KC_V)) {
        // M to O
        tap_code16(KC_O);
        
    }else if (leader_sequence_one_key(KC_F8)) {
        // F8 to F10
        tap_code16(KC_F10);
         
    }else if(leader_sequence_one_key(KC_ESC)) {
        //100% opacity
        tap_code16(KC_V);
        tap_code16(KC_0);
        
    } else if (leader_sequence_two_keys(KC_ESC, KC_ESC)) {
        // 10% opacity
        tap_code16(KC_V);
        tap_code16(KC_1);
        
    }else if (leader_sequence_one_key(KC_R)) {
        // save and close all windows
        tap_code16(LGUI(KC_S));
        tap_code16(LAG(KC_W));
        tap_code16(KC_ENT);

    } else if (leader_sequence_two_keys(KC_R, KC_R)) {
        //screen lock
        tap_code16(G(C(KC_Q)));

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

        //numpad 0 to 9
    }else if (leader_sequence_one_key(KC_P0)) {
        tap_code16(KC_P1);
    }else if (leader_sequence_two_keys(KC_P0, KC_P0)) {
        tap_code16(KC_P2);
    }else if (leader_sequence_three_keys(KC_P0, KC_P0, KC_P0)) {
        tap_code16(KC_P3);
        
    }else if (leader_sequence_one_key(KC_P4)) {
        tap_code16(KC_P7);
    }else if (leader_sequence_one_key(KC_P5)) {
        tap_code16(KC_P8);
    }else if (leader_sequence_one_key(KC_P6)) {
        tap_code16(KC_P9);
    }
        
}


    //tap dance
    enum{
        TD_VF8 =  0,
        TD_XG  =  1,
        TD_KO  =  2,

        TD_MSL =  3,
        TD_GF  =  4,
        TD_SLH =  5,
        TD_F1112 = 6,
        
        TD_TAB1 = 7,
        TD_P45 = 8,
        TD_P67 = 9,
        TD_P89 = 10,
        TD_02  = 11,
        TD_1F10= 12,
        TD_XMG = 13,
        TD_KOH = 14,
        TD_TAB2 =15,
        
        TD_BEA = 16, SOME_OTHER_DANCE
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



// 0 to 2
void triple_numpad (tap_dance_state_t *state, void *user_data);
void triple_numpad(tap_dance_state_t *state, void *user_data) {
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

// X > M > G
void triple_xmg (tap_dance_state_t *state, void *user_data);
void triple_xmg (tap_dance_state_t *state, void *user_data) {
 if (state->count == 2) {
        register_code16(KC_M);
    } else if(state->count == 3){
        register_code(KC_G);
    } else {
        register_code(KC_X);
    }
 if (state->count == 2) {
        unregister_code16(KC_M);
    } else if(state->count == 3) {
        unregister_code(KC_G);
    } else {
        unregister_code(KC_X);
    }
};

// K > O > H
void triple_koh (tap_dance_state_t *state, void *user_data);
void triple_koh (tap_dance_state_t *state, void *user_data) {
 if (state->count == 2) {
        register_code16(KC_O);
    } else if(state->count == 3){
        register_code(KC_H);
    } else {
        register_code(KC_K);
    }
 if (state->count == 2) {
        unregister_code16(KC_O);
    } else if(state->count == 3) {
        unregister_code(KC_H);
    } else {
        unregister_code(KC_K);
    }
};


void dance_cln_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_B);
    unregister_code16(KC_E);
    unregister_code16(A(KC_LCTL));
    unregister_code16(KC_TAB);

    unregister_code16(KC_G);
    unregister_code16(KC_M);
    unregister_code16(KC_T);
    unregister_code16(KC_D);

    unregister_code16(KC_K);
    unregister_code16(KC_O);
    unregister_code16(KC_L);
    unregister_code16(KC_V);
    unregister_code16(KC_F);
    unregister_code16(KC_X);
    unregister_code16(KC_H);
    unregister_code16(KC_SLSH);
    unregister_code16(KC_F8);
    unregister_code16(KC_F10);
    unregister_code16(KC_F11);
    unregister_code16(KC_F12);

    unregister_code16(KC_P0);
    unregister_code16(KC_P1);
    unregister_code16(KC_P2);
    unregister_code16(KC_P3);
    unregister_code16(KC_P4);
    unregister_code16(KC_P5);
    unregister_code16(KC_P6);
    unregister_code16(KC_P7);
    unregister_code16(KC_P8);
    unregister_code16(KC_P9);
    
    unregister_code16(LAYER_1);
    unregister_code16(LAYER_2);
    
};

tap_dance_action_t tap_dance_actions[] = {

    [TD_VF8] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_F8),
    [TD_XG] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_G),
    [TD_KO] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_O),
    [TD_BEA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, dance_cln_reset),


    [TD_GF] =   ACTION_TAP_DANCE_DOUBLE(KC_G, KC_F),

    /* change layer by tapping, TAPPING_TERM 200 */
        // double tap by default
        [TD_TAB1] = ACTION_TAP_DANCE_LAYER_MOVE(KC_TAB, LAYER_1),
        // triple tap by default
        [TD_TAB2] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_TAB, LAYER_2),
    
    [TD_MSL]  = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_SLSH),
    [TD_F1112] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12),
    [TD_1F10]  = ACTION_TAP_DANCE_DOUBLE(KC_P1, KC_F10),
    [TD_P45]   = ACTION_TAP_DANCE_DOUBLE(KC_P4, KC_P5),
    [TD_P67]   = ACTION_TAP_DANCE_DOUBLE(KC_P6, KC_P7),
    [TD_P89]   = ACTION_TAP_DANCE_DOUBLE(KC_P8, KC_P9),

    [TD_02] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_numpad, dance_cln_reset),
    [TD_XMG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_xmg, dance_cln_reset),
    [TD_KOH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_koh, dance_cln_reset)
    
};
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

//Added KANA imput 2023/12/15
enum custom_keycodes {
  A = SAFE_RANGE,
  I,U,E,O,
  KA,KI,KU,KE,KO,
  SA,SI,SU,SE,SO,
  TA,TI,TU,TE,TO,
  NA,NI,NU,NE,NO,
  HA,HI,HU,HE,HO,
  MA,MI,MU,ME,MO,
  RA,RI,RU,RE,RO,
  YA,YU,YO,WA,WO,
  NN,
  GA,GI,GU,GE,GO,
  ZA,ZI,ZU,ZE,ZO,
  DA,DI,DU,DE,DO,
  BA,BI,BU,BE,BO,
  XYA,XYU,XYO,
  XA,XI,XU,XE,XO,
  XTU,
  PA,PI,PU,PE,PO,
  DAKUTEN,
  HANDAKU
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode){
    case A:
    if(record->event.pressed){
      SEND_STRING("a");} else { }break;
    case I:
    if(record->event.pressed){
      SEND_STRING("i");}else{ }break;
    case U:
    if(record->event.pressed){
      SEND_STRING("u");}else{ }break;
    case E:
    if(record->event.pressed){
      SEND_STRING("e");}else{ }break;
    case O:
    if(record->event.pressed){
      SEND_STRING("o");}else{ }break;

    case KA:
    if(record->event.pressed){
      SEND_STRING("ka");} else { }break;
    case KI:
    if(record->event.pressed){
      SEND_STRING("ki");}else{ }break;
    case KU:
    if(record->event.pressed){
      SEND_STRING("ku");}else{ }break;
    case KE:
    if(record->event.pressed){
      SEND_STRING("ke");}else{ }break;
    case KO:
    if(record->event.pressed){
      SEND_STRING("ko");}else{ }break;

    case SA:
    if(record->event.pressed){
      SEND_STRING("sa");} else { }break;
    case SI:
    if(record->event.pressed){
      SEND_STRING("si");}else{ }break;
    case SU:
    if(record->event.pressed){
      SEND_STRING("su");}else{ }break;
    case SE:
    if(record->event.pressed){
      SEND_STRING("se");}else{ }break;
    case SO:
    if(record->event.pressed){
      SEND_STRING("so");}else{ }break;

    case TA:
    if(record->event.pressed){
      SEND_STRING("ta");} else { }break;
    case TI:
    if(record->event.pressed){
      SEND_STRING("ti");}else{ }break;
    case TU:
    if(record->event.pressed){
      SEND_STRING("tu");}else{ }break;
    case TE:
    if(record->event.pressed){
      SEND_STRING("te");}else{ }break;
    case TO:
    if(record->event.pressed){
      SEND_STRING("to");}else{ }break;

    case NA:
    if(record->event.pressed){
      SEND_STRING("na");} else { }break;
    case NI:
    if(record->event.pressed){
      SEND_STRING("ni");}else{ }break;
    case NU:
    if(record->event.pressed){
      SEND_STRING("nu");}else{ }break;
    case NE:
    if(record->event.pressed){
      SEND_STRING("ne");}else{ }break;
    case NO:
    if(record->event.pressed){
      SEND_STRING("no");}else{ }break;

    case HA:
    if(record->event.pressed){
      SEND_STRING("ha");} else { }break;
    case HI:
    if(record->event.pressed){
      SEND_STRING("hi");}else{ }break;
    case HU:
    if(record->event.pressed){
      SEND_STRING("hu");}else{ }break;
    case HE:
    if(record->event.pressed){
      SEND_STRING("he");}else{ }break;
    case HO:
    if(record->event.pressed){
      SEND_STRING("ho");}else{ }break;

    case MA:
    if(record->event.pressed){
      SEND_STRING("ma");} else { }break;
    case MI:
    if(record->event.pressed){
      SEND_STRING("mi");}else{ }break;
    case MU:
    if(record->event.pressed){
      SEND_STRING("mu");}else{ }break;
    case ME:
    if(record->event.pressed){
      SEND_STRING("me");}else{ }break;
    case MO:
    if(record->event.pressed){
      SEND_STRING("mo");}else{ }break;

    case RA:
    if(record->event.pressed){
      SEND_STRING("ra");} else { }break;
    case RI:
    if(record->event.pressed){
      SEND_STRING("ri");}else{ }break;
    case RU:
    if(record->event.pressed){
      SEND_STRING("ru");}else{ }break;
    case RE:
    if(record->event.pressed){
      SEND_STRING("re");}else{ }break;
    case RO:
    if(record->event.pressed){
      SEND_STRING("ro");}else{ }break;

    case YA:
    if(record->event.pressed){
      SEND_STRING("ya");} else { }break;
    case YU:
    if(record->event.pressed){
      SEND_STRING("yu");}else{ }break;
    case YO:
    if(record->event.pressed){
      SEND_STRING("yo");}else{ }break;
    case WA:
    if(record->event.pressed){
      SEND_STRING("wa");}else{ }break;
    case WO:
    if(record->event.pressed){
      SEND_STRING("wo");}else{ }break;
    case NN:
    if(record->event.pressed){
      SEND_STRING("nn");} else { }break;

    case GA:
    if(record->event.pressed){
      SEND_STRING("ga");} else { }break;
    case GI:
    if(record->event.pressed){
      SEND_STRING("gi");}else{ }break;
    case GU:
    if(record->event.pressed){
      SEND_STRING("gu");}else{ }break;
    case GE:
    if(record->event.pressed){
      SEND_STRING("ge");}else{ }break;
    case GO:
    if(record->event.pressed){
      SEND_STRING("go");}else{ }break;

    case ZA:
    if(record->event.pressed){
      SEND_STRING("za");} else { }break;
    case ZI:
    if(record->event.pressed){
      SEND_STRING("zi");}else{ }break;
    case ZU:
    if(record->event.pressed){
      SEND_STRING("zu");}else{ }break;
    case ZE:
    if(record->event.pressed){
      SEND_STRING("ze");}else{ }break;
    case ZO:
    if(record->event.pressed){
      SEND_STRING("zo");}else{ }break;

    case DA:
    if(record->event.pressed){
      SEND_STRING("da");} else { }break;
    case DI:
    if(record->event.pressed){
      SEND_STRING("di");}else{ }break;
    case DU:
    if(record->event.pressed){
      SEND_STRING("du");}else{ }break;
    case DE:
    if(record->event.pressed){
      SEND_STRING("de");}else{ }break;
    case DO:
    if(record->event.pressed){
      SEND_STRING("do");}else{ }break;

    case BA:
    if(record->event.pressed){
      SEND_STRING("ba");} else { }break;
    case BI:
    if(record->event.pressed){
      SEND_STRING("bi");}else{ }break;
    case BU:
    if(record->event.pressed){
      SEND_STRING("bu");}else{ }break;
    case BE:
    if(record->event.pressed){
      SEND_STRING("be");}else{ }break;
    case BO:
    if(record->event.pressed){
      SEND_STRING("bo");}else{ }break;

    case XYA:
    if(record->event.pressed){
      SEND_STRING("xya");} else { }break;
    case XYU:
    if(record->event.pressed){
      SEND_STRING("xyu");}else{ }break;
    case XYO:
    if(record->event.pressed){
      SEND_STRING("xyo");}else{ }break;

    case XA:
    if(record->event.pressed){
      SEND_STRING("xa");} else { }break;
    case XI:
    if(record->event.pressed){
      SEND_STRING("xi");}else{ }break;
    case XU:
    if(record->event.pressed){
      SEND_STRING("xu");}else{ }break;
    case XE:
    if(record->event.pressed){
      SEND_STRING("xe");}else{ }break;
    case XO:
    if(record->event.pressed){
      SEND_STRING("xo");}else{ }break;
    case XTU:
    if(record->event.pressed){
      SEND_STRING("xtu");}else{ }break;
          
    case PA:
    if(record->event.pressed){
      SEND_STRING("pa");} else { }break;
    case PI:
    if(record->event.pressed){
      SEND_STRING("pi");}else{ }break;
    case PU:
    if(record->event.pressed){
      SEND_STRING("pu");}else{ }break;
    case PE:
    if(record->event.pressed){
      SEND_STRING("pe");}else{ }break;
    case PO:
    if(record->event.pressed){
      SEND_STRING("po");}else{ }break;
          
    case DAKUTEN:
    if(record->event.pressed){
      SEND_STRING("dakutenn");}else{ }break;
    case HANDAKU:
    if(record->event.pressed){
      SEND_STRING("handakutenn");}else{ }break;

  }

  return true;
}
//changed END.2023/12/15

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)


//Save and Change layer
enum custom_keycodes {
 SC = SAFE_RANGE,
 };
bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode){
        case SC:
            if(record->event.pressed){
                
                register_code16(G(KC_S));
                unregister_code16(G(KC_S));
                register_code16(KC_F10);
                unregister_code16(KC_F10);
            }else{
                layer_move(LAYER_1);
            }
  break;
}
return true;
};


//v10
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_1] = LAYOUT_ansi_89(
    MO(_FN1),   G(C(KC_Q)), KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,   KC_F7,      KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,             C(KC_UP),
    TG(LAYER_2),KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,    KC_7,       KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_MUTE,
    TG(LAYER_3),KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,    KC_U,       KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_VOLU,
    KC_HOME,    KC_LCTL,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,    KC_J,       KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_VOLD,
    KC_END,     KC_LSFT,              KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,    KC_GRV,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
    MO(_FN4),   MO(_FN1),   KC_LALT,            KC_LGUI,  KC_SPC,   TG(LAYER_2),                    KC_RSFT,            KC_RGUI,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

[LAYER_2] = LAYOUT_ansi_89(
    MO(_FN2),   KC_TRNS,    KC_F1,          KC_F2,      KC_F3,       KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,            KC_TRNS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,        KC_Z,       KC_P,        TD(TD_P45),TD(TD_P67),  TD(TD_P89), KC_7,       KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_TRNS,
    XXXXXXX,    TD(TD_TAB1),KC_LBRC,        KC_RBRC,    ALT_T(KC_F1),CTL_T(KC_R),TD(TD_1F10),KC_Y,       KC_U,       KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_TRNS,
    G(KC_RBRC), MO(_FN1),   QK_LEAD,        TD(TD_XG),  KC_WH_U,     TD(TD_BEA), KC_ESC,     KC_H,       KC_J,       KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_PENT,            KC_TRNS,
    G(KC_LBRC), SFT_T(KC_M),                KC_F9,      TD(TD_F1112),TD(TD_KOH), TD(TD_VF8), TD(TD_02),  QK_LEAD,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
    KC_LCTL,    MO(_FN2),   ALT_T(KC_SLSH), GUI_T(KC_L),             KC_SPC,     TO(LAYER_1),                        KC_TRNS,            KC_TRNS,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

[LAYER_3] = LAYOUT_ansi_89(
    TO(LAYER_1),KC_TRNS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,      KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,            KC_TRNS,
    KC_HOME,    KC_ESC,             KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,     KC_P6,    KC_P7,      KC_P8,    KC_P9,    KC_P0,    KC_MINS,  KC_EQL,   KC_BSPC,            KC_TRNS,
    KC_PDOT,    KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,       KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_TRNS,
    G(KC_I),    CTL_T(KC_K),        KC_A,     KC_S,     KC_D,     TD(TD_GF),KC_G,      KC_H,     KC_J,       KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_TRNS,
    A(KC_H),    SFT_T(KC_Y),                  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_TRNS,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
    MO(_FN1),   MO(_FN3),ALT_T(KC_N),         GUI_T(KC_L),        KC_GRV,   MO(_FN4),                        KC_TRNS,            KC_TRNS,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

[LAYER_4] = LAYOUT_ansi_89(
    KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
    XXXXXXX,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
    XXXXXXX,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
    XXXXXXX,    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
    XXXXXXX,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
    XXXXXXX,    KC_LCTL,  KC_LALT,            KC_LGUI,  KC_SPC,  MO(_FN5),                       KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),
    
[LAYER_5] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,       KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,             KC_TRNS,
        KC_PGUP,    RO,         NU,       HU,       A,        U,        E,         O,        YA,         YU,       YO,       WA,       HO,       HANDAKU,  KC_BSPC,            KC_TRNS,
        KC_PGDN,    KC_TAB,     TA,       TE,       I,        SU,       KA,        NN,       NA,         NI,       RA,       SE,       DAKUTEN,  MU,       HE,                 KC_TRNS,
        KC_HOME,    MO(_FN1),   TI,       TO,       SI,       HA,       KI,        KU,       MA,         NO,       RI,       RE,       KE,                 KC_ENT,             KC_TRNS,
        KC_END,     MO(_FN4),             TU,       SA,       SO,       HI,        KO,       TO(LAYER_1),MI,       MO,       NE,       RU,       ME,       MO(_FN1), KC_UP,
        MO(_FN4),   MO(LAYER_6),G(KC_MINS),         G(KC_EQL),KC_SPC,   MO(LAYER_6),                     MO(_FN4),           MO(_FN6),                     KC_LEFT,  KC_DOWN,  KC_RGHT),

[LAYER_6] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        XXXXXXX,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        XXXXXXX,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        XXXXXXX,    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        XXXXXXX,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        XXXXXXX,    KC_LCTL,  KC_LALT,            KC_LGUI,  KC_SPC,  MO(_FN5),                       KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

[_FN1] = LAYOUT_ansi_89(
    XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,           XXXXXXX,
    XXXXXXX,   KC_TILD,     KC_F1,      KC_F2,     KC_F3,    KC_F4,     KC_F5,     KC_F6,      KC_F7,     KC_F8,    KC_F9,    KC_F10,    KC_F11,   KC_F12,    SGUI(KC_4),        XXXXXXX,
    XXXXXXX,   TG(LAYER_2), XXXXXXX,    G(KC_N),   G(KC_E),  G(KC_COMM),G(KC_T),   XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  G(KC_P),   KC_LBRC,  KC_RBRC,   KC_BSLS,           XXXXXXX,
    KC_PGUP,   XXXXXXX,     G(KC_K),    G(KC_S),   G(KC_D),  SGUI(KC_Z),G(KC_G),   KC_LEFT,    KC_DOWN,   KC_UP,    KC_RGHT,  KC_SCLN,   KC_QUOT,             KC_TRNS,           XXXXXXX,
    KC_PGDN,   XXXXXXX,                 XXXXXXX,   XXXXXXX,  G(KC_J),   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_COMM,   KC_DOT,   KC_SLSH,   KC_TRNS,  KC_VOLU,
    XXXXXXX,   XXXXXXX,     G(KC_MINS),            G(KC_EQL),KC_BSPC,   XXXXXXX,                          KC_TRNS,            KC_TRNS,                        KC_MUTE,  KC_VOLD, KC_MPLY),

[_FN2] = LAYOUT_ansi_89(
    XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_TRNS,
    XXXXXXX,   XXXXXXX,    XXXXXXX,  G(KC_LBRC), G(KC_RBRC),XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_TRNS,
    XXXXXXX,   SC,         G(KC_K),  G(C(KC_F)), SGUI(KC_I),KC_F15,    KC_F16,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_TRNS,
    XXXXXXX,   KC_PENT,    XXXXXXX,  KC_F7,      KC_WH_D,   G(KC_Z),   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            KC_TRNS,
    XXXXXXX,   XXXXXXX,              XXXXXXX,    XXXXXXX,   KC_F13,    KC_F14,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX,    XXXXXXX,              XXXXXXX,   KC_F,      XXXXXXX,                       XXXXXXX,            XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX),

[_FN3] = LAYOUT_ansi_89(
    XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_TRNS,
    XXXXXXX,  KC_P,     KC_F1,      KC_F2,    KC_F3,    KC_F4,      KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_TRNS,
    KC_SLSH,  KC_M,     TO(LAYER_1),C(KC_P8), XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_TRNS,
    XXXXXXX,  KC_ENT,   C(KC_P4),   C(KC_P2), C(KC_P6), XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_LCTL,            KC_TRNS,
    A(KC_H),  KC_H,                 XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LSFT,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  KC_SPC,     XXXXXXX,                       XXXXXXX,            XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX),

[_FN4] = LAYOUT_ansi_89(
    XXXXXXX,    LAG(KC_GRV),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_TRNS,
    XXXXXXX,    KC_GRV,     XXXXXXX,  BU,       XA,       XU,         XE,        XO,        XYA,        XYU,      XYO,      WO,       BO,       XXXXXXX,  XXXXXXX,            KC_TRNS,
    XXXXXXX,    XXXXXXX,    DA,       DE,       XI,       ZU,         GA,        XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  ZE,       XXXXXXX,  XXXXXXX,  BE,                 KC_TRNS,
    XXXXXXX,    XXXXXXX,    DI,       DO,       ZI,       BA,         GI,        GU,        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  GE,                 XXXXXXX,            KC_TRNS,
    XXXXXXX,    XXXXXXX,              XTU,      ZA,       ZO,         BI,        GO,        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,                          XXXXXXX,            XXXXXXX,                      XXXXXXX,  XXXXXXX,   XXXXXXX),

[_FN5] = LAYOUT_ansi_89(
    RGB_TOG,    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                      _______,  _______,  _______),
    
[_FN6] = LAYOUT_ansi_89(
    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_TRNS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,  PU,       XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  PO,       XXXXXXX,  XXXXXXX,            KC_TRNS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  PE,                 KC_TRNS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  PA,         XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            KC_TRNS,
    XXXXXXX,    XXXXXXX,              DU,       XXXXXXX,  XXXXXXX,    PI,        XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,                          XXXXXXX,            XXXXXXX,                      XXXXXXX,  XXXXXXX,   XXXXXXX),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
[LAYER_1] = {ENCODER_CCW_CW(TG(LAYER_2), TG(LAYER_2))},
[LAYER_2] = {ENCODER_CCW_CW(TG(LAYER_3), TG(LAYER_3))},
[LAYER_3] = {ENCODER_CCW_CW(TO(LAYER_1),TO(LAYER_1))},
[LAYER_4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
[LAYER_5] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
[LAYER_6] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    
[_FN1] = {ENCODER_CCW_CW(G(KC_Z), SGUI(KC_Z))},
[_FN2] = {ENCODER_CCW_CW(S(KC_LBRC), S(KC_RBRC))},
[_FN3] = {ENCODER_CCW_CW(C(KC_P2), C(KC_P8))},
[_FN4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
[_FN5] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
[_FN6] = {ENCODER_CCW_CW(G(KC_Z), SGUI(KC_Z))}
};
#endif // ENCODER_MAP_ENABLE
