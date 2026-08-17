#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

void print_array(int * arr, int size);

int find_maximum(int * arr, int size);
int find_minimum(int * arr, int size);
void reverse_array(int * arr, int size);

void add_element_to_front(int * arr, int * size, int element);
void add_element_to_back(int * arr, int * size, int element);
void add_element_to_index(int * arr, int * size, int element, int index);

void remove_element_from_front(int * arr, int * size);
void remove_element_from_back(int * arr, int * size);
void remove_element_from_index(int * arr, int * size, int index);

#endif //ARRAY_OPERATIONS_H