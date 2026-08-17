/*
 ============================================================================
 Name        : helper.c
 Author      : Muhammed Salih Yilmaz
 Date        : September 2023
 Version     : 0.0.1
 Copyright   : 
 Description : helper.c file. Written in C99.
 ============================================================================
 */

#include "helper.h"

/* Prints the current condition of the logbook */
void dump_logbook(LOGBOOK logbook)
{
	printf("\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("logbook_id: %-20lld\n\r", (long long)logbook.logbook_id);
	printf("partition_id: %-20ld\n\r", (long)logbook.partition_id);
	printf("logbook_name: %s\t\n", logbook.logbook_name);

	printf("\n\rSTATUS\n\r");
	printf("max_mes_size: %-16ld\n\r", (long)logbook.status.max_mes_size);
	printf("max_nb_logged_mes: %-16ld\n\r", (long)logbook.status.max_nb_logged_mes);
	printf("max_nb_in_progress_mes: %-16ld\n\r", (long)logbook.status.max_nb_in_progress_mes);
	printf("nb_logged_mes: %-16ld\n\r", (long)logbook.status.nb_logged_mes);
	printf("nb_in_progress_mes: %-16ld\n\r", (long)logbook.status.nb_in_progress_mes);
	printf("nb_aborted_mes: %-16ld\n\r", (long)logbook.status.nb_aborted_mes);

	printf("\n\rLOGS ENG\n\r");
	if(logbook.logs_eng != NULL)
	{
		printf("LOG_TYPE.id  %lld\t\n", (long long)logbook.logs_eng->id);
		printf("LOG_TYPE.write_status  %lu\t\n", (unsigned long)logbook.logs_eng->write_status);
		printf("LOG_TYPE.severity  %lu\t\n", (unsigned long)logbook.logs_eng->severity);
		printf("LOG_TYPE.creation_time  %lld\t\n", (long long)logbook.logs_eng->creation_time);
		printf("LOG_TYPE.log_data  %s\t\n", logbook.logs_eng->log_data);
		printf("LOG_TYPE.log_data_size  %llu\t\n", (unsigned long long)logbook.logs_eng->log_data_size);
	}
	
	printf("-------------------------------------------------------------------------------\n");
}

/* Prints the contents of the buffer, which has serialized data. */
void print_buffer_raw_data(const BUFFER *buf)
{
	unsigned char *byte = ((unsigned char *)buf->data);
	printf("\n\r");
	size_t i = 0;
	for (i = 0; i < buf->next; i++)
	{
		printf("%02X ", (unsigned int)byte[i]); // Print as hexadecimal
								  // printf("i: %ld \n", i);
	}
}

/* Prints the buffer's content's inforrmation. size, length etc.*/
void print_buffer_info(const BUFFER *buf)
{
	printf("\n\r");
	printf("(buf->next): %zu \n\r", buf->next);
	printf("(buf->size): %zu \n\r", buf->size);
	printf("sizeof(buf->next): %zu \n\r", sizeof(buf->next));
	printf("sizeof(buf->size): %zu \n\r", sizeof(buf->size));
	printf("sizeof(buf->checksum): %zu \n\r", sizeof(buf->checksum));
	printf("Address of buf->data is %p \n\r", (buf->data));
	printf("\n\r");
}

/* Prints the sizes of each data-type. It is for the programmer, not the end-user. */
void print_sizes_of_types(void)
{
	printf("---------------------------\n");
	printf("|  int8_t:   %2zu           |\n", sizeof(int8_t));
	printf("| uint8_t:   %2zu           |\n", sizeof(uint8_t));
	printf("|  int16_t:  %2zu           |\n", sizeof(int16_t));
	printf("| uint16_t:  %2zu           |\n", sizeof(uint16_t));
	printf("|  int32_t:  %2zu           |\n", sizeof(int32_t));
	printf("| uint32_t:  %2zu           |\n", sizeof(uint32_t));
	printf("|  int64_t:  %2zu           |\n", sizeof(int64_t));
	printf("| uint64_t:  %2zu           |\n", sizeof(uint64_t));
	printf("| float:     %2zu           |\n", sizeof(float));
	printf("| double:    %2zu           |\n\r", sizeof(double));
	printf("| STATUS:    %2zu           |\n\r", sizeof(STATUS));

	printf("---------------------------\n");

	printf("| signed int:  %2zu         |\n", sizeof(signed int));
	printf("| signed char: %2zu         |\n", sizeof(signed char));
	printf("| signed long: %2zu         |\n", sizeof(signed long));
	printf("| signed long long: %2zu    |\n", sizeof(long long));
	printf("| unsigned int:  %2zu       |\n", sizeof(unsigned int));
	printf("| unsigned char: %2zu       |\n", sizeof(unsigned char));
	printf("| unsigned long: %2zu       |\n", sizeof(unsigned long));
	printf("| unsigned long long: %2zu  |\n", sizeof(unsigned long long));
	printf("| float:  %2zu              |\n", sizeof(float));
	printf("| double: %2zu              |\n\r", sizeof(double));
	printf("| STATUS: %2zu              |\n\r", sizeof(STATUS));

	printf("---------------------------\n");
}

/* Function to free memory for a buffer and its data */
void free_buffer(BUFFER *buf)
{
	if (buf != NULL)
	{
		if (buf->data != NULL)
		{
			free(buf->data);
		}
		free(buf);
	}
}

/* Custom fread function */
size_t new_fread(void *ptr, size_t size, size_t count, FILE *stream)
{
	size_t bytes_read = 0;
	size_t total_bytes = size * count;
	unsigned char *data = (unsigned char *)ptr;

	while (bytes_read < total_bytes)
	{
		int byte = getc(stream);
		if (byte == EOF)
		{
			break; /* End of file */
		}

		data[bytes_read++] = (unsigned char)byte;
	}

	return bytes_read / size; /* Return the number of items read */
}

/* Custom rewind function */
void new_rewind(FILE *stream)
{
	fseek(stream, 0, SEEK_SET);
}

/* Function to serialize a LOGBOOK and write it to a file */
void serialize_logbook_to_file(const char *filename, LOGBOOK logbook)
{
	/* Open the file for writing in binary mode */
	FILE *file = fopen(filename, "wb");
	if (file == NULL)
	{
		fprintf(stderr, "Failed to open the file for writing.\n");
		return;
	}

	/* Serialize the LOGBOOK data into a buffer */
	BUFFER *buf = new_buffer();
	serialize_LOGBOOK(buf, logbook);

	/* Write the content of the buffer into the file */
	size_t bytes_written = fwrite(buf->data, 1, buf->next, file);
	if (bytes_written != buf->next)
	{
		fprintf(stderr, "Failed to write the entire buffer to the file.\n");
		fclose(file);
		free(buf->data);
		free(buf);
		return;
	}

	/* Close the file */
	fclose(file);

	/* Clean up resources */
	free_buffer(buf);
}

/* Function to deserialize a LOGBOOK from a file */
void deserialize_logbook_from_file(const char *filename, LOGBOOK *logbook)
{
	/* Open the binary file for reading */
	FILE *file = fopen(filename, "rb");
	if (file == NULL)
	{
		fprintf(stderr, "Failed to open the file for reading.\n");
		return;
	}

	/* Get the file size to determine the buffer size */
	if (fseek(file, 0, SEEK_END) != 0)
	{
		fprintf(stderr, "Failed to determine the file size.\n");
		fclose(file);
		return;
	}

	long file_position = ftell(file);
	if ((file_position < 0L) || ((uintmax_t)file_position > (uintmax_t)SIZE_MAX))
	{
		fprintf(stderr, "File size is invalid or too large.\n");
		fclose(file);
		return;
	}

	size_t file_size = (size_t)file_position;
	new_rewind(file);

	// printf("size: %ld\n", file_size);

	/* Allocate a buffer to hold the file content */
	void *file_data = malloc(file_size);
	if (file_data == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		fclose(file);
		return;
	}

	/* Read the file content into the buffer */
	size_t bytes_read = new_fread(file_data, 1, file_size, file);
	if (bytes_read != file_size)
	{
		fprintf(stderr, "Failed to read the entire file.\n");
		fclose(file);
		free(file_data);
		return;
	}

	/* Close the file */
	fclose(file);

	/* Create a buffer for deserialization */
	BUFFER *buf = (BUFFER *)malloc(sizeof(BUFFER));
	if (buf == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		free(file_data);
		return;
	}
	buf->data = file_data;
	buf->size = file_size;
	buf->next = 0;

	/* Deserialize data from the buffer */
	deserialize_LOGBOOK(buf, logbook);

	/* Clean up resources */
	free_buffer(buf);
}
