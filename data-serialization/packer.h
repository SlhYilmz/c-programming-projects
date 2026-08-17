/*
 ============================================================================
 Name        : packer.h
 Author      : Muhammed Salih Yilmaz
 Date        : September 2023
 Version     : 0.0.1
 Copyright   : 
 Description : packer header file. Written in C99.
 ============================================================================
 */

#ifndef PACKER_H
#define PACKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

/* Pool */
#define INITIAL_SIZE 256

#define member_size(type, member) sizeof(((type *)0)->member)

/* Data */
typedef struct BUFFER
{
	size_t size;
	void *data;
	size_t next;
	uint64_t checksum;
	int checksum_info_added;
} BUFFER;

extern BUFFER buf;

typedef struct STATUS
{
	int32_t max_mes_size;
	int32_t max_nb_logged_mes;
	int32_t max_nb_in_progress_mes;
	int32_t nb_logged_mes;
	int32_t nb_in_progress_mes;
	int32_t nb_aborted_mes;
} STATUS;

typedef struct LOG_TYPE
{
	int64_t id;
	uint32_t write_status;
	uint32_t severity;
	int64_t creation_time;
	unsigned char *log_data;
	uint64_t log_data_size;

	
} LOG_TYPE;

typedef struct LOGBOOK
{
	int64_t logbook_id;
	int32_t partition_id;
	char logbook_name[32];
	STATUS status;
	int32_t logbook_mutex;
	
	uint64_t logs_eng_counter;
	LOG_TYPE *logs_eng;

	// float my_float;
} LOGBOOK;

/* Serialize API. Kullaniciya cikilir. */
void* serialize(LOGBOOK logbook, size_t *length);

/* Deserialize API. Kullaniciya cikilir. */
void deserialize(LOGBOOK logbook, unsigned char msg[250], signed int length);

/* Buffer'in dolu olan size boyutunu dondurur. Length yani. */
size_t length_data();

/* Calculates the chekcsum. */
uint64_t calculate_checksum(const unsigned char *data, int size, BUFFER *buf);

/* Adds checksum info into the buffer. */
void add_checksum_info(BUFFER *buf);

/* Allocates memory for a new buffer. */
BUFFER *new_buffer();

/* Checks if there is space in the buffer for serialization or deseriazaliation */
int check_space(BUFFER *buf, size_t bytes);

/* Serialization Functions */
void serialize_int8_t(BUFFER *buf, int8_t x);
void deserialize_int8_t(BUFFER *buf, int8_t *x);

void serialize_uint8_t(BUFFER *buf, uint8_t x);
void deserialize_uint8_t(BUFFER *buf, uint8_t *x);


void serialize_int16_t(BUFFER *buf, int16_t x);
void deserialize_int16_t(BUFFER *buf, int16_t *x);

void serialize_uint16_t(BUFFER *buf, uint16_t x);
void deserialize_uint16_t(BUFFER *buf, uint16_t *x);


void serialize_int32_t(BUFFER *buf, int32_t x);
void deserialize_int32_t(BUFFER *buf, int32_t *x);

void serialize_uint32_t(BUFFER *buf, uint32_t x);
void deserialize_uint32_t(BUFFER *buf, uint32_t *x);


void serialize_int64_t(BUFFER *buf, int64_t x);
void deserialize_int64_t(BUFFER *buf, int64_t *x);

void serialize_uint64_t(BUFFER *buf, uint64_t x);
void deserialize_uint64_t(BUFFER *buf, uint64_t *x);


void serialize_float(BUFFER *buf, float x);
void deserialize_float(BUFFER *buf, float *x);

void serialize_double(BUFFER *buf, double x);
void deserialize_double(BUFFER *buf, double *x);


void serialize_string(BUFFER *buf, const char *str);
void deserialize_string(BUFFER *buf, char *str);


void serialize_STATUS(BUFFER *buf, STATUS status);
void deserialize_STATUS(BUFFER *buf, STATUS *status);


void serialize_LOG_TYPE(BUFFER *buf, LOG_TYPE log);
void deserialize_LOG_TYPE(BUFFER *buf, LOG_TYPE *log);


void serialize_LOGBOOK(BUFFER *buf, LOGBOOK logbook);
void deserialize_LOGBOOK(BUFFER *buf, LOGBOOK *logbook);


typedef void (*SerializeFunc)(BUFFER *, const void *);
typedef void (*DeserializeFunc)(BUFFER *, void *);

#define SERIALIZE(buf, data, size, serializeFunc) \
    do { \
        if (check_space(buf, size)) { \
            serializeFunc(buf, data); \
        } else { \
            printf("Serialization failed.\n"); \
        } \
    } while(0)

#define DESERIALIZE(buf, data, size, deserializeFunc) \
    do { \
        if (check_space(buf, size)) { \
            deserializeFunc(buf, data); \
        } else { \
            printf("Deserialization failed.\n"); \
        } \
    } while(0)

void serialize_generic(BUFFER *buf, const void *data, size_t size, SerializeFunc serializeFunc) {
    if (check_space(buf, size)) {
        serializeFunc(buf, data);
    } else {
        printf("Serialization failed.\n");
    }
}

void deserialize_generic(BUFFER *buf, void *data, size_t size, DeserializeFunc deserializeFunc) {
    if (check_space(buf, size)) {
        deserializeFunc(buf, data);
    } else {
        printf("Deserialization failed.\n");
    }
}

#define SERIALIZE_GENERIC(buf, data, size, type) \
    do { \
        serialize_generic(buf, data, size, (SerializeFunc)serialize_##type); \
    } while(0)

#define DESERIALIZE_GENERIC(buf, data, size, type) \
    do { \
        deserialize_generic(buf, data, size, (DeserializeFunc)deserialize_##type); \
    } while(0)


#endif /* PACKER_H */
