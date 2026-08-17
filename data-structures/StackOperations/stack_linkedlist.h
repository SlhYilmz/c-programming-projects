#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H

// Stack structure
typedef struct Node {
    int data;
    struct Node * next;
} Node;

typedef struct {
    Node * top;
} Stack_ll;

// initializes the stack
void create_stack_ll(Stack_ll * stack);

// inserts 1 element to the stack
void push_ll(Stack_ll *stack, int element);

// removes 1 element from the stack
int pop_ll(Stack_ll *stack);

// returns the last element without removing it.
int peek_ll(Stack_ll *stack);

// returns the current size of the stack
int size_ll(Stack_ll *stack);

// checks if the stack is empty
int is_empty_ll(Stack_ll *stack);

// prints the stack
void print_stack_ll(Stack_ll *stack);

#endif // STACK_LINKEDLIST_H