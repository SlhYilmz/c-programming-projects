/*
 ============================================================================
 Name        : helper.h
 Author      : Muhammed Salih Yilmaz
 Date        : September 2023
 Version     : 0.0.1
 Copyright   : 
 Description : helper header file. Written in C99.
 ============================================================================
 */

#ifndef HELPER_H
#define HELPER_H

#include "packer.h"

/* Prints the current condition of the logbook */
void dump_logbook(LOGBOOK logbook);

/* Prints the sizes of each data-type. It is for the programmer, not the end-user. */
void print_sizes_of_types();

/* Prints the contents of the buffer. */
void print_buffer_raw_data(const BUFFER *buf);

/* Prints the buffer's content's inforrmation. size, length etc.*/
void print_buffer_info(const BUFFER *buf);

/* Function to free memory for a buffer and its data */
void free_buffer(BUFFER *buf);

/* Custom fread function */
size_t new_fread(void *ptr, size_t size, size_t count, FILE *stream);

/* Custom rewind function */
void new_rewind(FILE *stream);

/* Function to serialize a LOGBOOK and write it to a file */
void serialize_logbook_to_file(const char *filename, LOGBOOK logbook);

/* Function to deserialize a LOGBOOK from a file */
void deserialize_logbook_from_file(const char *filename, LOGBOOK *logbook);

#endif /* HELPER_H */
