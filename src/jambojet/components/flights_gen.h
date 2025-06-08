/**
 * @file flights_gen.h
 */

#ifndef FLIGHTS_H
#define FLIGHTS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * flights_create(lv_obj_t * parent, const char * from_city, const char * to_city, const char * departure, const char * arrival, const char * cost, const char * duration);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*FLIGHTS_H*/