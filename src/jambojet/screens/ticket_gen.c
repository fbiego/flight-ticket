/**
 * @file ticket_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "ticket_gen.h"
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

lv_obj_t * ticket_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_card_outline;
    static lv_style_t style_card_filled;

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

        style_inited = true;
    }

    lv_obj_t * lv_obj_1 = lv_obj_create(NULL);
    lv_obj_add_style(lv_obj_1, &style_light_theme, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_1, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(lv_obj_1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(lv_obj_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_1);
    lv_image_set_src(lv_image_1, &logo);

    char departure_time[6];
    lv_snprintf(departure_time, sizeof(departure_time), "%02d:%02d", my_flight.departure_time / 100, my_flight.departure_time % 100);
    char arrival_time[6];
    lv_snprintf(arrival_time, sizeof(arrival_time), "%02d:%02d", my_flight.arrival_time / 100, my_flight.arrival_time % 100);
    char cost[16];
    lv_snprintf(cost, sizeof(cost), "KES %d", my_flight.cost);
    char duration[16];
    lv_snprintf(duration, sizeof(duration), "%dh %02dm", time_diff(my_flight.departure_time, my_flight.arrival_time) / 100, (time_diff(my_flight.departure_time, my_flight.arrival_time) % 100));
    lv_obj_t * flight = flights_create(lv_obj_1, jambojet_get_city_name(my_flight.from_city), jambojet_get_city_name(my_flight.to_city), departure_time, arrival_time, cost, duration);
        

    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_2, &style_card_outline, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_2, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(lv_obj_2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(lv_obj_2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_height(lv_obj_2, 600);

    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_1, "My Ticket");
    lv_obj_set_align(lv_label_1, LV_ALIGN_TOP_MID);

    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_2, "Felix Bo");
    
    lv_label_bind_text(lv_label_2, &subject_name, NULL);
    lv_obj_set_style_text_font(lv_label_2, &nn_bold_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_2);
    lv_obj_add_style(lv_obj_3, &style_light_theme, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(lv_obj_3, &nn_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_obj_3, lv_pct(100));
    lv_obj_set_style_pad_left(lv_obj_3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(lv_obj_3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_height(lv_obj_3, 80);

    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_3, "Flight No: JM8668");
    
    lv_label_bind_text(lv_label_3, &subject_flight, "Flight No: %s");

    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_4, "Seat: 5A");
    
    lv_label_bind_text(lv_label_4, &subject_seat, "Seat: %s");
    lv_obj_set_align(lv_label_4, LV_ALIGN_TOP_RIGHT);

    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_5, "Terminal: 1D");
    
    lv_label_bind_text(lv_label_5, &subject_terminal, "Terminal: %s");
    lv_obj_set_align(lv_label_5, LV_ALIGN_BOTTOM_LEFT);

    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_6, "Gate:3");
    
    lv_label_bind_text(lv_label_6, &subject_gate, "Gate: %s");
    lv_obj_set_align(lv_label_6, LV_ALIGN_BOTTOM_RIGHT);

    lv_obj_t * lv_label_7 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_7, "Boarding: 11:55");
    
    lv_label_bind_text(lv_label_7, &subject_boarding, "Boarding: %s");
    lv_obj_set_width(lv_label_7, lv_pct(100));
    lv_obj_set_style_pad_left(lv_label_7, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(lv_label_7, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_2);
    lv_obj_add_style(lv_obj_4, &style_card_outline, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(lv_obj_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_obj_4, 300);
    lv_obj_set_height(lv_obj_4, 300);
    
    lv_obj_t * qr = lv_qrcode_create(lv_obj_4);
    lv_qrcode_set_size(qr, 280);
    lv_qrcode_set_dark_color(qr, lv_color_hex(0xE20177));
    const char * qr_text = "https://jambojet.com/";
    lv_qrcode_update(qr, qr_text, lv_strlen(qr_text));
    lv_obj_set_align(qr, LV_ALIGN_CENTER);
    


    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_1;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/