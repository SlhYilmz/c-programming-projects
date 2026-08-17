#ifndef PACKER_H
#define PACKER_H

#include "../inc/logbook.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 256
#define member_size(type, member) sizeof(((type *)0)->member)

size_t length_data(void);
uint64_t calculate_checksum(const unsigned char *data, int size, BUFFER *buf);
void add_checksum_info(BUFFER *buf);
BUFFER *new_buffer(void);
int check_space(BUFFER *buf, size_t bytes);

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

#endif /* PACKER_H */
