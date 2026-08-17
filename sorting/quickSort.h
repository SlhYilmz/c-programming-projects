#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "helperFunctions.h"

// Time complexity:
// Worst:   O(n^2)      - Pivot is either the smallest element, or the largest element
// Best:    O(n.logn)   - Pivot is the middle element, or near the middle.
// Average: O(n.logn)   - Unordered list of elements.

// function to find the partition position
int partition(int array[], int low, int high)
{
    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pivot = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pivot - 1);

        // recursive call on the right of pivot
        quickSort(array, pivot + 1, high);
    }
}

#endif // QUICKSORT_H