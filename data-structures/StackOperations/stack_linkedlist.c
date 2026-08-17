#include <stdio.h>
#include <stdlib.h>

#include "stack_linkedlist.h"

// initializes the stack
void create_stack_ll(Stack_ll *stack)
{
    stack->top = NULL;
}

/*
 * In the push function, a new node is created to hold the value that needs to be pushed onto the stack.
 * This new node becomes the new top of the stack.
 * The next pointer of the new node is set to the current top of the stack, linking the new node to the rest of the stack elements.
 * Finally, the top pointer is updated to point to the new node.
 * 
 * The reason for this design is that it allows for efficient insertion of new elements at the top of the stack.
 * By creating a new node and updating the top pointer, the new element becomes the first element in the stack,
 * and the previous stack elements become the elements below it.
 * This approach is known as "pushing" the element onto the stack,
 * mimicking the behavior of placing an item on top of a physical stack of objects.
 */
void push_ll(Stack_ll *stack, int element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
}

/*
 * In the pop function, the top element of the stack is removed and returned.
 * To accomplish this, the current top node is temporarily stored in the temp node.
 * The value of the top element is retrieved and stored in a variable called value.
 * The top pointer is then updated to point to the next node in the stack, effectively removing the top node.
 * 
 * The reason for using a temporary node (temp) is to preserve the reference to the current top node.
 * This allows us to retrieve the value of the top element before removing it from the stack.
 * By storing the value in value and freeing the memory allocated for the temp node,
 * we ensure that the memory associated with the top node is properly released.
 */
int pop_ll(Stack_ll *stack)
{
    if (is_empty_ll(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    Node *temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

/*
 * The peek function is used to retrieve the value of the top element without modifying the stack.
 * It simply returns the value stored in the data field of the top node.
 */
int peek_ll(Stack_ll *stack)
{
    if (is_empty_ll(stack))
    {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack->top->data;
}

// returns the current size of the stack
int size_ll(Stack_ll *stack)
{
    int count = 0;
    Node* current = stack->top;
    while (current->next != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
    
}

// checks if the stack is empty
int is_empty_ll(Stack_ll *stack)
{
    return stack->top == NULL;
}

// prints the stack
void print_stack_ll(Stack_ll *stack)
{
    if(is_empty_ll(stack)){
        printf("Stack is empty. Cannot print.\n");
        return;
    }
    Node * current = stack->top;
    printf("Stack_ll elements:\n");
    while (current->next != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
}