/**
 * @file jambojet_gen.c
 */

/*********************
 *      INCLUDES
 *********************/
#include "jambojet_gen.h"

#if LV_USE_XML
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/* Global Styles */
lv_style_t style_dark_theme;
lv_style_t style_light_theme;
lv_style_t style_flex_ver;

/* Fonts */
// // lv_font_t * inter_16;
// // lv_font_t * inter_24;
// // lv_font_t * inter_30;
// // lv_font_t * nn_regular_16;
// // lv_font_t * nn_regular_24;
// // lv_font_t * nn_bold_24;
// // lv_font_t * nn_regular_30;
// // lv_font_t * nn_bold_30;

/* Images */
// // const void * logo;
// // const void * emerald_icon;
// // const void * tickets_icon;
// // const void * luggage_icon;
// // const void * airplane_icon;

/*Subjects*/
lv_subject_t subject_name;
lv_subject_t subject_seat;
lv_subject_t subject_flight;
lv_subject_t subject_terminal;
lv_subject_t subject_boarding;
lv_subject_t subject_gate;
lv_subject_t subject_tier;
lv_subject_t subject_loyalty;
lv_subject_t subject_points;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void jambojet_init_gen(const char * asset_path)
{
    char buf[256];

    /* Global Styles */
    static bool style_inited = false;

    if (!style_inited) {
        
        lv_style_init(&style_dark_theme);
        lv_style_set_bg_color(&style_dark_theme, lv_color_hex(0x000000));
        lv_style_set_text_color(&style_dark_theme, lv_color_hex(0xffffff));
        lv_style_set_pad_all(&style_dark_theme, 0);
        lv_style_set_radius(&style_dark_theme, 0);
        lv_style_set_border_width(&style_dark_theme, 0);
        lv_style_set_width(&style_dark_theme, lv_pct(100));
        lv_style_set_height(&style_dark_theme, lv_pct(100));

        lv_style_init(&style_light_theme);
        lv_style_set_bg_color(&style_light_theme, lv_color_hex(0xffffff));
        lv_style_set_pad_all(&style_light_theme, 0);
        lv_style_set_radius(&style_light_theme, 0);
        lv_style_set_border_width(&style_light_theme, 0);
        lv_style_set_width(&style_light_theme, lv_pct(100));
        lv_style_set_height(&style_light_theme, lv_pct(100));
        lv_style_set_text_color(&style_light_theme, lv_color_hex(0xE20177));
        lv_style_set_text_font(&style_light_theme, &nn_regular_24);

        lv_style_init(&style_flex_ver);
        lv_style_set_layout(&style_flex_ver, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_flex_ver, LV_FLEX_FLOW_COLUMN);
        lv_style_set_pad_row(&style_flex_ver, 50);
        lv_style_set_flex_track_place(&style_flex_ver, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_main_place(&style_flex_ver, LV_FLEX_ALIGN_START);
        lv_style_set_flex_cross_place(&style_flex_ver, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_all(&style_flex_ver, 50);

        style_inited = true;
    }

    /* Subjects */
    static char subject_name_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_name_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_name,
                            subject_name_buf,
                            subject_name_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "Felix Biego"
                          );
    static char subject_seat_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_seat_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_seat,
                            subject_seat_buf,
                            subject_seat_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "5A"
                          );
    static char subject_flight_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_flight_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_flight,
                            subject_flight_buf,
                            subject_flight_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "JM8669"
                          );
    static char subject_terminal_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_terminal_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_terminal,
                            subject_terminal_buf,
                            subject_terminal_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "1D"
                          );
    static char subject_boarding_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_boarding_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_boarding,
                            subject_boarding_buf,
                            subject_boarding_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "11:55"
                          );
    static char subject_gate_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_gate_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_gate,
                            subject_gate_buf,
                            subject_gate_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "4"
                          );
    static char subject_tier_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_tier_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_tier,
                            subject_tier_buf,
                            subject_tier_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "Emerald"
                          );
    static char subject_loyalty_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_loyalty_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_loyalty,
                            subject_loyalty_buf,
                            subject_loyalty_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "JM000XXX000"
                          );
    lv_subject_init_int(&subject_points, 673);

    /* Fonts */
    /* create tiny ttf font "inter_16" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/Inter_24pt_Regular.ttf");
	// 	// inter_16 = lv_tiny_ttf_create_file(buf, 16);
    /* create tiny ttf font "inter_24" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/Inter_24pt_Regular.ttf");
	// 	// inter_24 = lv_tiny_ttf_create_file(buf, 24);
    /* create tiny ttf font "inter_30" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/Inter_24pt_Regular.ttf");
	// 	// inter_30 = lv_tiny_ttf_create_file(buf, 30);
    /* create tiny ttf font "nn_regular_16" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Regular.ttf");
	// 	// nn_regular_16 = lv_tiny_ttf_create_file(buf, 16);
    /* create tiny ttf font "nn_regular_24" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Regular.ttf");
	// 	// nn_regular_24 = lv_tiny_ttf_create_file(buf, 24);
    /* create tiny ttf font "nn_bold_24" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Bold.ttf");
	// 	// nn_bold_24 = lv_tiny_ttf_create_file(buf, 24);
    /* create tiny ttf font "nn_regular_30" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Regular.ttf");
	// 	// nn_regular_30 = lv_tiny_ttf_create_file(buf, 30);
    /* create tiny ttf font "nn_bold_30" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Bold.ttf");
	// 	// nn_bold_30 = lv_tiny_ttf_create_file(buf, 30);

    /* Images */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "images/logo.png");
	// 	// logo = lv_strdup(buf);
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "images/emerald_icon.png");
	// 	// emerald_icon = lv_strdup(buf);
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "images/tickets_icon.png");
	// 	// tickets_icon = lv_strdup(buf);
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "images/luggage_icon.png");
	// 	// luggage_icon = lv_strdup(buf);
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "images/airplane_icon.png");
	// 	// airplane_icon = lv_strdup(buf);

    #if LV_USE_XML

        lv_xml_register_font(NULL, "inter_16", inter_16);
        lv_xml_register_font(NULL, "inter_24", inter_24);
        lv_xml_register_font(NULL, "inter_30", inter_30);
        lv_xml_register_font(NULL, "nn_regular_16", nn_regular_16);
        lv_xml_register_font(NULL, "nn_regular_24", nn_regular_24);
        lv_xml_register_font(NULL, "nn_bold_24", nn_bold_24);
        lv_xml_register_font(NULL, "nn_regular_30", nn_regular_30);
        lv_xml_register_font(NULL, "nn_bold_30", nn_bold_30);

        lv_xml_register_image(NULL, "logo", logo);
        lv_xml_register_image(NULL, "emerald_icon", emerald_icon);
        lv_xml_register_image(NULL, "tickets_icon", tickets_icon);
        lv_xml_register_image(NULL, "luggage_icon", luggage_icon);
        lv_xml_register_image(NULL, "airplane_icon", airplane_icon);

        lv_xml_register_subject(NULL, "name", &subject_name);
        lv_xml_register_subject(NULL, "seat", &subject_seat);
        lv_xml_register_subject(NULL, "flight", &subject_flight);
        lv_xml_register_subject(NULL, "terminal", &subject_terminal);
        lv_xml_register_subject(NULL, "boarding", &subject_boarding);
        lv_xml_register_subject(NULL, "gate", &subject_gate);
        lv_xml_register_subject(NULL, "tier", &subject_tier);
        lv_xml_register_subject(NULL, "loyalty", &subject_loyalty);
        lv_xml_register_subject(NULL, "points", &subject_points);

    #endif
}

/* callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/
