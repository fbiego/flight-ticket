/**
 * @file flights_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "flights_gen.h"
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

lv_obj_t * flights_create(lv_obj_t * parent, const char * from_city, const char * to_city, const char * departure, const char * arrival, const char * cost, const char * duration)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_card_outline;
    static lv_style_t style_slider;
    static lv_style_t style_slider_indic;
    static lv_style_t style_slider_knob;

    static bool style_inited = false;

    if (!style_inited) {
        
        lv_style_init(&style_card_outline);
        lv_style_set_width(&style_card_outline, 440);
        lv_style_set_height(&style_card_outline, 110);
        lv_style_set_bg_color(&style_card_outline, lv_color_hex(0xFFFFFF));
        lv_style_set_border_color(&style_card_outline, lv_color_hex(0xE20177));
        lv_style_set_border_width(&style_card_outline, 2);
        lv_style_set_radius(&style_card_outline, 10);
        lv_style_set_text_color(&style_card_outline, lv_color_hex(0xE20177));
        lv_style_set_text_font(&style_card_outline, &nn_regular_24);
        lv_style_set_pad_all(&style_card_outline, 10);

        lv_style_init(&style_slider);
        lv_style_set_width(&style_slider, 380);
        lv_style_set_height(&style_slider, 2);
        lv_style_set_bg_color(&style_slider, lv_color_hex(0xE20177));

        lv_style_init(&style_slider_indic);
        lv_style_set_bg_color(&style_slider_indic, lv_color_hex(0xE20177));
        lv_style_set_border_color(&style_slider_indic, lv_color_hex(0x54022c));
        lv_style_set_bg_opa(&style_slider_indic, 155);
        lv_style_set_width(&style_slider_indic, 20);

        lv_style_init(&style_slider_knob);
        lv_style_set_bg_color(&style_slider_knob, lv_color_hex(0xE20177));
        lv_style_set_border_color(&style_slider_knob, lv_color_hex(0xE20177));
        lv_style_set_width(&style_slider_knob, 24);
        lv_style_set_bg_opa(&style_slider_knob, 0);
        lv_style_set_pad_all(&style_slider_knob, 20);
        lv_style_set_bg_image_src(&style_slider_knob, &airplane_icon);

        style_inited = true;
    }

    lv_obj_t * lv_obj_1 = lv_obj_create(parent);
        lv_obj_add_style(lv_obj_1, &style_card_outline, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_1, departure);

    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_2, from_city);
    lv_obj_set_align(lv_label_2, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_style_text_font(lv_label_2, &nn_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_3, arrival);
    lv_obj_set_align(lv_label_3, LV_ALIGN_TOP_RIGHT);

    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_4, to_city);
    lv_obj_set_align(lv_label_4, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_style_text_font(lv_label_4, &nn_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_5, duration);
    lv_obj_set_align(lv_label_5, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_text_font(lv_label_5, &nn_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_6, cost);
    lv_obj_set_align(lv_label_6, LV_ALIGN_TOP_MID);
    lv_obj_set_style_text_font(lv_label_6, &nn_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_slider_1 = lv_slider_create(lv_obj_1);
    lv_obj_add_style(lv_slider_1, &style_slider, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_slider_1, &style_slider_indic, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_slider_1, &style_slider_knob, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_align(lv_slider_1, LV_ALIGN_CENTER);
    lv_slider_set_value(lv_slider_1, 10, LV_ANIM_OFF);


    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_1;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/