/**
 * @file book_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "book_gen.h"
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

static char cities_arrival[MAX_CITY_STRING];

static lv_obj_t * lv_dropdown_1;
static lv_obj_t * lv_dropdown_2;
static lv_obj_t * lv_obj_3;
static lv_obj_t * lv_label_2;

static const jambojet_flight_t* matched_flights[5];

/***********************
 *  STATIC PROTOTYPES
 **********************/
static void generate_flights();
static void on_departure_selected(lv_event_t * e);
static void on_arrival_selected(lv_event_t * e);
static void on_selected(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * book_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_drop_down_main;
    static lv_style_t style_drop_down;
    static lv_style_t style_drop_down_selected;
    static lv_style_t style_no_bar;

    static bool style_inited = false;

    if(!style_inited) {
        
        lv_style_init(&style_drop_down_main);
        lv_style_set_width(&style_drop_down_main, 210);
        lv_style_set_height(&style_drop_down_main, 50);
        lv_style_set_bg_color(&style_drop_down_main, lv_color_hex(0xFFFFFF));
        lv_style_set_border_color(&style_drop_down_main, lv_color_hex(0xE20177));
        lv_style_set_text_color(&style_drop_down_main, lv_color_hex(0xE20177));
        lv_style_set_text_font(&style_drop_down_main, &nn_regular_24);

        lv_style_init(&style_drop_down);
        lv_style_set_width(&style_drop_down, 200);
        lv_style_set_height(&style_drop_down, 50);
        lv_style_set_bg_color(&style_drop_down, lv_color_hex(0xFFFFFF));
        lv_style_set_border_color(&style_drop_down, lv_color_hex(0xE20177));
        lv_style_set_text_color(&style_drop_down, lv_color_hex(0xE20177));
        lv_style_set_text_font(&style_drop_down, &nn_regular_24);

        lv_style_init(&style_drop_down_selected);
        // lv_style_set_width(&style_drop_down_selected, 180);
        // lv_style_set_height(&style_drop_down_selected, 50);
        lv_style_set_bg_color(&style_drop_down_selected, lv_color_hex(0xFFFFFF));
        lv_style_set_border_color(&style_drop_down_selected, lv_color_hex(0xE20177));
        lv_style_set_text_color(&style_drop_down_selected, lv_color_hex(0xE20177));
        lv_style_set_text_font(&style_drop_down_selected, &nn_regular_24);
        lv_style_set_pad_left(&style_drop_down_selected, 0);
        lv_style_set_pad_right(&style_drop_down_selected, 0);
        lv_style_set_text_align(&style_drop_down_selected, LV_TEXT_ALIGN_CENTER);

        lv_style_init(&style_no_bar);
        lv_style_set_outline_opa(&style_no_bar, 0);
        lv_style_set_outline_width(&style_no_bar, 0);
        lv_style_set_bg_opa(&style_no_bar, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_1 = lv_obj_create(NULL);
    lv_obj_add_style(lv_obj_1, &style_light_theme, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_2, &style_drop_down_main, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_2, &style_no_bar, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_obj_2, 440);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_obj_2, 50);

    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_1, "11/05/2025");
    lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);

    lv_dropdown_1 = lv_dropdown_create(lv_obj_1);
    lv_obj_add_style(lv_dropdown_1, &style_drop_down, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_x(lv_dropdown_1, 50);
    lv_obj_set_y(lv_dropdown_1, 120);

    static char cities_string[MAX_CITY_STRING];
    build_city_list(cities_string, MAX_CITY_STRING, 8, -1);
    lv_dropdown_set_options(lv_dropdown_1, cities_string);

    lv_dropdown_set_symbol(lv_dropdown_1, NULL);
    lv_obj_add_event_cb(lv_dropdown_1, on_departure_selected, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_t * list_1 = lv_dropdown_get_list(lv_dropdown_1);
    lv_obj_add_style(list_1, &style_drop_down_selected, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(list_1, &style_no_bar, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(list_1, lv_color_hex(0xE20177), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(list_1, lv_color_hex(0xE20177), LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_text_color(list_1, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    // lv_obj_set_height(list_1, LV_SIZE_CONTENT);
    lv_obj_set_style_max_height(list_1, 400, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_1);
    lv_image_set_src(lv_image_1, &airplane_icon);
    lv_obj_set_align(lv_image_1, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_image_1, 130);

    lv_dropdown_2 = lv_dropdown_create(lv_obj_1);
    lv_obj_add_style(lv_dropdown_2, &style_drop_down, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(lv_dropdown_2, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_x(lv_dropdown_2, -50);
    lv_obj_set_y(lv_dropdown_2, 120);
    build_city_list(cities_arrival, MAX_CITY_STRING, 8, 0);
    lv_dropdown_set_options(lv_dropdown_2, cities_arrival);
    lv_dropdown_set_symbol(lv_dropdown_2, NULL);
    lv_obj_add_event_cb(lv_dropdown_2, on_arrival_selected, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_t * list_2 = lv_dropdown_get_list(lv_dropdown_2);
    lv_obj_add_style(list_2, &style_drop_down_selected, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(list_2, &style_no_bar, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(list_2, lv_color_hex(0xE20177), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(list_2, lv_color_hex(0xE20177), LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_text_color(list_2, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_max_height(list_2, 400, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_2 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_2, "Available Flights");
    lv_obj_set_align(lv_label_2, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_2, 200);
    lv_obj_set_style_text_font(lv_label_2, &nn_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_3 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_3, &style_light_theme, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_3, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_3, &style_no_bar, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_obj_3, 540);
    lv_obj_set_height(lv_obj_3, 710);
    lv_obj_set_style_pad_all(lv_obj_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(lv_obj_3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(lv_obj_3, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_obj_3, 250);

    generate_flights();

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_1;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void generate_flights()
{
    lv_obj_clean(lv_obj_3);

    uint32_t index_1 = lv_dropdown_get_selected(lv_dropdown_1);
    uint32_t index_2 = lv_dropdown_get_selected(lv_dropdown_2);
    if (index_2 >= index_1) {
        index_2++;
    }
    jambojet_city_t city_1 = (jambojet_city_t)index_1;
    jambojet_city_t city_2 = (jambojet_city_t)index_2;

    int count = jambojet_get_flights(city_1, city_2, matched_flights, 5);

    if (count == 0) {
        lv_label_set_text(lv_label_2, "No Flights Available");
        return;
    } else {
        lv_label_set_text(lv_label_2, "Available Flights");
    }

    for (int i = 0; i < count; i++)
    {
        const jambojet_flight_t* f = matched_flights[i];
        char departure_time[6];
        lv_snprintf(departure_time, sizeof(departure_time), "%02d:%02d", f->departure_time / 100, f->departure_time % 100);
        char arrival_time[6];
        lv_snprintf(arrival_time, sizeof(arrival_time), "%02d:%02d", f->arrival_time / 100, f->arrival_time % 100);
        char cost[16];
        lv_snprintf(cost, sizeof(cost), "KES %d", f->cost);
        char duration[16];
        lv_snprintf(duration, sizeof(duration), "%dh %02dm", time_diff(f->departure_time, f->arrival_time) / 100, (time_diff(f->departure_time, f->arrival_time) % 100));
        lv_obj_t * flight = flights_create(lv_obj_3, jambojet_get_city_name(f->from_city), jambojet_get_city_name(f->to_city), departure_time, arrival_time, cost, duration);
        lv_obj_add_event_cb(lv_obj_get_child(flight, 6), on_selected, LV_EVENT_RELEASED, f);
    }
}

static void on_departure_selected(lv_event_t * e)
{
    lv_obj_t * dropdown = (lv_obj_t *)lv_event_get_target(e);
    uint32_t index = lv_dropdown_get_selected(dropdown);

    if (index < 4)
    {
        build_city_list(cities_arrival, MAX_CITY_STRING, 8, index);
    } else {
        build_city_list(cities_arrival, MAX_CITY_STRING, 4, index);
    }
    lv_dropdown_set_options(lv_dropdown_2, cities_arrival);

    generate_flights();
}

static void on_arrival_selected(lv_event_t * e)
{
    generate_flights();
}

static void on_selected(lv_event_t * e)
{
    lv_obj_t * slider = (lv_obj_t *)lv_event_get_target(e);
    uint32_t value = lv_slider_get_value(slider);

    jambojet_flight_t * flight = (jambojet_flight_t *)lv_event_get_user_data(e);

    my_flight.from_city = flight->from_city;
    my_flight.to_city = flight->to_city;
    my_flight.departure_time = flight->departure_time;
    my_flight.arrival_time = flight->arrival_time;
    my_flight.cost = flight->cost;

    uint32_t board = jambojet_get_boarding_time(my_flight.departure_time);
    char boarding_time[6];
    lv_snprintf(boarding_time, sizeof(boarding_time), "%02d:%02d", board / 100, board % 100);
    lv_subject_copy_string(&subject_boarding, boarding_time);

    uint32_t p = lv_subject_get_int(&subject_points) + my_flight.cost / 100;
    lv_subject_set_int(&subject_points, p);

    if (value > 90){
        load_ticket(e);
    }
}