#include <stdio.h>

void print_array(int * arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_maximum(int * arr, int size){
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    // printf("size: %d\n", size);
    return max;
}

int find_minimum(int * arr, int size){
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    // printf("size: %d\n", size);
    return min;
    
}

void reverse_array(int * arr, int size)
{
    int beginning = 0;
    int ending = size - 1;

    while (beginning < ending)
    {
        int temp = arr[beginning];
        arr[beginning] = arr[ending];
        arr[ending] = temp;

        beginning++;
        ending--;
    }
    // printf("size: %d\n", size);
    
}

void add_element_to_front(int * arr, int * size, int element)
{
    (*size)++;
    for (int i = *size - 1 ; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    // printf("size: %d\n", *size);

}

void add_element_to_back(int * arr, int * size, int element)
{
    arr[*size] = element;
    (*size)++;
    // printf("size: %d\n", *size);

}

void add_element_to_index(int * arr, int * size, int element, int index)
{
    (*size)++;
    for (int i = *size - 1 ; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;

}

void remove_element_from_front(int * arr, int *size)
{
    if (*size == 0)
    {
        printf("Error. Array is empty.");
        return;
    }
    for (int i = 0; i < *size -1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    

}

void remove_element_from_back(int * arr, int *size)
{
    if (*size == 0)
    {
        printf("Error. Array is empty.");
        return;
    }
    (*size)--;
    arr[*size] = 0;

}

void remove_element_from_index(int * arr, int *size, int index)
{
    if (index < 0 || index >= *size )
    {
        printf("Error. Invalid index.");
        return;
    }
    for (int i = index; i < *size -1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;

}