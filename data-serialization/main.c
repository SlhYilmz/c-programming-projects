/*
 ============================================================================
 Name        : main.c
 Author      : Muhammed Salih Yilmaz
 Date        : September 2023
 Version     : 0.0.1
 Copyright   : 
 Description : main.c file. Written in C99.
 ============================================================================
 */

#include "packer.h"
#include "endian.h"
#include "helper.h"

#define IS_LITTLE_ENDIAN (*(uint16_t *) "\0\x01" == 1U)

/* Main */
int main(void)
{
	LOG_TYPE dummy_log = {
		.id = 12,
		.write_status = 1,
		.severity = 65,
		.creation_time = 2,
		.log_data = (unsigned char *)"merhaba",
		.log_data_size = sizeof(dummy_log.log_data),
	};

	LOG_TYPE dummy_log2 = {
		.id = 0,
		.write_status = 0,
		.severity = 0,
		.creation_time = 0,
		.log_data = (unsigned char *)"",
		.log_data_size = 0
	};

	LOGBOOK logbook = {
		.logbook_id = 123456789,
		.partition_id = 42,
		.logbook_name = "app_status",

		.status = {.max_mes_size = 100,
					.max_nb_logged_mes = 200,
					.max_nb_in_progress_mes = 300,
					.nb_logged_mes = 50,
					.nb_in_progress_mes = 25,
					.nb_aborted_mes = 10},
		.logbook_mutex = 987,
		.logs_eng_counter = 1,
		.logs_eng = &dummy_log,

		// .my_float = 10.4567,
	};

	LOGBOOK logbook2 = {
		.logbook_id = -1,
		.partition_id = -1,
		.logbook_name = "",

		.status = {.max_mes_size = -1,
					.max_nb_logged_mes = -1,
					.max_nb_in_progress_mes = -1,
					.nb_logged_mes = -1,
					.nb_in_progress_mes = -1,
					.nb_aborted_mes = -1},
		.logbook_mutex = -1,
		.logs_eng_counter = -1,
    	.logs_eng = &dummy_log2,

		.logs_eng_counter = 1,
		.logs_eng = &dummy_log2,

		// .my_float = 0.0,
	};

	size_t length = 0;

	void *my_data = serialize(logbook, &length);

	unsigned char *msg = (unsigned char *)my_data;
	deserialize(logbook2, msg, length);


	/*CLOSE THESE 3 LINES TO NOT USE FILE SYSTEM, AND OPEN THE ABOVE 3 LINES.*/
	// serialize_logbook_to_file("salih.bin", logbook);
	// /*to look: hexdump -C salih.bin*/
	// deserialize_logbook_from_file("salih.bin", &logbook2);

	// print_sizes_of_types();

	// int64_t i = 0;
	// for (i = 0; i < 5; i++)
	// {
	// 	printf("merhaba [%ld]\n", i);
	// }


	return EXIT_SUCCESS;
}
