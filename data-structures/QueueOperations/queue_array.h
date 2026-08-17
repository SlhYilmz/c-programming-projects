#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

// Queue structure
typedef struct {
    int front, end, size;

    //unsigned -> non-negative integers
    unsigned int capacity;
    int* items;
} Queue;

// checks if the queue is empty
int is_empty_queue_array(Queue *queue);

// checks if the queue is full
int is_full_queue_array(Queue *queue);

// inserts 1 element to the queue
void enqueue(Queue *queue, int element);

// removes 1 element from the queue
int dequeue(Queue *queue);

// returns the element at the front end without removing it.
int front(Queue *queue);

// returns the element at the rear end without removing it.
int rear(Queue *queue);

// returns the current size of the queue
int size_queue_array(Queue *queue);

// initializes the queue
void create_queue(Queue * queue, unsigned int capacity);

// prints the queue
void print_queue(Queue *queue);

#endif // QUEUE_ARRAY_H