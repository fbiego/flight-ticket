/**
 * @file jambojet.h
 */

#ifndef JAMBOJET_H
#define JAMBOJET_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "jambojet_gen.h"

/*********************
 *      DEFINES
 *********************/

#define MAX_CITY_STRING 256

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    NBO_NAIROBI,
    MBA_MOMBASA,
    EDL_ELDORET,
    KIS_KISUMU,
    GOM_GOMA,
    LAU_LAMU,
    MYD_MALINDI,
    UKA_UKUNDA,
    ZNZ_ZANZIBAR,
} jambojet_city_t;

typedef struct {
    jambojet_city_t from_city;
    jambojet_city_t to_city;
    uint32_t departure_time; // Millitary time in HHMM format
    uint32_t arrival_time;   // Millitary time in HHMM format
    uint32_t cost;           // Cost in KES
} jambojet_flight_t;

typedef struct {
    jambojet_flight_t flight;
    uint32_t boarding_time; // Boarding time in HHMM format
    const char * flight_number; // Flight number, e.g., "JM8669"
    const char seat[4];           // Seat number, e.g., "5A"
    const char terminal[4];       // Terminal, e.g., "1D"
    const char gate[4];           // Gate number, e.g., "4"
} jambojet_ticket_t;

/**********************
 * GLOBAL VARIABLES
 **********************/

 static const jambojet_flight_t flight_db[] = {
    // Nairobi (NBO) → Mombasa (MBA)
    { NBO_NAIROBI, MBA_MOMBASA,  630,  745, 7000 },
    { NBO_NAIROBI, MBA_MOMBASA,  825,  940, 7000 },
    { NBO_NAIROBI, MBA_MOMBASA, 1735, 1850, 6860 },
    { NBO_NAIROBI, MBA_MOMBASA, 1920, 2035, 6580 },
    { NBO_NAIROBI, MBA_MOMBASA, 1945, 2100, 6720 },

    // Nairobi (NBO) → Eldoret (EDL)
    { NBO_NAIROBI, EDL_ELDORET,  610,  710, 5500 },
    { NBO_NAIROBI, EDL_ELDORET,  720,  820, 5800 },
    { NBO_NAIROBI, EDL_ELDORET, 1210, 1310, 6000 },
    { NBO_NAIROBI, EDL_ELDORET, 1550, 1650, 6200 },
    { NBO_NAIROBI, EDL_ELDORET, 1830, 1930, 6500 },

    // Nairobi (NBO) → KISUMU (KIS)
    { NBO_NAIROBI, KIS_KISUMU,  600,  700, 9800 },
    { NBO_NAIROBI, KIS_KISUMU,  910,  1010, 10300 },
    { NBO_NAIROBI, KIS_KISUMU, 1250, 1350, 9800 },
    { NBO_NAIROBI, KIS_KISUMU, 1850, 1950, 8300 },

    // Nairobi (NBO) → Lamu (LAU)
    { NBO_NAIROBI, LAU_LAMU,  900, 1020, 8300 },

    // Eldoret (EDL) → Kisumu (KIS)
    { EDL_ELDORET, KIS_KISUMU,  1220, 1255, 4800 },
    { EDL_ELDORET, KIS_KISUMU,  1830, 1905, 5000 },

    // Kisumu (KIS) → Nairobi (NBO)
    { KIS_KISUMU, NBO_NAIROBI,  1210, 1320, 5200 },
    { KIS_KISUMU, NBO_NAIROBI,  1830, 1940, 5300 },

    // Nairobi (NBO) → Zanzibar (ZNZ)
    { NBO_NAIROBI, ZNZ_ZANZIBAR,  900, 1030, 11000 },
    { NBO_NAIROBI, ZNZ_ZANZIBAR, 1330, 1500, 11500 },

    // Mombasa (MBA) → Zanzibar (ZNZ)
    { MBA_MOMBASA, ZNZ_ZANZIBAR,  900, 1015, 7000 },

    // Mombasa (MBA) → Lamu (LAU)
    { MBA_MOMBASA, LAU_LAMU,  800,  900, 5000 },
    { MBA_MOMBASA, LAU_LAMU,  1200, 1300, 5200 },

    // Mombasa (MBA) → Malindi (MYD)
    { MBA_MOMBASA, MYD_MALINDI,  900,  950, 4000 },
    { MBA_MOMBASA, MYD_MALINDI,  1300, 1350, 4200 },

    // Mombasa (MBA) → Ukunda (UKA)
    { MBA_MOMBASA, UKA_UKUNDA,  800,  850, 3000 },
    { MBA_MOMBASA, UKA_UKUNDA,  1200, 1250, 3200 },

    // Mombasa (MBA) → Goma (GOM)
    { MBA_MOMBASA, GOM_GOMA,  900, 1030, 12000 },
    { MBA_MOMBASA, GOM_GOMA,  1300, 1430, 12500 },

    // Mombasa (MBA) → Eldoret (EDL)
    { MBA_MOMBASA, EDL_ELDORET,  800,  930, 7000 },
    { MBA_MOMBASA, EDL_ELDORET,  1200, 1330, 7200 },

    // Mombasa (MBA) → Kisumu (KIS)
    { MBA_MOMBASA, KIS_KISUMU,  900,  1030, 8000 },
    { MBA_MOMBASA, KIS_KISUMU,  1300, 1430, 8200 },

    // Mombasa (MBA) → Nairobi (NBO)
    { MBA_MOMBASA, NBO_NAIROBI,  600,  730, 7000 },
    { MBA_MOMBASA, NBO_NAIROBI,  900, 1030, 7200 },
    { MBA_MOMBASA, NBO_NAIROBI, 1300, 1430, 7500 },

    // Eldoret (EDL) → Nairobi (NBO)
    { EDL_ELDORET, NBO_NAIROBI,  610,  710, 5500 },
    { EDL_ELDORET, NBO_NAIROBI,  720,  820, 5800 },
    { EDL_ELDORET, NBO_NAIROBI, 1210, 1310, 6000 },
    { EDL_ELDORET, NBO_NAIROBI, 1550, 1650, 6200 },
    { EDL_ELDORET, NBO_NAIROBI, 1830, 1930, 6500 },

    // Eldoret (EDL) → Mombasa (MBA)
    { EDL_ELDORET, MBA_MOMBASA,  800,  930, 7000 },
    { EDL_ELDORET, MBA_MOMBASA,  1200, 1330, 7200 },

    // Eldoret (EDL) → Kisumu (KIS)
    { EDL_ELDORET, KIS_KISUMU,  1220, 1255, 4800 },
    { EDL_ELDORET, KIS_KISUMU,  1830, 1905, 5000 },

    // Kisumu (KIS) → Mombasa (MBA)
    { KIS_KISUMU, MBA_MOMBASA,  900,  1030, 8000 },
    { KIS_KISUMU, MBA_MOMBASA,  1300, 1430, 8200 },

    // Kisumu (KIS) → Eldoret (EDL)
    { KIS_KISUMU, EDL_ELDORET,  1220, 1255, 4800 },
    { KIS_KISUMU, EDL_ELDORET,  1830, 1905, 5000 },

    // Zanzibar (ZNZ) → Mombasa (MBA)
    { ZNZ_ZANZIBAR, MBA_MOMBASA,  900, 1015, 7000 },

    // Zanzibar (ZNZ) → Nairobi (NBO)
    { ZNZ_ZANZIBAR, NBO_NAIROBI,  900, 1030, 11000 },
    { ZNZ_ZANZIBAR, NBO_NAIROBI, 1330, 1500, 11500 },

    // Lamu (LAU) → Mombasa (MBA)
    { LAU_LAMU, MBA_MOMBASA,  800,  900, 5000 },
    { LAU_LAMU, MBA_MOMBASA,  1200, 1300, 5200 },

    // Lamu (LAU) → Nairobi (NBO)
    { LAU_LAMU, NBO_NAIROBI,  900, 1020, 8300 },

    // Malindi (MYD) → Mombasa (MBA)
    { MYD_MALINDI, MBA_MOMBASA,  900,  950, 4000 },
    { MYD_MALINDI, MBA_MOMBASA,  1300, 1350, 4200 },

    // Malindi (MYD) → Nairobi (NBO)
    { MYD_MALINDI, NBO_NAIROBI,  900, 1030, 11000 },

    // Ukunda (UKA) → Mombasa (MBA)
    { UKA_UKUNDA, MBA_MOMBASA,  800,  850, 3000 },
    { UKA_UKUNDA, MBA_MOMBASA,  1200, 1250, 3200 },


    // Ukunda (UKA) → Nairobi (NBO)
    { UKA_UKUNDA, NBO_NAIROBI,  900, 1020, 8300 },
    // Ukunda (UKA) → Mombasa (MBA)
    { UKA_UKUNDA, MBA_MOMBASA,  800,  850, 3000 },
    { UKA_UKUNDA, MBA_MOMBASA,  1200, 1250, 3200 },

    // Goma (GOM) → Mombasa (MBA)
    { GOM_GOMA, MBA_MOMBASA,  900, 1030, 12000 },
    { GOM_GOMA, MBA_MOMBASA,  1300, 1430, 12500 },  

    // Goma (GOM) → Nairobi (NBO)
    { GOM_GOMA, NBO_NAIROBI,  900, 1030, 11000 },
    { GOM_GOMA, NBO_NAIROBI, 1330, 1500, 11500 },


};


extern jambojet_flight_t my_flight;

extern jambojet_ticket_t my_ticket;


/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the component library
 */
void jambojet_init(const char * asset_path);

const char * jambojet_get_city_name(jambojet_city_t city);

void build_city_list(char *buffer, size_t buffer_size, int count, int skip_city);

void load_ticket(lv_event_t *e);

uint32_t time_diff(uint32_t time1, uint32_t time2);

const jambojet_flight_t* jambojet_get_flight(jambojet_city_t from, jambojet_city_t to);

int jambojet_get_flights(jambojet_city_t from, jambojet_city_t to, const jambojet_flight_t** results, int max_results);

uint32_t jambojet_get_boarding_time(uint32_t departure_time);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*JAMBOJET_H*/