/**
 * @file home_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "home_gen.h"
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

lv_obj_t * home_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_card_outline;
    static lv_style_t style_card_filled;
    static lv_style_t style_no_bar;

    static bool style_inited = false;

    if(!style_inited) {
        
        lv_style_init(&style_card_outline);
        lv_style_set_width(&style_card_outline, 440);
        lv_style_set_height(&style_card_outline, 200);
        lv_style_set_bg_color(&style_card_outline, lv_color_hex(0xFFFFFF));
        lv_style_set_border_color(&style_card_outline, lv_color_hex(0xE20177));
        lv_style_set_text_color(&style_card_outline, lv_color_hex(0xE20177));
        lv_style_set_text_font(&style_card_outline, &nn_regular_24);

        lv_style_init(&style_card_filled);
        lv_style_set_width(&style_card_filled, 440);
        lv_style_set_height(&style_card_filled, 200);
        lv_style_set_bg_color(&style_card_filled, lv_color_hex(0xE20177));
        lv_style_set_border_color(&style_card_filled, lv_color_hex(0xE20177));
        lv_style_set_text_color(&style_card_filled, lv_color_hex(0xFFFFFF));
        lv_style_set_text_font(&style_card_filled, &nn_regular_24);

        lv_style_init(&style_no_bar);
        lv_style_set_outline_opa(&style_no_bar, 0);
        lv_style_set_outline_width(&style_no_bar, 0);
        lv_style_set_bg_opa(&style_no_bar, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_1 = lv_obj_create(NULL);
    lv_obj_add_style(lv_obj_1, &style_light_theme, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_1, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_1);
    lv_image_set_src(lv_image_1, &logo);

    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_2, &style_card_filled, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_1, "Fel");
    
    lv_label_bind_text(lv_label_1, &subject_name, NULL);
    lv_obj_set_style_text_font(lv_label_1, &nn_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_2, "Eme");
    
    lv_label_bind_text(lv_label_2, &subject_tier, NULL);
    lv_obj_set_align(lv_label_2, LV_ALIGN_TOP_RIGHT);

    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_3, "JM2022000XXX");
    
    lv_label_bind_text(lv_label_3, &subject_loyalty, NULL);
    lv_obj_set_align(lv_label_3, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_style_text_font(lv_label_3, &nn_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_4, "58");
    
    lv_label_bind_text(lv_label_4, &subject_points, NULL);
    lv_obj_set_align(lv_label_4, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_style_text_font(lv_label_4, &nn_bold_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_5, "Points");
    lv_obj_set_align(lv_label_5, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_y(lv_label_5, -35);
    lv_obj_set_style_text_font(lv_label_5, &nn_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_image_2 = lv_image_create(lv_obj_2);
    lv_image_set_src(lv_image_2, &emerald_icon);
    lv_obj_set_align(lv_image_2, LV_ALIGN_CENTER);

    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_3, &style_card_outline, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_6, "Book Flight");
    lv_obj_set_align(lv_label_6, LV_ALIGN_TOP_MID);

    lv_obj_t * lv_image_3 = lv_image_create(lv_obj_3);
    lv_image_set_src(lv_image_3, &tickets_icon);
    lv_obj_set_align(lv_image_3, LV_ALIGN_CENTER);

    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_4, &style_card_outline, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flag(lv_obj_4, LV_OBJ_FLAG_HIDDEN, true);

    lv_obj_t * lv_label_7 = lv_label_create(lv_obj_4);
    lv_label_set_text(lv_label_7, "No Upcoming Flights");
    lv_obj_set_align(lv_label_7, LV_ALIGN_TOP_MID);

    lv_obj_t * lv_image_4 = lv_image_create(lv_obj_4);
    lv_image_set_src(lv_image_4, &luggage_icon);
    lv_obj_set_align(lv_image_4, LV_ALIGN_CENTER);

    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_5, &style_card_outline, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_5, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_5, &style_no_bar, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(lv_obj_5, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(lv_obj_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_8 = lv_label_create(lv_obj_5);
    lv_label_set_text(lv_label_8, "Upcoming Flights");
    lv_obj_set_align(lv_label_8, LV_ALIGN_TOP_MID);

    upcoming_create(lv_obj_5, "JM8668 to Eldoret • Terminal 1D", "Seat 2A • Boarding: 11:55");

    upcoming_create(lv_obj_5, "JM8668 to Eldoret • Terminal 1D", "Seat 2A • Boarding: 11:55");


    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_1;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/