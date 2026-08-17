/*
 ============================================================================
 Name        : packer.c
 Author      : Muhammed Salih Yilmaz
 Date        : September 2023
 Version     : 0.0.1
 Copyright   : 
 Description : packer.c file. Written in C99.
 ============================================================================
 */

#include "packer.h"
#include "endian.h"
#include "helper.h"

#define BUFFER_SIZE_TOO_SMALL 0
#define BUFFER_SIZE_OK 1

// Declare a global instance of BUFFER
BUFFER buf = {
    .size = INITIAL_SIZE,
    .data = NULL, // We'll initialize this later
    .next = 0,
    .checksum = 0,
    .checksum_info_added = 0,
};

// buffer_data adiyla, initial_size boyutunda bir char array initialize et.
static char buffer_data[INITIAL_SIZE];

// Buffer'in dolu olan size boyutunu dondurur. Length yani.
size_t length_data()
{
    return buf.next;
}

void *serialize(LOGBOOK logbook, size_t *length)
{
    buf.data = buffer_data;

    // uint64_t my_checksum = calculate_checksum((unsigned char *)&logbook, sizeof(logbook), &buf);
    // // printf("checksum sender: %lld\n\r", buf.checksum);

    // printf("my_chekcsum: %ld\n", my_checksum);
    // add_checksum_info(&buf);

    serialize_LOGBOOK(&buf, logbook);

    *length = buf.next;

    print_buffer_raw_data(&buf);
    printf("\n\r");
    // dump_logbook(logbook);
    printf("\n\r");
    // print_buffer_info(&buf);
    return buf.data;
}

void deserialize(LOGBOOK logbook, unsigned char msg[250], signed int length)
{
    if (length == 0 || length < 0)
    {
        printf("Message not received, or message is null.\n\r");
    }
    else
    {
        buf.data = msg;
        buf.next = (size_t)length;

        // uint64_t received_checksum = *((uint64_t *)buf.data);
        // uint64_t serialized_checksum;
        // memcpy(&serialized_checksum, ((unsigned char *)buf.data), sizeof(uint64_t));

        // /* Move buffer's pointer so it does not deserialize the checksum. */
        // unsigned char *data_ptr = (unsigned char *)buf.data;
        // data_ptr += sizeof(uint64_t);
        // buf.data = (void *)data_ptr;
        // // buf.next -= sizeof(uint64_t);
        // // buf.data += sizeof(uint64_t);


        // printf("\n\r");
        // if (received_checksum == serialized_checksum)
        // {
            deserialize_LOGBOOK(&buf, &logbook);
            printf("\n\rAFTER DESERIALIZATON\n\r");
            print_buffer_raw_data(&buf);
            // dump_logbook(logbook);
        // }
        // else
        // {
        //     printf("Data is corrupted. not deseriaziling.\n\r");
        // }
    }
}

uint64_t calculate_checksum(const unsigned char *data, int size, BUFFER *buf)
{
    uint64_t checksum = 0;
    int i = 0;
    buf->checksum = 0U;
    for (i = 0; i < size; i++)
    {
        buf->checksum += data[i];
    }
    checksum = buf->checksum;
    return checksum;
}

void add_checksum_info(BUFFER *buf)
{
    if (buf == NULL || buf->data == NULL)
    {
        /* Handle null buffer or null pointer. */
        return;
    }
    if (check_space(buf, sizeof(unsigned char)))
    {
        memcpy(((char *)buf->data) + buf->next, &(buf->checksum), sizeof(uint64_t));
        buf->next += sizeof(uint64_t);
        buf->checksum_info_added = 1;
    }
    else
    {
        /* Handle insufficient space error. */
        printf("Not enough space to hold checksum.\n");
    }
}

BUFFER *new_buffer()
{
    BUFFER *buf = malloc(sizeof(BUFFER));

    if (buf != NULL)
    {
        buf->data = malloc(INITIAL_SIZE);
        if (buf->data == NULL)
        {
            /* Memory allocation error */
            free(buf);
            buf = NULL;
        }
        else
        {
            buf->size = INITIAL_SIZE;
            buf->next = 0;
        }
    }

    return buf;
}

/* Checks if there is space in the buffer for serialization or deseriazaliation */
int check_space(BUFFER *buf, size_t bytes)
{
    if ((buf->next + bytes) > buf->size)
    {
        printf("Size of buffer is too small to serialize.");
        return BUFFER_SIZE_TOO_SMALL;
    }
    else
    {
        return BUFFER_SIZE_OK;
    }
}

/* Serialize Functions */

/**********************/
/* SIGNED INT8_T */
void serialize_int8_t(BUFFER *buf, int8_t x)
{
    if (check_space(buf, sizeof(int8_t)))
    {
        x = hton_int8(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(int8_t));
        buf->next += sizeof(int8_t);
    }
    else
    {
        printf("int8_t serialization failed.\n");
    }
}

void deserialize_int8_t(BUFFER *buf, int8_t *x)
{
    if (check_space(buf, sizeof(int8_t)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(int8_t));

        /* This function translates an int8_t from network byte order to host byte order.*/
        *x = ntoh_int8(*x);
        buf->next += sizeof(int8_t);
    }
    else
    {
        printf("int8_t deserialization failed.\n");
    }
}

/**********************/
/* UNSIGNED INT8_T */
void serialize_uint8_t(BUFFER *buf, uint8_t x)
{
    if (check_space(buf, sizeof(uint8_t)))
    {
        x = hton_uint8(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(uint8_t));
        buf->next += sizeof(uint8_t);
    }
    else
    {
        printf("uint8_t serialization failed.\n");
    }
}

void deserialize_uint8_t(BUFFER *buf, uint8_t *x)
{
    if (check_space(buf, sizeof(uint8_t)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(uint8_t));

        /* This function translates a uint8_t from network byte order to host byte order. */
        *x = ntoh_uint8(*x);
        buf->next += sizeof(uint8_t);
    }
    else
    {
        printf("uint8_t deserialization failed.\n");
    }
}

/**********************/
/* SIGNED INT16_T */
void serialize_int16_t(BUFFER *buf, int16_t x)
{
    if (check_space(buf, sizeof(int16_t)))
    {
        x = hton_int16(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(int16_t));
        buf->next += sizeof(int16_t);
    }
    else
    {
        printf("int16_t serialization failed.\n");
    }
}

void deserialize_int16_t(BUFFER *buf, int16_t *x)
{
    if (check_space(buf, sizeof(int16_t)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(int16_t));

        /* This function translates an int16_t from network byte order to host byte order. */
        *x = ntoh_int16(*x);
        buf->next += sizeof(int16_t);
    }
    else
    {
        printf("int16_t deserialization failed.\n");
    }
}

/**********************/
/* UNSIGNED INT16_T */
void serialize_uint16_t(BUFFER *buf, uint16_t x)
{
    if (check_space(buf, sizeof(uint16_t)))
    {
        x = hton_uint16(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(uint16_t));
        buf->next += sizeof(uint16_t);
    }
    else
    {
        printf("uint16_t serialization failed.\n");
    }
}

void deserialize_uint16_t(BUFFER *buf, uint16_t *x)
{
    if (check_space(buf, sizeof(uint16_t)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(uint16_t));

        /* This function translates a uint16_t from network byte order to host byte order. */
        *x = ntoh_uint16(*x);
        buf->next += sizeof(uint16_t);
    }
    else
    {
        printf("uint16_t deserialization failed.\n");
    }
}

/***********************/
/* SIGNED INT32_T */
void serialize_int32_t(BUFFER *buf, int32_t x)
{
    if (check_space(buf, sizeof(int32_t)))
    {
        x = hton_int32(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(int32_t));
        buf->next += sizeof(int);
    }
    else
    {
        printf("int32_t serialization failed.");
    }
}

void deserialize_int32_t(BUFFER *buf, int32_t *x)
{
    if (check_space(buf, sizeof(int32_t)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(int32_t));

        /* This function translates an integer from network byte order to host byte order. */
        *x = ntoh_int32(*x);
        buf->next += sizeof(int32_t);
    }
    else
    {
        printf("int32_t deserialization failed.\n");
    }
}

/***********************/
/* UNSIGNED INT32_T */
void serialize_uint32_t(BUFFER *buf, uint32_t x)
{
    if (check_space(buf, sizeof(uint32_t)))
    {
        x = hton_uint32(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(uint32_t));
        buf->next += sizeof(uint32_t);
    }
    else
    {
        printf("uint32_t serialization failed.\n");
    }
}

void deserialize_uint32_t(BUFFER *buf, uint32_t *x)
{
    if (check_space(buf, sizeof(uint32_t)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(uint32_t));
        *x = ntoh_uint32(*x);
        buf->next += sizeof(uint32_t);
    }
    else
    {
        printf("uint32_t deserialization failed.\n");
    }
}

/**********************/
/* SIGNED INT64_T */
void serialize_int64_t(BUFFER *buf, int64_t x)
{
    if (check_space(buf, sizeof(int64_t)))
    {
        x = hton_int64(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(int64_t));
        buf->next += sizeof(int64_t);
    }
    else
    {
        printf("int64_t serialization failed.\n");
    }
}

void deserialize_int64_t(BUFFER *buf, int64_t *x)
{
    if(x == NULL)
    {
        return;
    }
    if (check_space(buf, sizeof(int64_t)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(int64_t));

        /* This function translates an int64_t from network byte order to host byte order. */
        *x = ntoh_int64(*x);
        buf->next += sizeof(int64_t);
    }
    else
    {
        printf("int64_t deserialization failed.\n");
    }
}

/**********************/
/* UNSIGNED INT64_T */
void serialize_uint64_t(BUFFER *buf, uint64_t x)
{
    if (check_space(buf, sizeof(uint64_t)))
    {
        x = hton_uint64(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(uint64_t));
        buf->next += sizeof(uint64_t);
    }
    else
    {
        printf("uint64_t serialization failed.\n");
    }
}

void deserialize_uint64_t(BUFFER *buf, uint64_t *x)
{
    if (check_space(buf, sizeof(uint64_t)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(uint64_t));

        /* This function translates a uint64_t from network byte order to host byte order. */
        *x = ntoh_uint64(*x);
        buf->next += sizeof(uint64_t);
    }
    else
    {
        printf("uint64_t deserialization failed.\n");
    }
}

/***********************/
/* FLOAT */
void serialize_float(BUFFER *buf, float x)
{
    if (check_space(buf, sizeof(float)))
    {
        x = hton_float(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(float));
        buf->next += sizeof(float);
    }
    else
    {
        printf("Float serialization failed.\n");
    }
}

void deserialize_float(BUFFER *buf, float *x)
{
    if (check_space(buf, sizeof(float)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(float));
        *x = ntoh_float(*x);
        buf->next += sizeof(float);
    }
    else
    {
        printf("Float deserialization failed.\n");
    }
}

/**********************/
/* DOUBLE */
void serialize_double(BUFFER *buf, double x)
{
    if (check_space(buf, sizeof(double)))
    {
        x = hton_double(x);
        memcpy(((char *)buf->data) + buf->next, &x, sizeof(double));
        buf->next += sizeof(double);
    }
    else
    {
        printf("Double serialize failed.\n");
    }
}

void deserialize_double(BUFFER *buf, double *x)
{
    if (check_space(buf, sizeof(double)))
    {
        memcpy(x, ((char *)buf->data) + buf->next, sizeof(double));
        *x = ntoh_double(*x);
        buf->next += sizeof(double);
    }
    else
    {
        printf("Double deserialization failed.\n");
    }
}

/***********************/
/* String */
void serialize_string(BUFFER *buf, const char *str)
{
    size_t str_len = member_size(LOGBOOK, logbook_name);
    // printf("str_len: %ld\n\r", str_len);
    if (check_space(buf, str_len))
    {
        memcpy(((char *)buf->data) + buf->next, str, str_len);
        buf->next += str_len;
    }
    else
    {
        printf("String serialization failed.");
    }
}

void deserialize_string(BUFFER *buf, char *str)
{
    size_t str_len = member_size(LOGBOOK, logbook_name);
    strcpy(str, ((char *)buf->data) + buf->next);
    buf->next += str_len;
}

/***********************/
/* STATUS */
void serialize_STATUS(BUFFER *buf, STATUS status)
{
   // Check if the buffer has enough space for the serialized STATUS struct
    if (check_space(buf, sizeof(STATUS)))
    {
        // Serialize each member of the STATUS struct separately


        serialize_int32_t(buf, status.max_mes_size);
        serialize_int32_t(buf, status.max_nb_logged_mes);
        serialize_int32_t(buf, status.max_nb_in_progress_mes);
        serialize_int32_t(buf, status.nb_logged_mes);
        serialize_int32_t(buf, status.nb_in_progress_mes);
        serialize_int32_t(buf, status.nb_aborted_mes);
    }
    else
    {
        printf("STATUS serialization failed: Not enough space.\n");
    }
}

void deserialize_STATUS(BUFFER *buf, STATUS *status)
{
   // Check if the buffer has enough space for the serialized STATUS struct
    if (check_space(buf, sizeof(STATUS)))
    {
        // Serialize each member of the STATUS struct separately
        deserialize_int32_t(buf, &(status->max_mes_size));
        deserialize_int32_t(buf, &(status->max_nb_logged_mes));
        deserialize_int32_t(buf, &(status->max_nb_in_progress_mes));
        deserialize_int32_t(buf, &(status->nb_logged_mes));
        deserialize_int32_t(buf, &(status->nb_in_progress_mes));
        deserialize_int32_t(buf, &(status->nb_aborted_mes));
    }
    else
    {
        printf("STATUS deserialization failed: Not enough space.\n");
    }
}


void serialize_LOG_TYPE(BUFFER *buf, LOG_TYPE log)
{
    // Serialize each member of the LOG_TYPE struct separately
    serialize_int64_t(buf, (log.id));
    serialize_uint32_t(buf, log.write_status);
    serialize_uint32_t(buf, log.severity);
    serialize_int64_t(buf, log.creation_time);

    // Serialize log_data_size as uint64_t
    serialize_uint64_t(buf, log.log_data_size);

    // Serialize log_data
    if (log.log_data_size > 0)
    {
        if (check_space(buf, log.log_data_size))
        {
            memcpy(((char *)buf->data) + buf->next, log.log_data, log.log_data_size);
            buf->next += log.log_data_size;
        }
        else
        {
            printf("LOG_TYPE log_data serialization failed: Not enough space.\n");
        }
    }
}

void deserialize_LOG_TYPE(BUFFER *buf, LOG_TYPE *log)
{
//     // Deserialize each member of the LOG_TYPE struct separately
    deserialize_int64_t(buf, &(log->id));
    // printf("log->id: %ld\n\r", log->id);

    deserialize_uint32_t(buf, &(log->write_status));
    // printf("log->write_status: %d\n\r", log->write_status);

    deserialize_uint32_t(buf, &log->severity);
    // printf("log->severity: %d\n\r", log->severity);

    deserialize_int64_t(buf, &log->creation_time);
    // printf("log->creation_time: %ld\n\r", log->creation_time);

    // Deserialize log_data_size as uint64_t
    deserialize_uint64_t(buf, &log->log_data_size);
    // printf("log->log_data_size: %ld\n\r", log->log_data_size);

    // Deserialize log_data
    if (log->log_data_size > 0)
    {
        if (check_space(buf, log->log_data_size))
        {
            log->log_data = (unsigned char *)malloc(log->log_data_size);
            if (log->log_data == NULL)
            {
                printf("Memory allocation for LOG_TYPE log_data failed.\n");
                return;
            }
            memcpy(log->log_data, ((char *)buf->data) + buf->next, log->log_data_size);
            buf->next += log->log_data_size;
        }
        else
        {
            printf("LOG_TYPE log_data deserialization failed: Not enough space.\n");
        }
    }
}

/***********************/
/* LOGBOOK */
void serialize_LOGBOOK(BUFFER *buf, LOGBOOK logbook)
{
    // serialize_float(buf, logbook.my_float);

    SERIALIZE_GENERIC(buf, &logbook.logbook_id, sizeof(logbook.logbook_id), int64_t);
    // serialize_int64_t(buf, logbook.logbook_id);

    // serialize_int32_t(buf, logbook.partition_id);
    // serialize_string(buf, logbook.logbook_name);

    // serialize_STATUS(buf, logbook.status);

    // serialize_int32_t(buf, logbook.logbook_mutex);
    // serialize_LOG_TYPE(buf, *(logbook.logs_eng));
}

void deserialize_LOGBOOK(BUFFER *buf, LOGBOOK *logbook)
{
    buf->next = 0;
    // deserialize_float(buf, &logbook->my_float);

    DESERIALIZE_GENERIC(buf, &logbook->logbook_id, sizeof(logbook->logbook_id), int64_t);
    // deserialize_int64_t(buf, &logbook->logbook_id);
    // deserialize_int32_t(buf, &logbook->partition_id);
    // deserialize_string(buf, logbook->logbook_name);

    // deserialize_STATUS(buf, &(logbook->status));

    // deserialize_int32_t(buf, &logbook->logbook_mutex);
    // deserialize_LOG_TYPE(buf, (logbook->logs_eng));
}
