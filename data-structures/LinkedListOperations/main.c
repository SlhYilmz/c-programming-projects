#include <stdio.h>
#include <stdlib.h>

#include "linkedlist_operations.h"

int main()
{
    Node *head = NULL;
    // head = malloc(sizeof(Node));

    add_element_to_front(&head, 3);
    add_element_to_back(&head, 4);
    add_element_to_front(&head, 21);
    add_element_to_back(&head, 7);
    add_element_to_back(&head, 42);

    print_linkedlist(head);
    printf("---------------------------\n");
    printf("\n");

    int max = find_maximum(head);
    int min = find_minimum(head);

    printf("Max. value: %d\n", max);
    printf("Min. value: %d\n", min);
    printf("\n");

    head = reverse_linkedlist(head);
    printf("Reverse ");
    print_linkedlist(head);
    printf("\n");

    int element1 = 57;
    int index1 = 2;
    printf("Element %d added to index %d\n", element1, index1);
    add_element_to_index(&head, element1, index1);

    print_linkedlist(head);
    printf("\n");

    printf("Remove element from back\n");
    remove_element_from_back(&head);
    print_linkedlist(head);
    printf("\n");

    printf("Remove element from front\n");
    remove_element_from_front(&head);
    print_linkedlist(head);
    printf("\n");

    int index2 = 2;
    printf("Remove element from index %d\n", index2);
    remove_element_from_index(&head, index2);
    print_linkedlist(head);
    printf("\n");

    printf("---------------------------------------------\n");
    int element2 = 5;
    printf("Add element %d to the front (implementation #2)\n", element2);
    head = add_element_to_front_2(head, element2);
    print_linkedlist(head);
    printf("\n");

    int element3 = 28;
    printf("Add element %d to the back (implementation #2)\n", element3);
    head = add_element_to_back_2(head, element3);
    print_linkedlist(head);
    printf("\n");

    int element4 = 33;
    int index4 = 2;
    printf("Element %d added to index %d (implementation #2)\n", element4, index4);
    head = add_element_to_index_2(head, element4, index4);
    print_linkedlist(head);
    printf("\n");


    printf("Remove element from back (implementation #2)\n");
    head = remove_element_from_back_2(head);
    print_linkedlist(head);
    printf("\n");

    printf("Remove element from front (implementation #2)\n");
    head = remove_element_from_front_2(head);
    print_linkedlist(head);
    printf("\n");

    int index5 = 1;
    printf("Remove element from index %d (implementation #2)\n", index5);
    head = remove_element_from_index_2(head, index5);
    print_linkedlist(head);
    printf("\n");


    return 0;
}
