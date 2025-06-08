/**
 * @file jambojet_gen.h
 */

#ifndef JAMBOJET_GEN_H
#define JAMBOJET_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl.h"

/*Include all the widget and components of this library*/
#include "components/flights_gen.h"
#include "components/upcoming_gen.h"
#include "screens/book_gen.h"
#include "screens/home_gen.h"
#include "screens/ticket_gen.h"

/*********************
 *      DEFINES
 *********************/

// TODO: should these definitions be prefixed with the project name?


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/* Global Styles */
extern lv_style_t style_dark_theme;
extern lv_style_t style_light_theme;
extern lv_style_t style_flex_ver;

/* Fonts */
LV_FONT_DECLARE(inter_16);
LV_FONT_DECLARE(inter_24);
LV_FONT_DECLARE(inter_30);
LV_FONT_DECLARE(nn_regular_16);
LV_FONT_DECLARE(nn_regular_24);
LV_FONT_DECLARE(nn_bold_24);
LV_FONT_DECLARE(nn_regular_30);
LV_FONT_DECLARE(nn_bold_30);

/* Images */
LV_IMAGE_DECLARE(logo);
LV_IMAGE_DECLARE(emerald_icon);
LV_IMAGE_DECLARE(tickets_icon);
LV_IMAGE_DECLARE(luggage_icon);
LV_IMAGE_DECLARE(airplane_icon);

/* Subjects */
extern lv_subject_t subject_name;
extern lv_subject_t subject_seat;
extern lv_subject_t subject_flight;
extern lv_subject_t subject_terminal;
extern lv_subject_t subject_boarding;
extern lv_subject_t subject_gate;
extern lv_subject_t subject_tier;
extern lv_subject_t subject_loyalty;
extern lv_subject_t subject_points;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/* callbacks */

/**
 * Initialize the component library
 */

void jambojet_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*JAMBOJET_GEN_H*/
