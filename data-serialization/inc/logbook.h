/*
 ============================================================================
 Name        : logbook.h
 Author      : Muhammed Salih Yilmaz
 Date        : September 2023
 Version     : 0.0.1
 Copyright   : 
 Description : Public logbook types and serialization API. Written in C99.
 ============================================================================
 */

#ifndef LOGBOOK_H
#define LOGBOOK_H

#include <stddef.h>
#include <stdint.h>

typedef struct BUFFER
{
	size_t size;
	void *data;
	size_t next;
	uint64_t checksum;
	int checksum_info_added;
} BUFFER;

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

/* Public serialization API. */
void *serialize(LOGBOOK logbook, size_t *length);

/* Public deserialization API. */
void deserialize(LOGBOOK logbook, unsigned char msg[250], size_t length);

#endif /* LOGBOOK_H */
