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


#define KC_LOWR LOWER
#define KC_RASE RAISE

// Objectives:
//  - Navigate one-handed with either hand
//
//  - Easily type common convoluted legalisms with minimal thumb-dancing
//    o Exhibit 1 at 12:5-13:2
//    o Rule 12(b)(6)
//  - ’997 Patent - ideally with numpad. Apostrophe is shift-alt-RBRC on Mac.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WINDOWS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                      ,-------+-------+-------+-------+-------+-------.
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                        KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------|                      |-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                        KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|                      |-------+-------+-------+-------+-------+-------|
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                        KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT ,
  //|-------+-------+-------+-------+-------+-------+-------.      ,-------|-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_HOME,       KC_END , KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
  //`-------+-------+-------+-------+-------+-------+-------/      \-------+-------+-------+-------+-------+-------+-------'
                                  KC_LGUI,KC_LALT,KC_LOWR,             KC_RASE, KC_SPC, KC_ENT
  //                             `-------+-------+-------'            `-------+-------+-------'
  ),

  [_MACOS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                      KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                      KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     KC_LGUI, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                      KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_HOME,     KC_END , KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
  //`-------+-------+-------+-------+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                  KC_LCTL,KC_LALT,KC_LOWR,          KC_RASE, KC_SPC, KC_ENT
  //                             `-------+-------+-------'         `-------+-------+-------'
  ),
// Move from desktop to desktop with left hand (to facilitate moving windows on MacOS,
// which requires mouse-control left right)
  [_LOWER] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                      KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,_______,KC_PGUP, KC_UP ,KC_PGDN,_______,                     KC_APOS, KC_P7 , KC_P8 , KC_P9 ,KC_TAB ,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,KC_CAPS,KC_LEFT,KC_DOWN,KC_RGHT,_______,                     KC_LPRN, KC_P4 , KC_P5 , KC_P6 ,KC_COLN,KC_PLUS,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     _______,_______,_______, KC_SPC, KC_ENT,_______,_______,    KC_NLCK ,KC_RPRN, KC_P1 , KC_P2 , KC_P3 ,KC_MINS,_______,
  //`-------+-------+-------+-------+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                   _______,_______,_______,         _______, KC_P0 , KC_DOT
  //                              `-------+-------+-------'        `-------+-------+-------'
  ),
// Archive mail in Mail.app
#define KC_ARCH RGUI(KC_ENT)
// Symbols from standard egodox ez layout: https://configure.ergodox-ez.com/keyboard_layouts/new


  [_RAISE] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     _______,KC_F11 ,KC_F12 ,KC_F13 ,KC_F14 ,KC_F15 ,                     KC_F16 ,KC_F17 ,KC_F18 ,KC_F19 ,KC_F20 ,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,KC_EXLM, KC_AT ,KC_LCBR,KC_RCBR,KC_PIPE,                     KC_INS ,KC_PGDN,KC_PGUP,KC_MINS,KC_EQL ,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                     KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,_______,KC_BSLS,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,_______,    ,KC_HOME,KC_END ,_______,_______,KC_ARCH,_______,
  //`-------+-------+-------+-------+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                   _______,_______,_______,         _______,TG(_LOWER),_______
  //                              `-------+-------+-------'        `-------+-------+-------'
  ),

// should have window moving keys: on mac, KC_command option left right
    // move desktop: control alt gui left right left right
  [_ADJUST] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.              ,-------+-------+-------+-------+-------+-------.
     KC_WINDOWS ,_______    ,_______    ,_______    ,_______    ,_______    ,_______                               ,_______    ,_______    ,_______    ,_______    , KC_MACOS  ,
  //|-------+-------+-------+-------+-------+-------|              |-------+-------+-------+-------+-------+-------|
     _______ ,_______    ,_______    ,_______    ,_______    ,_______    ,_______                               ,_______    ,_______    ,_______    ,_______    ,_______    ,
  //|-------+-------+-------+-------+-------+-------|              |-------+-------+-------+-------+-------+-------|
     _______ ,_______    ,_______    ,_______    ,_______    ,_______    ,                       KC_WINLEFT ,KC_WINDISP ,KC_WINMAX  ,KC_WINRGHT ,_______    ,_______    ,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     _______ , QK_BOOT  ,_______    ,_______    ,_______    ,_______    ,_______    ,_______             ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,
  //`-------+-------+-------+-------+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                       _______,_______,_______,         _______,_______,_______
  //                  `-------+-------+-------'        `-------+-------+-------'
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

/* Windows needs the following AutoHotkey/similar scripts:

F21::’

*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    PROCESS_WINDOWS_MAC_KEY(KC_APOS, SS_TAP(X_F21), SS_LSFT(SS_LALT(SS_TAP(X_RBRACKET))));
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
