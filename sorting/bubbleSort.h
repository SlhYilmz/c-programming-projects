#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "helperFunctions.h"

// Time complexity:
// Worst case:      O(n^2)  -> 2 nested loops
// Best case:       O(n)    -> already in order.
// Average case:    O(n^2)
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubbleSortOptimized(int arr[], int n)
{
    int is_swapped;
    for (int i = 0; i < n - 1; i++)
    {
        is_swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                is_swapped = 1;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (is_swapped == 0)
            break;
    }
}

#endif // BUBBLESORT_H