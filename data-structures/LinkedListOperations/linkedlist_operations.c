#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_operations.h"

void print_linkedlist(Node *head)
{
    printf("Linked list: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int find_maximum(Node *head)
{
    int max = head->data;
    while (head != NULL)
    {
        if (head->data > max)
        {
            max = head->data;
        }
        head = head->next;
    }

    return max;
}

int find_minimum(Node *head)
{
    int min = head->data;
    while (head != NULL)
    {
        if (head->data < min)
        {
            min = head->data;
        }
        head = head->next;
    }

    return min;
}

Node *reverse_linkedlist(Node *head)
{

    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void add_element_to_front(Node **head, int element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = *head;

    *head = new_node;
}

Node *add_element_to_front_2(Node *head, int element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = head;

    return new_node;
}

void add_element_to_back(Node **head, int element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

Node *add_element_to_back_2(Node *head, int element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    return head;
}

void add_element_to_index(Node **head, int element, int index)
{
    if (index == 0)
    {
        add_element_to_front(head, element);
    }
    else
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = element;

        Node *current = *head;
        for (int i = 0; i < index - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            printf("Error. Index out of bounds.");
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

Node *add_element_to_index_2(Node *head, int element, int index)
{
    if (index == 0)
    {
        head = add_element_to_front_2(head, element);
    }
    else
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = element;

        Node *current = head;
        for (int i = 0; i < index - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            printf("Error. Index out of bounds.");
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    return head;
}

void remove_element_from_front(Node **head)
{
    if (*head == NULL)
    {
        printf("Error. Linked list is already empty.\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

Node *remove_element_from_front_2(Node *head)
{
    if (head == NULL)
    {
        printf("Error. Linked list is already empty.\n");
        return 0;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void remove_element_from_back(Node **head)
{
    if (*head == NULL)
    {
        printf("Error. Linked list is already empty.\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *current = *head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

Node *remove_element_from_back_2(Node *head)
{
    if (head == NULL)
    {
        printf("Error. Linked list is already empty.\n");
        return 0;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return 0;
    }

    Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

void remove_element_from_index(Node **head, int index)
{
    if (*head == NULL)
    {
        printf("Error. Linked list is already empty.\n");
        return;
    }
    if (index == 0)
    {
        remove_element_from_front(head);
    }
    else
    {
        Node *current = *head;
        Node *temp = NULL;

        for (int i = 0; i < index - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if (current == NULL || current->next == NULL)
        {
            printf("Error. Index out of bounds.\n");
            return;
        }
        temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

Node *remove_element_from_index_2(Node *head, int index)
{
    if (head == NULL)
    {
        printf("Error. Linked list is already empty.\n");
        return 0;
    }
    if (index == 0)
    {
        head = remove_element_from_front_2(head);
    }
    else
    {
        Node *current = head;
        Node *temp = NULL;

        for (int i = 0; i < index - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if (current == NULL || current->next == NULL)
        {
            printf("Error. Index out of bounds.\n");
            return 0;
        }
        temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    return head;
}