#include QMK_KEYBOARD_H
#include "config.h"
#include "keymap_common.h"

enum layer_names {
    _BASE,  // Base layer
    _MED,   // Media layer
    _NAV,   // Navigation layer
    _SYM,   // Symbol layer
    _NUM,   // Number layer
    _FUN,   // Function layer
    _RGB,   // RGB layer
    _PLN,   // Plain layer
    _MAC,   // Macro layer
    _MDR    // Media Right layer
};

#define _LOCK C(G(KC_Q)) // Lock the computer
#define _EURO S(A(KC_2)) // €

#define _LSFT_A LSFT_T(KC_A)
#define _LCTL_S LCTL_T(KC_S)
#define _LOPT_D LALT_T(KC_D)
#define _LGUI_F LGUI_T(KC_F)
#define _ALL_G ALL_T(KC_G)
#define _ALL_H ALL_T(KC_H)
#define _RGUI_J RGUI_T(KC_J)
#define _ROPT_K RALT_T(KC_K)
#define _RCTL_L RCTL_T(KC_L)
#define _RSFT_SCLN RSFT_T(KC_SCLN)

#define _RGB_ESC LT(_RGB, KC_ESC)
#define _MAC_MUT LT(_MAC, KC_MUTE)
#define _MED_ESC LT(_MED, KC_ESC)
#define _MED_SHT LT(_MED, KC_LSFT)
#define _NAV_SPC LT(_NAV, KC_SPC)
#define _SYM_TAB LT(_SYM, KC_TAB)
#define _SYM_ENT LT(_SYM, KC_ENT)
#define _NUM_BSP LT(_NUM, KC_BSPC)
#define _FUN_DEL LT(_FUN, KC_DEL)
#define _FUN_ESC LT(_FUN, KC_ESC)
#define _PLN_QUT LT(_PLN, KC_QUOT)
#define _MDR_MUT LT(_MDR, KC_MUTE)

#define _CMD_Q LGUI(KC_Q)
#define _CMD_W LGUI(KC_W)
#define _CMD_E LGUI(KC_E)
#define _CMD_R LGUI(KC_R)
#define _CMD_T LGUI(KC_T)
#define _CMD_S LGUI(KC_S)
#define _CMD_Z LGUI(KC_Z)
#define _CMD_X LGUI(KC_X)
#define _CMD_C LGUI(KC_C)
#define _CMD_V LGUI(KC_V)
#define _CMD_B LGUI(KC_B)
#define _CMD_F LGUI(KC_F)
#define _SPOTL LGUI(KC_SPC)

#define _HPR_1 HYPR(KC_1)
#define _HPR_2 HYPR(KC_2)
#define _HPR_3 HYPR(KC_3)
#define _HPR_4 HYPR(KC_4)
#define _HPR_5 HYPR(KC_5)
#define _HPR_LT HYPR(KC_LEFT)
#define _HPR_RT HYPR(KC_RGHT)
#define _HPR_UP HYPR(KC_UP)
#define _HPR_DN HYPR(KC_DOWN)


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_MED, KC_ESC):
            return TAPPING_TERM_THUMB;
        case LT(_NAV, KC_SPC):
            return TAPPING_TERM_THUMB;
        case LT(_SYM, KC_TAB):
            return TAPPING_TERM_THUMB;
        case LT(_SYM, KC_ENT):
            return TAPPING_TERM_THUMB;
        case LT(_NUM, KC_BSPC):
            return TAPPING_TERM_THUMB;
        case LT(_FUN, KC_DEL):
            return TAPPING_TERM_THUMB;
        default:
            return TAPPING_TERM;
    }
}

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, _NUM_BSP, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        MO(_RGB),   KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       /****/   KC_Y,          KC_U,       KC_I,       KC_O,       KC_P,       _MDR_MUT,
        MO(_PLN),   _LSFT_A,    _LCTL_S,    _LOPT_D,    _LGUI_F,    _ALL_G,     /****/   _ALL_H,        _RGUI_J,    _ROPT_K,    _RCTL_L,    _RSFT_SCLN, _PLN_QUT,
        MO(_MAC),   KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       /****/   KC_N,          KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    MO(_MAC),
                                                        _MED_ESC,   _NAV_SPC,   _SYM_TAB,   /****/   _SYM_ENT,      _NUM_BSP,   _FUN_DEL
    ),

    [_MED] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /****/   XXXXXXX,       KC_BRID,    KC_BRIU,    XXXXXXX,    XXXXXXX,    _______,
        _______,    KC_LSFT,    KC_LCTL,    KC_LOPT,    KC_LGUI,    KC_HYPR,    /****/   KC_MUTE,       KC_VOLD,    KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /****/   KC_MPLY,       KC_MPRV,    KC_MNXT,    XXXXXXX,    XXXXXXX,    _______,
                                                        _______,    _______,    _______,    /****/   _HPR_3,        _HPR_4,     _HPR_5
    ),

    [_NAV] = LAYOUT_split_3x6_3(
        _______,    _CMD_Q,     _CMD_W,    _CMD_F,      _CMD_R,     _CMD_T,     /****/   KC_PGUP,        KC_HOME,    KC_UP,      KC_END,     XXXXXXX,    _______,
        _______,    KC_LSFT,    _CMD_S,    KC_LOPT,     KC_LGUI,    KC_HYPR,    /****/   KC_PGDN,        KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,    XXXXXXX,
        _______,    _CMD_Z,     _CMD_X,    _CMD_C,      _CMD_V,     _CMD_B,     /****/   XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                       _______,    _______,     _______,    /****/   _______,        _______,    _______
    ),

    [_SYM] = LAYOUT_split_3x6_3(
        _______,    KC_CIRC,    KC_PIPE,    KC_LBRC,    KC_RBRC,    KC_SLSH,    /****/   KC_HASH,        KC_LT,      KC_GT,      KC_TILD,    XXXXXXX,    _______,
        _______,    KC_AT,      KC_EQL,     KC_LCBR,    KC_RCBR,    KC_ASTR,    /****/   KC_UNDS,        KC_LPRN,    KC_RPRN,    KC_COLN,    KC_SCLN,    XXXXXXX,
        _______,    KC_PERC,    KC_AMPR,    KC_QUOT,    KC_DQUO,    KC_MINS,    /****/   KC_GRV,         KC_DLR,     KC_BSLS,    KC_SLSH,    XXXXXXX,    _______,
                                                        KC_EXLM,    KC_QUES,    KC_MINS,    /****/   KC_PLUS,        KC_DOT,     KC_COMM
    ),

    [_NUM] = LAYOUT_split_3x6_3(
        _______,    KC_CIRC,    KC_P7,      KC_P8,      KC_P9,      KC_PSLS,    /****/   XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        _______,    _EURO,      KC_P4,      KC_P5,      KC_P6,      KC_PAST,    /****/   KC_HYPR,        KC_RGUI,    KC_ROPT,    KC_RCTL,    KC_RSFT,    XXXXXXX,
        _______,    KC_PERC,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    /****/   XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                        KC_PDOT,    KC_P0,      KC_PPLS,    /****/   _______,        _______,    _______
    ),

    [_FUN] = LAYOUT_split_3x6_3(
        _______,    _LOCK,      XXXXXXX,    _HPR_UP,    XXXXXXX,    SGUI(KC_3), /****/   XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        _______,    XXXXXXX,    _HPR_LT,    _HPR_DN,    _HPR_RT,    SGUI(KC_4), /****/   KC_HYPR,        KC_RGUI,    KC_ROPT,    KC_RCTL,    KC_RSFT,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    SGUI(KC_5), /****/   XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                        _HPR_1,     _SPOTL,     _HPR_2,     /****/   _______,        _______,    _______
    ),

    [_RGB] = LAYOUT_split_3x6_3(
        _______,    RGB_VAD,    RGB_VAI,    RGB_RMOD,   RGB_MOD,    XXXXXXX,    /****/   XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        _______,    RGB_TOG,    RGB_TOG,    RGB_SPD,    RGB_SPI,    XXXXXXX,    /****/   KC_HYPR,        KC_RGUI,    KC_ROPT,    KC_RCTL,    KC_RSFT,    XXXXXXX,
        _______,    RGB_SAD,    RGB_SAI,    RGB_HUD,    RGB_HUI,    XXXXXXX,    /****/   XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                        _______,    _______,    _______,    /****/   _______,        _______,    _______
    ),

    [_PLN] = LAYOUT_split_3x6_3(
        _______,    _______,    _______,    _______,    _______,    _______,    /****/   _______,        _______,    _______,    _______,    _______,    _______,
        _______,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       /****/   KC_H,           KC_J,       KC_K,       KC_L,       KC_SCLN,    XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    /****/   _______,        _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,    _______,    /****/   _______,        _______,    _______
    ),

    [_MAC] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    XXXXXXX,    DM_REC1,    DM_REC2,    XXXXXXX,    /****/   XXXXXXX,        DM_REC2,    DM_REC1,    XXXXXXX,    XXXXXXX,    _______,
        _______,    XXXXXXX,    XXXXXXX,    DM_PLY1,    DM_PLY2,    XXXXXXX,    /****/   XXXXXXX,        DM_PLY2,    DM_PLY1,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /****/   XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                        _______,    _______,    _______,    /****/   _______,        _______,    _______
    ),

    [_MDR] = LAYOUT_split_3x6_3(
        _______,    _______,    _______,    _______,    _______,    _______,    /****/   _______,        _______,    _______,    KC_VOLU,    KC_MNXT,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    /****/   _______,        _______,    _______,    KC_VOLD,    KC_MPLY,    XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    /****/   _______,        _______,    _______,    KC_MUTE,    KC_MPRV,    _______,
                                                        _______,    _______,    _______,    /****/   _______,        _______,    _______
    )
};
