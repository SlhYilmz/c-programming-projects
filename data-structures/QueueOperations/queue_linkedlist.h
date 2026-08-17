#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

// Node structure for the linked list
typedef struct Queue_Node_LL {
    int data;
    struct Queue_Node_LL* next;
} Queue_Node_LL;

// Queue structure
typedef struct {
    Queue_Node_LL* front;
    Queue_Node_LL* rear;
} Queue_ll;

// checks if the queue is empty
int is_empty_queue_ll(Queue_ll *queue);

// checks if the queue is full
int is_full_queue_ll(Queue_ll *queue);

// inserts 1 element to the queue
void enqueue_ll(Queue_ll *queue, int element);

// removes 1 element from the queue
int dequeue_ll(Queue_ll *queue);

// returns the element at the front end without removing it.
int front_ll(Queue_ll *queue);

// returns the element at the rear end without removing it.
int rear_ll(Queue_ll *queue);

// returns the current size of the queue
int size_queue_ll(Queue_ll *queue);

// initializes the queue
Queue_ll * create_queue_ll();

// prints the queue
void print_queue_ll(Queue_ll *queue);

#endif // QUEUE_LINKEDLIST_H