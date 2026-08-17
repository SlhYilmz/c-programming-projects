#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#define MAX_CAPACITY 100

// Stack structure
typedef struct {
    int top;

    //unsigned -> non-negative integers
    //unsigned int capacity;
    //int* items;
    int items[MAX_CAPACITY];
} Stack;

// initializes the stack
/* void create_stack(Stack * stack, unsigned int capacity); */

void create_stack(Stack * stack);

// inserts 1 element to the stack
void push(Stack *stack, int element);

// removes 1 element from the stack
int pop(Stack *stack);

// returns the last element without removing it.
int peek(Stack *stack);

// returns the current size of the stack
int size(Stack *stack);

// checks if the stack is empty
int is_empty(Stack *stack);

// checks if the stack is full
int is_full(Stack *stack);

// prints the stack
void print_stack(Stack *stack);

#endif // STACK_ARRAY_H