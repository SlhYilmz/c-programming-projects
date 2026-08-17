#include <stdio.h>
#include <stdlib.h>

#include "stack_array.h"

// initializes the stack
// void create_stack(Stack *stack, unsigned int capacity)
// {
//     // stack = (Stack *)malloc(sizeof(Stack));

//     stack->capacity = capacity;
//     stack->top = -1;
//     stack->items = (int *)malloc(stack->capacity * sizeof(int));
// }

void create_stack(Stack *stack)
{
    // stack = (Stack *)malloc(sizeof(Stack));

    
    stack->top = -1;
}

// inserts 1 element to the stack
void push(Stack *stack, int element)
{
    if (is_full(stack))
    {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->top = stack->top + 1;
    stack->items[stack->top] = element;
}

// removes 1 element from the stack
int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    return stack->items[stack->top--];
}

// returns the last element without removing it.
int peek(Stack *stack)
{
    return stack->items[stack->top];
}

// returns the current size of the stack
int size(Stack *stack)
{
    return stack->top + 1;
}

// checks if the stack is empty
int is_empty(Stack *stack)
{
    return stack->top == -1;
}

// checks if the stack is full
int is_full(Stack *stack)
{
    //return stack->top == (int)stack->capacity - 1;
    return stack->top == MAX_CAPACITY;
}

// prints the stack
void print_stack(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->items[i]);
    }
    printf("\n");

    return;
}