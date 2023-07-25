#include QMK_KEYBOARD_H
#include "config.h"

#define LAYER_DEFAULT 0
#define LAYER_MEDIA 1
#define LAYER_NAV 2
#define LAYER_SYM 3
#define LAYER_NUM 4
#define LAYER_FN 5
#define LAYER_RGB 6
#define LAYER_PLAIN 7
#define LAYER_MACRO 8
#define LAYER_MEDIA_RIGHT 9

#define MY_LOCK C(G(KC_Q)) // Lock the computer
#define MY_EURO S(A(KC_2)) // €

#define MT_LSFT_A LSFT_T(KC_A)
#define MT_LCTL_S LCTL_T(KC_S)
#define MT_LOPT_D LALT_T(KC_D)
#define MT_LGUI_F LGUI_T(KC_F)
#define MT_ALL_G ALL_T(KC_G)
#define MT_ALL_H ALL_T(KC_H)
#define MT_RGUI_J RGUI_T(KC_J)
#define MT_ROPT_K RALT_T(KC_K)
#define MT_RCTL_L RCTL_T(KC_L)
#define MT_RSFT_SCLN RSFT_T(KC_SCLN)

#define LT_RGB_ESC LT(LAYER_RGB, KC_ESC)
#define LT_MAC_MUT LT(LAYER_MACRO, KC_MUTE)
#define LT_MED_ESC LT(LAYER_MEDIA, KC_ESC)
#define LT_NAV_SPC LT(LAYER_NAV, KC_SPC)
#define LT_SYM_TAB LT(LAYER_SYM, KC_TAB)
#define LT_SYM_ENT LT(LAYER_SYM, KC_ENT)
#define LT_NUM_BSP LT(LAYER_NUM, KC_BSPC)
#define LT_FUN_DEL LT(LAYER_FN, KC_DEL)
#define LT_PLN_QUT LT(LAYER_PLAIN, KC_QUOT)
#define LT_RMD_PPY LT(LAYER_MEDIA_RIGHT, KC_MPLY)

#define M_CMD_Q LGUI(KC_Q)
#define M_CMD_W LGUI(KC_W)
#define M_CMD_E LGUI(KC_E)
#define M_CMD_R LGUI(KC_R)
#define M_CMD_T LGUI(KC_T)
#define M_CMD_S LGUI(KC_S)
#define M_CMD_Z LGUI(KC_Z)
#define M_CMD_X LGUI(KC_X)
#define M_CMD_C LGUI(KC_C)
#define M_CMD_V LGUI(KC_V)
#define M_CMD_B LGUI(KC_B)
#define M_CMD_F LGUI(KC_F)
#define M_SPOTL LGUI(KC_SPC)

#define M_HPR_1 HYPR(KC_1)
#define M_HPR_2 HYPR(KC_2)
#define M_HPR_3 HYPR(KC_3)
#define M_HPR_4 HYPR(KC_4)
#define M_HPR_5 HYPR(KC_5)
#define M_HPR_LT HYPR(KC_LEFT)
#define M_HPR_RT HYPR(KC_RGHT)
#define M_HPR_UP HYPR(KC_UP)
#define M_HPR_DN HYPR(KC_DOWN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_DEFAULT] =
        LAYOUT_split_3x6_3(
            LT_RGB_ESC, KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       /****/   KC_Y,          KC_U,       KC_I,       KC_O,       KC_P,           LT_RMD_PPY,
            MO(7),      MT_LSFT_A,  MT_LCTL_S,  MT_LOPT_D,  MT_LGUI_F,  MT_ALL_G,   /****/   MT_ALL_H,      MT_RGUI_J,  MT_ROPT_K,  MT_RCTL_L,  MT_RSFT_SCLN,   LT_PLN_QUT,
            LT_MAC_MUT, KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       /****/   KC_N,          KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,        LT_MAC_MUT,
                                                            LT_MED_ESC, LT_NAV_SPC, LT_SYM_TAB, /****/   LT_SYM_ENT,    LT_NUM_BSP, LT_FUN_DEL
        ),

	[LAYER_MEDIA] =
        LAYOUT_split_3x6_3(
            _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /****/   XXXXXXX,       KC_BRID,    KC_BRIU,    XXXXXXX,    XXXXXXX,    _______,
            _______,    KC_LSFT,    KC_LCTL,    KC_LOPT,    KC_LGUI,    KC_HYPR,    /****/   KC_MUTE,       KC_VOLD,    KC_VOLU,    KC_MUTE,    XXXXXXX,    XXXXXXX,
            _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /****/   XXXXXXX,       KC_MPRV,    KC_MNXT,    XXXXXXX,    XXXXXXX,    _______,
                                                            _______,    _______,    _______,    /****/   M_HPR_3,       M_HPR_4,    M_HPR_5
           ),

	[LAYER_NAV] =
        LAYOUT_split_3x6_3(
            _______,    M_CMD_Q,    M_CMD_W,    M_CMD_F,    M_CMD_R,    M_CMD_T,    /****/  KC_PGUP,        KC_HOME,    KC_UP,      KC_END,     XXXXXXX,    _______,
            _______,    KC_LSFT,    M_CMD_S,    KC_LOPT,    KC_LGUI,    KC_HYPR,    /****/  KC_PGDN,        KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,    XXXXXXX,
            _______,    M_CMD_Z,    M_CMD_X,    M_CMD_C,    M_CMD_V,    M_CMD_B,    /****/  XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                            _______,    _______,    _______,    /****/  _______,        _______,    _______
           ),

	[LAYER_SYM] =
        LAYOUT_split_3x6_3(
            _______,    KC_CIRC,    KC_PIPE,    KC_LBRC,    KC_RBRC,    KC_SLSH,    /****/  KC_HASH,        KC_LT,      KC_GT,      KC_TILD,    XXXXXXX,    _______,
            _______,    KC_AT,      KC_EQL,     KC_LCBR,    KC_RCBR,    KC_ASTR,    /****/  KC_UNDS,        KC_LPRN,    KC_RPRN,    KC_COLN,    KC_SCLN,    XXXXXXX,
            _______,    KC_PERC,    KC_AMPR,    KC_QUOT,    KC_DQUO,    KC_MINS,    /****/  KC_GRV,         KC_DLR,     KC_BSLS,    KC_SLSH,    XXXXXXX,    _______,
                                                            KC_EXLM,    KC_QUES,    KC_MINS,    /****/  KC_PLUS,        KC_DOT,     KC_COMM
        ),

	[LAYER_NUM] =
        LAYOUT_split_3x6_3(
            _______,    KC_CIRC,    KC_P7,      KC_P8,      KC_P9,      KC_PSLS,    /****/  XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
            _______,    MY_EURO,    KC_P4,      KC_P5,      KC_P6,      KC_PAST,    /****/  KC_HYPR,        KC_RGUI,    KC_ROPT,    KC_RCTL,    KC_RSFT,    XXXXXXX,
            _______,    KC_PERC,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    /****/  XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                            KC_PDOT,    KC_P0,      KC_PPLS,    /****/  _______,        _______,    _______
        ),

	[LAYER_FN] =
        LAYOUT_split_3x6_3(
            _______,    MY_LOCK,    XXXXXXX,    M_HPR_UP,   XXXXXXX,    SGUI(KC_3), /****/  XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
            _______,    XXXXXXX,    M_HPR_LT,   M_HPR_DN,   M_HPR_RT,   SGUI(KC_4), /****/  KC_HYPR,        KC_RGUI,    KC_ROPT,    KC_RCTL,    KC_RSFT,    XXXXXXX,
            _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    SGUI(KC_5), /****/  XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                            M_HPR_1,    M_SPOTL,    M_HPR_2,    /****/  _______,        _______,    _______
        ),

	[LAYER_RGB] =
        LAYOUT_split_3x6_3(
            _______,    RGB_VAD,    RGB_VAI,    RGB_RMOD,   RGB_MOD,    XXXXXXX,    /****/  XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
            _______,    RGB_TOG,    RGB_TOG,    RGB_SPD,    RGB_SPI,    XXXXXXX,    /****/  KC_HYPR,        KC_RGUI,    KC_ROPT,    KC_RCTL,    KC_RSFT,    XXXXXXX,
            _______,    RGB_SAD,    RGB_SAI,    RGB_HUD,    RGB_HUI,    XXXXXXX,    /****/  XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                            _______,    _______,    _______,    /****/  _______,        _______,    _______
        ),

	[LAYER_PLAIN] =
        LAYOUT_split_3x6_3(
            _______,    _______,    _______,    _______,    _______,    _______,    /****/  _______,        _______,    _______,    _______,    _______,    _______,
            _______,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       /****/  KC_H,           KC_J,       KC_K,       KC_L,       KC_SCLN,    XXXXXXX,
            _______,    _______,    _______,    _______,    _______,    _______,    /****/  _______,        _______,    _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    /****/  _______,        _______,    _______
        ),

	[LAYER_MACRO] =
        LAYOUT_split_3x6_3(
            _______,    XXXXXXX,    XXXXXXX,    DM_REC1,    DM_REC2,    XXXXXXX,    /****/  XXXXXXX,        DM_REC2,    DM_REC1,    XXXXXXX,    XXXXXXX,    _______,
            _______,    XXXXXXX,    XXXXXXX,    DM_PLY1,    DM_PLY2,    XXXXXXX,    /****/  XXXXXXX,        DM_PLY2,    DM_PLY1,    XXXXXXX,    XXXXXXX,    XXXXXXX,
            _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /****/  XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                                                            _______,    _______,    _______,    /****/  _______,        _______,    _______
        ),

	[LAYER_MEDIA_RIGHT] =
        LAYOUT_split_3x6_3(
            _______,    _______,    _______,    _______,    _______,    _______,    /****/  _______,        _______,    _______,    KC_VOLU,    KC_MNXT,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,    /****/  _______,        _______,    _______,    KC_VOLD,    KC_MPRV,    XXXXXXX,
            _______,    _______,    _______,    _______,    _______,    _______,    /****/  _______,        _______,    _______,    KC_MUTE,    KC_MUTE,    _______,
                                                            _______,    _______,    _______,    /****/  _______,        _______,    _______
        )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_ESC):
            return TAPPING_TERM_THUMB;
        case LT(2, KC_SPC):
            return TAPPING_TERM_THUMB;
        case LT(3, KC_TAB):
            return TAPPING_TERM_THUMB;
        case LT(3, KC_ENT):
            return TAPPING_TERM_THUMB;
        case LT(4, KC_BSPC):
            return TAPPING_TERM_THUMB;
        case LT(5, KC_DEL):
            return TAPPING_TERM_THUMB;
        default:
            return TAPPING_TERM;
    }
}
