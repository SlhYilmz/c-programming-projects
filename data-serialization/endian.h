/*
 ============================================================================
 Name        : endian.h
 Author      : Muhammed Salih Yilmaz
 Date        : September 2023
 Version     : 0.0.1
 Copyright   : 
 Description : endian header file. Written in C99.
 ============================================================================
 */

#ifndef ENDIAN_H
#define ENDIAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * This header provides definitions for fixed-size integer types,
 * such as uint64_t, int32_t, and so on, which are used for precise data type sizes
 * regardless of the platform.
 */
#include <stdint.h>

/**
 * DEFINE ENDIANNES CONSTANTS
 * These lines define two constants LITTLE_ENDIAN and BIG_ENDIAN with integer values 1 and 2, respectively.
 * These constants will be used to indicate the endianness (byte order) of the system.
 */
#define LITTLE_ENDIAN 1
#define BIG_ENDIAN 2

/**
 * DETECT ENDIANNESS AT COMPILE TIME
 *
 * __BYTE_ORDER__ is a predefined macro that specifies the byte order of the target architecture at compile time.
 * It can have values like __ORDER_LITTLE_ENDIAN__ and __ORDER_BIG_ENDIAN__.
 *
 * The code checks if __BYTE_ORDER__ is defined and if the architecture supports the macros for little-endian and big-endian detection.
 *
 * If the system's byte order is little-endian, it defines ENDIANNESS as LITTLE_ENDIAN.
 * If it's big-endian, it defines ENDIANNESS as BIG_ENDIAN.
 *
 * If none of the conditions match (indicating an unsupported endianness),
 * it triggers a compilation error with the message "Unsupported endianness."
 */
#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#define ENDIANNESS LITTLE_ENDIAN
#elif defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#define ENDIANNESS BIG_ENDIAN
#else
#error "Unsupported endianness"
#endif

/**
 * NETWORK BYTE ORDER --> BIG ENDIAN
 * HOST BYTE ORDER --> LITTLE ENDIAN
 */
/*Custom function to convert endiannes.*/
/**********************/

/* host byte order --> network byte order (big-endian): signed int 8 bit */
int8_t hton_int8(int8_t value);

/* network byte order --> host byte order: signed int 8 bit */
int8_t ntoh_int8(int8_t value);

/* host byte order --> network byte order (big-endian): unsigned int 8 bit */
uint8_t hton_uint8(uint8_t value);

/* network byte order --> host byte order: unsigned int 8 bit */
uint8_t ntoh_uint8(uint8_t value);

/**********************/

/* host byte order --> network byte order (big-endian): signed int 16 bit */
int16_t hton_int16(int16_t value);

/* network byte order --> host byte order: signed int 16 bit */
int16_t ntoh_int16(int16_t value);

/* host byte order --> network byte order (big-endian): unsigned int 16 bit */
uint16_t hton_uint16(uint16_t value);

/* network byte order --> host byte order: unsigned int 16 bit */
uint16_t ntoh_uint16(uint16_t value);

/**********************/

/* host byte order --> network byte order (big-endian): signed int 32 bit */
int32_t hton_int32(int32_t value);

/* network byte order --> host byte order: signed int 32 bit */
int32_t ntoh_int32(int32_t value);

/* host byte order --> network byte order (big-endian): unsigned int 32 bit */
uint32_t hton_uint32(uint32_t value);

/* network byte order --> host byte order: unsigned int 32 bit */
uint32_t ntoh_uint32(uint32_t value);

/**********************/

/* host byte order --> network byte order (big-endian): signed int 64 bit */
int64_t hton_int64(int64_t value);

/* network byte order --> host byte order: signed int 64 bit */
int64_t ntoh_int64(int64_t value);

/* host byte order --> network byte order (big-endian): unsigned int 64 bit */
uint64_t hton_uint64(uint64_t value);

/* network byte order --> host byte order: unsigned int 64 bit */
uint64_t ntoh_uint64(uint64_t value);

/**********************/

/* host byte order --> network byte order (big-endian): float */
float hton_float(float value);

/* network byte order --> host byte order: float */
float ntoh_float(float value);

/* host byte order --> network byte order (big-endian): double */
double hton_double(double value);

/* network byte order --> host byte order: double */
double ntoh_double(double value);

#endif /* ENDIAN_H */
