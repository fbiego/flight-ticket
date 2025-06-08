/**
 * @file jambojet.c
 */

/*********************
 *      INCLUDES
 *********************/
#include "jambojet.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void create_screens(void);
static void nav_book(lv_event_t *e);
static void nav_ticket(lv_event_t *e);
static void create_nav_bar(lv_obj_t *parent, lv_event_cb_t back_event_cb);

static void nav_home(lv_event_t *e);

static void on_unloaded_book(lv_event_t *e);
static void on_unloaded_ticket(lv_event_t *e);

/**********************
 *  STATIC VARIABLES
 **********************/

static lv_obj_t *home_screen = NULL;
static lv_obj_t *book_screen = NULL;
static lv_obj_t *ticket_screen = NULL;

/**********************
 *  GLOBAL VARIABLES
 **********************/

jambojet_flight_t my_flight = {
    .from_city = NBO_NAIROBI,
    .to_city = MBA_MOMBASA,
    .departure_time = 900, // 9:00 AM
    .arrival_time = 1030,   // 10:30 AM
    .cost = 7000            // Cost in KES
};

jambojet_ticket_t my_ticket = {
    .boarding_time = 830, // Boarding time in HHMM format
    .flight_number = "JM8669",
    .seat = "5A",
    .terminal = "1D",
    .gate = "4"
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void jambojet_init(const char *asset_path)
{
    jambojet_init_gen(asset_path);

    create_screens();
}

const char *jambojet_get_city_name(jambojet_city_t city)
{
    switch (city)
    {
    case NBO_NAIROBI:
        return "Nairobi (NBO)";
    case EDL_ELDORET:
        return "Eldoret (EDL)";
    case KIS_KISUMU:
        return "Kisumu (KIS)";
    case GOM_GOMA:
        return "Goma (GOM)";
    case LAU_LAMU:
        return "Lamu (LAU)";
    case MYD_MALINDI:
        return "Malindi (MYD)";
    case MBA_MOMBASA:
        return "Mombasa (MBA)";
    case UKA_UKUNDA:
        return "Ukunda (UKA)";
    case ZNZ_ZANZIBAR:
        return "Zanzibar (ZNZ)";
    default:
        return "Unknown City";
    }
}

void build_city_list(char *buffer, size_t buffer_size, int count, int skip_city) 
{
    buffer[0] = '\0';  // Clear the buffer

    for (int i = 0, added = 0; i <= ZNZ_ZANZIBAR && added < count; i++) {
        if (i == skip_city) continue;

        const char *name = jambojet_get_city_name((jambojet_city_t)i);

        size_t remaining = buffer_size - lv_strlen(buffer) - 1;
        lv_strncat(buffer, name, remaining);

        added++;

        if (added < count) {
            remaining = buffer_size - lv_strlen(buffer) - 1;
            lv_strncat(buffer, "\n", remaining);
        }
    }
}

const jambojet_flight_t* jambojet_get_flight(jambojet_city_t from, jambojet_city_t to) 
{
    int num_flights = sizeof(flight_db) / sizeof(flight_db[0]);
    for (int i = 0; i < num_flights; ++i) {
        if (flight_db[i].from_city == from && flight_db[i].to_city == to) {
            return &flight_db[i]; // Return the first match
        }
    }
    return NULL;
}

int jambojet_get_flights(jambojet_city_t from, jambojet_city_t to, const jambojet_flight_t** results, int max_results)
{
    int count = 0;
    int total = sizeof(flight_db) / sizeof(flight_db[0]);
    for (int i = 0; i < total && count < max_results; ++i) {
        if (flight_db[i].from_city == from && flight_db[i].to_city == to) {
            results[count++] = &flight_db[i];
        }
    }
    return count;
}

void load_ticket(lv_event_t *e)
{
    nav_ticket(e);
}

uint32_t time_diff(uint32_t time1, uint32_t time2) 
{
    // Extract hours and minutes
    uint32_t h1 = time1 / 100;
    uint32_t m1 = time1 % 100;
    uint32_t h2 = time2 / 100;
    uint32_t m2 = time2 % 100;

    // Convert to total minutes
    uint32_t total1 = h1 * 60 + m1;
    uint32_t total2 = h2 * 60 + m2;

    uint32_t diff = total2 - total1;
    if (diff < 0) diff += 24 * 60;  // Handle wraparound at midnight

    // Convert back to military time format
    uint32_t dh = diff / 60;
    uint32_t dm = diff % 60;
    return dh * 100 + dm;
}

uint32_t jambojet_get_boarding_time(uint32_t departure_time) 
{
    uint32_t hours = departure_time / 100;
    uint32_t minutes = departure_time % 100;

    int total_minutes = hours * 60 + minutes - 40;

    if (total_minutes < 0) {
        total_minutes += 24 * 60; // Wrap around midnight
    }

    uint32_t new_hours = total_minutes / 60;
    uint32_t new_minutes = total_minutes % 60;

    return new_hours * 100 + new_minutes;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void create_nav_bar(lv_obj_t *parent, lv_event_cb_t back_event_cb)
{
    lv_obj_t *nav_bar = lv_obj_create(parent);
    lv_obj_remove_style_all(nav_bar);
    lv_obj_set_size(nav_bar, LV_PCT(100), 50);
    lv_obj_set_align(nav_bar, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(nav_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(nav_bar, back_event_cb, LV_EVENT_CLICKED, NULL);
}

static void create_screens(void)
{

    home_screen = home_create();
    lv_obj_t *book_card = lv_obj_get_child(home_screen, 2);
    lv_obj_add_event_cb(book_card, nav_book, LV_EVENT_CLICKED, NULL);


    lv_screen_load(home_screen);
    
}

static void nav_home(lv_event_t *e)
{
    if (home_screen == NULL)
    {
        home_screen = home_create();
    }
    lv_screen_load(home_screen);
}

static void nav_book(lv_event_t *e)
{
    if (book_screen == NULL)
    {
        book_screen = book_create();
        create_nav_bar(book_screen, nav_home);
        lv_obj_add_event_cb(book_screen, on_unloaded_book, LV_EVENT_SCREEN_UNLOADED, NULL);
    }
    lv_screen_load(book_screen);
}

static void on_unloaded_book(lv_event_t *e)
{
    lv_obj_delete(book_screen);
    book_screen = NULL;
}



static void nav_ticket(lv_event_t *e)
{
    if (ticket_screen == NULL)
    {
        ticket_screen = ticket_create();
        create_nav_bar(ticket_screen, nav_book);
        lv_obj_add_event_cb(ticket_screen, on_unloaded_ticket, LV_EVENT_SCREEN_UNLOADED, NULL);
    }
    lv_screen_load(ticket_screen);
}

static void on_unloaded_ticket(lv_event_t *e)
{
    lv_obj_delete(ticket_screen);
    ticket_screen = NULL;
}