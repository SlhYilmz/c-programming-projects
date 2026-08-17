#ifndef LINKEDLIST_OPERATIONS_H
#define LINKEDLIST_OPERATIONS_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void print_linkedlist(Node *head);

int find_maximum(Node *head);
int find_minimum(Node *head);
Node *reverse_linkedlist(Node *head);

// Implementations with pointer to the pointer
void add_element_to_front(Node **head, int element);
void add_element_to_back(Node **head, int element);
void add_element_to_index(Node **head, int element, int index);

void remove_element_from_front(Node **head);
void remove_element_from_back(Node **head);
void remove_element_from_index(Node **head, int index);

// Implementations with only one pointer
/* While using a single pointer parameter simplifies the function signature and reduces indirection,
 * it requires manually updating the original pointer in the main code
 * and may involve more steps when assigning the updated head pointer in the calling code.
*/
Node *add_element_to_front_2(Node *head, int element);
Node *add_element_to_back_2(Node *head, int element);
Node *add_element_to_index_2(Node *head, int element, int index);

Node *remove_element_from_front_2(Node *head);
Node *remove_element_from_back_2(Node *head);
Node *remove_element_from_index_2(Node *head, int index);

#endif // LINKEDLIST_OPERATIONS_H