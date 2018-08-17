#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _WINDOWS 0
#define _MACOS 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  KC_WINDOWS = SAFE_RANGE,
  KC_MACOS,
  LOWER,
  RAISE,
  ADJUST,
  KC_WINRGHT, // Move window to right
  KC_WINLEFT, // Move window to left
  KC_WINMAX, // Maximize window
  KC_WINDISP, // Move window to next display
  KC_APOS, // Apostrophe
};

#define KC_ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RESET RESET

// Objectives:
//  - Navigate one-handed with either hand
//
//  - Easily type common convoluted legalisms with minimal thumb-dancing
//    o Exhibit 1 at 12:5-13:2
//    o Rule 12(b)(6)
//  - ’997 Patent - ideally with numpad. Apostrophe is shift-alt-RBRC on Mac.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WINDOWS] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,HOME,     END , N  , M  ,COMM,DOT ,SLSH,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LALT,LOWR,         RASE, SPC, ENT
  //                  `----+----+----'        `----+----+----'
  ),

  [_MACOS] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LGUI, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,HOME,     END , N  , M  ,COMM,DOT ,SLSH,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL,LALT,LOWR,         RASE, SPC, ENT
  //                  `----+----+----'        `----+----+----'
  ),
// Move from desktop to desktop with left hand (to facilitate moving windows on MacOS,
// which requires mouse-control left right)
// It's desirable not to have a key over SPC, so that it's possible to type numbers
// with spaces in between and also to avoid mistyping "123 text" as "1230text"
  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,PGUP, UP ,PGDN,    ,               APOS, P7 , P8 , P9 ,COLN ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,LEFT,DOWN,RGHT,    ,               LPRN, P4 , P5 , P6 ,MINS,PLUS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    , SPC, ENT,    ,    ,    NLCK ,RPRN, P1 , P2 , P3 ,DOT ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    , P0
  //                  `----+----+----'        `----+----+----'
  ),
// Archive mail in Mail.app
#define KC_ARCH RGUI(KC_ENT)
// Symbols from standard egodox ez layout: https://configure.ergodox-ez.com/keyboard_layouts/new


  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,F11 ,F12 ,F13 ,F14 ,F15 ,               F16 ,F17 ,F18 ,F19 ,F20 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,LCBR,RCBR,PIPE,               INS ,PGDN,PGUP,MINS,EQL ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,HASH,DLR ,LPRN,RPRN,GRV ,               LEFT,DOWN, UP ,RGHT,    ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,PERC,CIRC,LBRC,RBRC,TILD,    ,         ,HOME,END ,    ,    ,ARCH,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

// should have window moving keys: on mac, command option left right
    // move desktop: control alt gui left right left right
  [_ADJUST] = LAYOUT_kc(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
     WINDOWS ,        ,        ,        ,        ,        ,                                   ,        ,        ,        ,        , MACOS  ,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
             ,        ,        ,        ,        ,        ,                                   ,        ,        ,        ,        ,        ,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
             ,        ,        ,        ,        ,        ,                           WINLEFT ,WINDISP ,WINMAX  ,WINRGHT ,        ,        ,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
             , RESET  ,        ,        ,        ,        ,        ,                 ,        ,        ,        ,        ,        ,        ,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                             ,        ,        ,                         ,        ,
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

uint16_t current_default_layer;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
  current_default_layer = default_layer;
}

void matrix_init_user(void) {
    current_default_layer = eeconfig_read_default_layer();
}

// Use in switch(keycode). Needs SEND_STRING format.
#define PROCESS_WINDOWS_MAC_KEY(keycode, winmacro, macmacro) \
case keycode: \
  if (record->event.pressed) { \
    if (current_default_layer == 1UL<<_WINDOWS) { \
      SEND_STRING(winmacro); \
    } \
    else { \
      SEND_STRING(macmacro); \
    } \
  } \
  return false; \
  break;
// End PROCESS_WINDOWS_MAC_KEY definition

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    PROCESS_WINDOWS_MAC_KEY(KC_APOS, SS_TAP(X_QUOTE), SS_LSFT(SS_LALT(SS_TAP(X_RBRACKET))));
    PROCESS_WINDOWS_MAC_KEY(KC_WINLEFT, SS_LGUI(SS_TAP(X_LEFT)), SS_LGUI(SS_LALT(SS_TAP(X_LEFT))));
    PROCESS_WINDOWS_MAC_KEY(KC_WINRGHT, SS_LGUI(SS_TAP(X_RIGHT)), SS_LGUI(SS_LALT(SS_TAP(X_RIGHT))));
    PROCESS_WINDOWS_MAC_KEY(KC_WINMAX, SS_LGUI(SS_TAP(X_UP)), SS_LGUI(SS_LALT(SS_TAP(X_UP))));
    PROCESS_WINDOWS_MAC_KEY(KC_WINDISP, "", SS_LCTRL(SS_LGUI(SS_LALT(SS_TAP(X_RIGHT)))));

    // Use escape to cancel oneshot keys if active.
    case KC_ESC:
      if (record->event.pressed) {
        bool queue = true;
        if ((get_oneshot_mods ()) && !has_oneshot_mods_timed_out ()) {
          clear_oneshot_mods ();
          queue = false;
        }
        return queue;
      }
      return true;
      break;
    // Layer shifting code
    case KC_WINDOWS:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_WINDOWS);
      }
      return false;
      break;
    case KC_MACOS:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_MACOS);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
