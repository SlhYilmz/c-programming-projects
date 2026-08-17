#include <stdio.h>

#include "array_operations.h"

int main()
{

    printf("------------------------------------------------\n");
    
    int arr1[20] = {10, 2, 65, 465, 11, 65, 23, 1, 3};
    // int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size1 = 9;

    printf("Original Array 1:\n");

    print_array(arr1, size1);

    printf("\n");
    printf("------------------------------------------------\n");

    int maximum1 = find_maximum(arr1, size1);
    int minimum1 = find_minimum(arr1, size1);
    printf("Maximum element of the array: %d\n", maximum1);
    printf("Minimum element of the array: %d\n", minimum1);

    printf("\n");

    reverse_array(arr1, size1);
    printf("Reversed Array 1:\n");
    print_array(arr1, size1);

    printf("\n");
    int element1 = 12;
    printf("Add element %d to the front of the array:\n", element1);
    add_element_to_front(arr1, &size1, element1);
    print_array(arr1, size1);

    printf("\n");
    int element2 = 7;
    printf("Add element %d to the back of the array:\n", element2);
    add_element_to_back(arr1, &size1, element2);
    print_array(arr1, size1);

    printf("\n");
    int element3 = 135;
    int index1 = 6;
    printf("Add element %d to the %dth index of the array:\n", element3, index1);
    add_element_to_index(arr1, &size1, element3, index1);
    print_array(arr1, size1);

    printf("\n");
    printf("Remove element from the front of the array:\n");
    remove_element_from_front(arr1, &size1);
    print_array(arr1, size1);

    printf("\n");
    printf("Remove element from the back of the array:\n");
    remove_element_from_back(arr1, &size1);
    print_array(arr1, size1);

    printf("\n");
    int index2 = 3;
    printf("Remove element from the %dth index of the array:\n", index2);
    remove_element_from_index(arr1, &size1, index2);
    print_array(arr1, size1);
   


    printf("------------------------------------------------\n");

    return 0;
}