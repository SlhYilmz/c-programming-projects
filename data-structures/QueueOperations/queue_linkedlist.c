#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "queue_linkedlist.h"

// checks if the queue is empty
int is_empty_queue_ll(Queue_ll *queue)
{
    return (queue->front == NULL);
}

// inserts 1 element to the queue (from the back)
void enqueue_ll(Queue_ll *queue, int element)
{
   // Create a new node
    Queue_Node_LL* newNode = (Queue_Node_LL*)malloc(sizeof(Queue_Node_LL));
    newNode->data = element;
    newNode->next = NULL;

    // If the queue is empty, update both front and rear to the new node
    if (is_empty_queue_ll(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        // Otherwise, add the new node after the current rear node
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enqueued to queue.\n", element);
}

// removes 1 element from the queue (from the front)
int dequeue_ll(Queue_ll *queue)
{
    if (is_empty_queue_ll(queue)) {
        printf("Cannot dequeue. Queue is empty.\n");
        return -1;  
    }

    // Store the front node and its data
    Queue_Node_LL* frontNode = queue->front;
    int element = frontNode->data;

    // Update the front to the next node
    queue->front = queue->front->next;

    // If the queue becomes empty, update rear to NULL as well
    if (queue->front == NULL)
        queue->rear = NULL;

    // Free the memory of the dequeued node
    free(frontNode);

    //printf("%d dequeued from queue.\n", element);
    return element;
}

// returns the element at the front end without removing it.
int front_ll(Queue_ll *queue)
{
    if (is_empty_queue_ll(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->front->data;
}

// returns the element at the rear end without removing it.
int rear_ll(Queue_ll *queue)
{
    if (is_empty_queue_ll(queue)) {
        printf("Queue is empty.\n");
        return -1;  // or any other suitable error value
    }

    return queue->rear->data;
}

// returns the current size of the queue
int size_queue_ll(Queue_ll *queue)
{
    int count = 1;
    Queue_Node_LL* current = queue->front;
    while (current->next != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// initializes the queue
Queue_ll * create_queue_ll()
{
    Queue_ll* queue = (Queue_ll*)malloc(sizeof(Queue_ll));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// prints the queue
void print_queue_ll(Queue_ll *queue)
{
    if (is_empty_queue_ll(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    Queue_Node_LL* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}