/*
 ============================================================================
 Name        : endian.c
 Author      : Muhammed Salih Yilmaz
 Date        : September 2023
 Version     : 0.0.1
 Copyright   : 
 Description : endian.c file. Written in C99.
 ============================================================================
 */

#include "endian.h"

/**
 * NETWORK BYTE ORDER --> BIG ENDIAN
 * HOST BYTE ORDER --> LITTLE ENDIAN
 */
/*Custom function to convert endiannes.*/
/**********************/

/* host byte order --> network byte order (big-endian): signed int 8 bit */
int8_t hton_int8(int8_t value)
{
    return value; /* No byte order change for int8_t */
}

/* network byte order --> host byte order: signed int 8 bit */
int8_t ntoh_int8(int8_t value)
{
    return value; /* No byte order change for int8_t */
}

/* host byte order --> network byte order (big-endian): unsigned int 8 bit */
uint8_t hton_uint8(uint8_t value)
{
    return value; /* No byte order change for uint8_t */
}

/* network byte order --> host byte order: unsigned int 8 bit */
uint8_t ntoh_uint8(uint8_t value)
{
    return value; /* No byte order change for uint8_t */
}

/**********************/

/* host byte order --> network byte order (big-endian): signed int 16 bit */
int16_t hton_int16(int16_t value)
{
#if ENDIANNESS == LITTLE_ENDIAN
    return ((value & 0x00FF) << 8) | ((value & 0xFF00) >> 8);
#else
    return value;
#endif
}

/*  network byte order --> host byte order: signed int 16 bit */
int16_t ntoh_int16(int16_t value)
{
    return hton_int16(value); /* For most systems, hton_int16 and ntoh_int16 are the same */
}

/* host byte order --> network byte order (big-endian): unsigned int 16 bit */
uint16_t hton_uint16(uint16_t value)
{
#if ENDIANNESS == LITTLE_ENDIAN
    return ((value & 0x00FFU) << 8) | ((value & 0xFF00U) >> 8);
#else
    return value;
#endif
}

/* network byte order --> host byte order: unsigned int 16 bit */
uint16_t ntoh_uint16(uint16_t value)
{
    return hton_uint16(value); /* For most systems, hton_uint16 and ntoh_uint16 are the same */
}

/**********************/

/* host byte order --> network byte order (big-endian): signed int 32 bit */
int32_t hton_int32(int32_t value)
{
#if ENDIANNESS == LITTLE_ENDIAN
    return ((value & 0x000000FF) << 24) |
           ((value & 0x0000FF00) << 8) |
           ((value & 0x00FF0000) >> 8) |
           ((value & 0xFF000000) >> 24);
#else
    return value;
#endif
}

/* network byte order --> host byte order: signed int 32 bit */
int32_t ntoh_int32(int32_t value)
{
    return hton_int32(value); /* For most systems, ntoh_int32 and hton_int32 are the same */
}

/* host byte order --> network byte order (big-endian): unsigned int 32 bit */
uint32_t hton_uint32(uint32_t value)
{
#if ENDIANNESS == LITTLE_ENDIAN
    return ((value & 0x000000FFU) << 24) |
           ((value & 0x0000FF00U) << 8) |
           ((value & 0x00FF0000U) >> 8) |
           ((value & 0xFF000000U) >> 24);
#else
    return value;
#endif
}

/* network byte order --> host byte order: unsigned int 32 bit */
uint32_t ntoh_uint32(uint32_t value)
{
    return hton_uint32(value); /* For most systems, hton_uint32 and ntoh_uint32 are the same */
}

/**********************/

/* host byte order --> network byte order (big-endian): signed int 64 bit */
int64_t hton_int64(int64_t value)
{
#if ENDIANNESS == LITTLE_ENDIAN
    return ((value & 0x00000000000000FFLL) << 56) |
           ((value & 0x000000000000FF00LL) << 40) |
           ((value & 0x0000000000FF0000LL) << 24) |
           ((value & 0x00000000FF000000LL) << 8) |
           ((value & 0x000000FF00000000LL) >> 8) |
           ((value & 0x0000FF0000000000LL) >> 24) |
           ((value & 0x00FF000000000000LL) >> 40) |
           ((value & 0xFF00000000000000LL) >> 56);
#else
    return value;
#endif
}

/* network byte order --> host byte order: signed int 64 bit */
int64_t ntoh_int64(int64_t value)
{
    return hton_int64(value); /* For most systems, hton_int64 and ntoh_int64 are the same */
}

/* host byte order --> network byte order (big-endian): unsigned int 64 bit */
uint64_t hton_uint64(uint64_t value)
{
#if ENDIANNESS == LITTLE_ENDIAN
    return ((value & 0x00000000000000FFULL) << 56) |
           ((value & 0x000000000000FF00ULL) << 40) |
           ((value & 0x0000000000FF0000ULL) << 24) |
           ((value & 0x00000000FF000000ULL) << 8) |
           ((value & 0x000000FF00000000ULL) >> 8) |
           ((value & 0x0000FF0000000000ULL) >> 24) |
           ((value & 0x00FF000000000000ULL) >> 40) |
           ((value & 0xFF00000000000000ULL) >> 56);
#else
    return value;
#endif
}

/* network byte order --> host byte order: unsigned int 64 bit */
uint64_t ntoh_uint64(uint64_t value)
{
    return hton_uint64(value); /* For most systems, hton_uint64 and ntoh_uint64 are the same */
}

/**********************/

/* host byte order --> network byte order (big-endian): float */
float hton_float(float value)
{
    uint32_t temp = *((uint32_t*)&value);
    temp = hton_uint32(temp);
    return *((float*)&temp);
}

/* network byte order --> host byte order: float */
float ntoh_float(float value)
{
    uint32_t temp = *((uint32_t*)&value);
    temp = ntoh_uint32(temp);
    return *((float*)&temp);
}

/**
 * The reason for using uint64_t is that the IEEE 754 standard defines the bit layout for double precision floating-point numbers.
 * It has a 64-bit representation, with specific bit patterns for the sign, exponent, and mantissa.
 * When you use uint64_t, you can manipulate the bits directly to convert the double to network byte order and vice versa.
 *
 * Using uint64_t allows you to perform the necessary bit-level operations required for proper conversion.
 * It ensures that the bit representation of the double remains intact during the conversion process.
 *
 * If you try to use double directly for these operations, you might encounter issues
 * related to the way floating-point numbers are stored and handled by the system's architecture.
 * Using uint64_t ensures that the bit-level representation is correctly preserved during the conversion process,
 * which is essential for network communication and data consistency across different systems.
 */

/* host byte order --> network byte order (big-endian): double */
double hton_double(double value)
{
    uint64_t temp;
    memcpy(&temp, &value, sizeof(uint64_t));
    temp = hton_int64(temp);
    memcpy(&value, &temp, sizeof(uint64_t));
    return value;
}

/* network byte order --> host byte order: double */
double ntoh_double(double value)
{
    uint64_t temp;
    memcpy(&temp, &value, sizeof(uint64_t));
    temp = ntoh_uint64(temp);
    memcpy(&value, &temp, sizeof(uint64_t));
    return value;
}
