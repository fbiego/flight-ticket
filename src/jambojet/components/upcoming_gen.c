/**
 * @file upcoming_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "upcoming_gen.h"
#include "../ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * upcoming_create(lv_obj_t * parent, const char * info1, const char * info2)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_card_outline;
    static lv_style_t style_slider;
    static lv_style_t style_slider_indic;

    static bool style_inited = false;

    if (!style_inited) {
        
        lv_style_init(&style_card_outline);
        lv_style_set_width(&style_card_outline, 440);
        lv_style_set_height(&style_card_outline, 55);
        lv_style_set_bg_color(&style_card_outline, lv_color_hex(0xFFFFFF));
        lv_style_set_border_color(&style_card_outline, lv_color_hex(0xE20177));
        lv_style_set_border_width(&style_card_outline, 1);
        lv_style_set_border_side(&style_card_outline, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_radius(&style_card_outline, 0);
        lv_style_set_text_color(&style_card_outline, lv_color_hex(0xE20177));
        lv_style_set_text_font(&style_card_outline, &nn_regular_16);
        lv_style_set_pad_left(&style_card_outline, 10);
        lv_style_set_pad_right(&style_card_outline, 10);
        lv_style_set_pad_top(&style_card_outline, 5);
        lv_style_set_pad_bottom(&style_card_outline, 5);

        lv_style_init(&style_slider);
        lv_style_set_width(&style_slider, 380);
        lv_style_set_height(&style_slider, 2);
        lv_style_set_bg_color(&style_slider, lv_color_hex(0xE20177));

        lv_style_init(&style_slider_indic);
        lv_style_set_bg_color(&style_slider_indic, lv_color_hex(0xE20177));
        lv_style_set_border_color(&style_slider_indic, lv_color_hex(0xE20177));
        lv_style_set_bg_opa(&style_slider_indic, 200);
        lv_style_set_width(&style_slider_indic, 20);

        style_inited = true;
    }

    lv_obj_t * lv_obj_1 = lv_obj_create(parent);
        lv_obj_add_style(lv_obj_1, &style_card_outline, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_1);
    lv_image_set_src(lv_image_1, &airplane_icon);
    lv_obj_set_align(lv_image_1, LV_ALIGN_RIGHT_MID);

    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_1, info1);

    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_2, info2);
    lv_obj_set_align(lv_label_2, LV_ALIGN_BOTTOM_LEFT);


    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_1;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/