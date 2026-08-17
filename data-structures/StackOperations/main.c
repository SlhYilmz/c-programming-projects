#include <stdio.h>
#include <stdlib.h>

#include "stack_array.h"
#include "stack_linkedlist.h"


void stackWithArray()
{
    Stack *stack;
    //unsigned int stackSize = 100;
    //create_stack(stack, stackSize);
    create_stack(stack);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 4);
    push(stack, 5);

    print_stack(stack);

    int poppedValue = 0;
    printf("Pop.\n");
    poppedValue = pop(stack);
    printf("poppedValue: %d\n", poppedValue);
    print_stack(stack);

    printf("Peek (top element): %d\n", peek(stack));
    print_stack(stack);

    printf("Pop.\n");
    poppedValue = pop(stack);
    printf("poppedValue: %d\n", poppedValue);
    print_stack(stack);

    int currentSize = size(stack);
    printf("Current size of the stack array: %d\n", currentSize);
    printf("\n");
}

void stackWithLinkedList()
{
    /*
     * Burayı pointer şeklinde tanımlamamamızın sebebi, zaten stack'in başı için
     * bir pointer tutuyor olmamız. Doğrudan stack'i gösteren bir pointer gereksiz olacaktır.
     * Fakat üstteki örnek diğer şekilde de yapılabildiğini göstermiştir.
     */
    Stack_ll stack_ll;
    create_stack_ll(&stack_ll);

    // Buralarda da adresini gönderiyor olmamızın sebebi, stack değişkenine doğrudan erişmek.
    push_ll(&stack_ll, 10);
    push_ll(&stack_ll, 20);
    push_ll(&stack_ll, 30);
    push_ll(&stack_ll, 4);
    push_ll(&stack_ll, 5);

    print_stack_ll(&stack_ll);
    printf("\n");

    int poppedValue2 = 0;
    printf("Pop_ll.\n");
    poppedValue2 = pop_ll(&stack_ll);
    printf("poppedValue2: %d\n", poppedValue2);
    print_stack_ll(&stack_ll);
    printf("\n");

    printf("Peek_ll (top element): %d\n", peek_ll(&stack_ll));
    print_stack_ll(&stack_ll);
    printf("\n");

    printf("Pop_ll.\n");
    poppedValue2 = pop_ll(&stack_ll);
    printf("poppedValue2: %d\n", poppedValue2);
    print_stack_ll(&stack_ll);
    printf("\n");

    int currentSize2 = size_ll(&stack_ll);
    printf("Current size of the stack linked list: %d\n", currentSize2);
    printf("\n");
}


int main()
{
    printf("----------------------------\n");
    printf("Stack (Array implementation)\n");
    printf("\n");
    stackWithArray();

    /*****************************************/
    printf("----------------------------------\n");
    printf("Stack (Linked List implementation)\n");
    printf("\n");
    stackWithLinkedList();

    

    return 0;
}