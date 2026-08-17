#include <stdio.h>
#include <stdlib.h>

#include "queue_array.h"
#include "queue_linkedlist.h"


void queueWithArray()
{
    Queue *queue;
    create_queue(queue, 50);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 4);
    enqueue(queue, 5);

    print_queue(queue);
    printf("\n");

    printf("%d dequeued from queue\n", dequeue(queue));
    print_queue(queue);
    printf("\n");

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
}

void queueWithLinkedList()
{
    Queue_ll *queue = create_queue_ll();

    enqueue_ll(queue, 1);
    enqueue_ll(queue, 2);
    enqueue_ll(queue, 3);
    enqueue_ll(queue, 40);
    enqueue_ll(queue, 50);

    print_queue_ll(queue);
    printf("\n");

    printf("%d dequeued from queue\n", dequeue_ll(queue));
    print_queue_ll(queue);
    printf("\n");

    printf("Front item is %d\n", front_ll(queue));
    printf("Rear item is %d\n", rear_ll(queue));

    // printf("size: %d\n", size_queue_ll(queue));
    // printf("%d dequeued from queue\n", dequeue_ll(queue));
    // printf("size: %d\n", size_queue_ll(queue));
    // print_queue_ll(queue);
    // printf("%d dequeued from queue\n", dequeue_ll(queue));
    // printf("%d dequeued from queue\n", dequeue_ll(queue));
    // print_queue_ll(queue);
    // printf("size: %d\n", size_queue_ll(queue));
    // printf("%d dequeued from queue\n", dequeue_ll(queue));
    // print_queue_ll(queue);
    // printf("size: %d\n", size_queue_ll(queue));
}

int main()
{
    /*****************************************/
    printf("----------------------------\n");
    printf("Queue (Array implementation)\n");
    printf("\n");
    queueWithArray();

    /*****************************************/
    printf("----------------------------------\n");
    printf("Queue (Linked List implementation)\n");
    printf("\n");
    queueWithLinkedList();

    return 0;
}