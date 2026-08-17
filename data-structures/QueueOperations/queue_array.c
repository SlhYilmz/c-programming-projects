#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "queue_array.h"

// checks if the queue is empty
int is_empty_queue_array(Queue *queue)
{
    return (queue->size == 0);
}

// checks if the queue is full
int is_full_queue_array(Queue *queue)
{
    return (queue->size == queue->capacity);
}

// inserts 1 element to the queue (from the back)
/* By wrapping the indices, the circular queue can effectively utilize the available space in the array.
 * When elements are dequeued from the front end, the front index moves forward,
 * and when elements are enqueued at the rear end, the rear index moves forward.
 * If the indices reach the end of the array, the modulo operator wraps them back to the beginning,
 * allowing the queue to continue operating correctly without wasting space.
 */
void enqueue(Queue *queue, int element)
{
    if (is_full_queue_array(queue))
    {
        printf("Cannot enqueue an element. Queue is full.\n");
        return;
    }
    queue->end = (queue->end + 1) % queue->capacity;
    queue->items[queue->end] = element;
    queue->size = queue->size + 1;

    printf("%d enqueued to queue.\n", element);
}

// removes 1 element from the queue (from the front)
int dequeue(Queue *queue)
{
    if (is_empty_queue_array(queue))
    {
        return INT_MIN;
    }
    int element = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return element;
}

// returns the element at the front end without removing it.
int front(Queue *queue)
{
    if (is_empty_queue_array(queue))
    {
        return INT_MIN;
    }
    return queue->items[queue->front];
}

// returns the element at the rear end without removing it.
int rear(Queue *queue)
{
    if (is_empty_queue_array(queue))
        return INT_MIN;
    return queue->items[queue->end];
}

// returns the current size of the queue
int size_queue_array(Queue *queue)
{
    return (queue->size);
}

// initializes the queue
void create_queue(Queue *queue, unsigned int capacity)
{
    // Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;

    queue->end = capacity - 1;
    queue->items = (int *)malloc(queue->capacity * sizeof(int));
}

// prints the queue
void print_queue(Queue *queue)
{
    if (is_empty_queue_array(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    int index = queue->front;
    for (int i = 0; i < queue->size; i++)
    {
        printf("%d, ", queue->items[index]);
        index = (index + 1) % queue->capacity;
    }
    printf("\n");
}