#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "helperFunctions.h"

// Time Complexity: 
// One loop to select an element of Array one by one = O(N)
// Another loop to compare that element with every other Array element = O(N)
// Therefore overall complexity = O(N) * O(N) = O(N*N) = O(N^2) (Best and worst)
void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < size; j++)
        {
            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[j] < array[minimum])
                minimum = j;
        }

        // put min at the correct position
        swap(&array[minimum], &array[i]);
    }
}

#endif // SELECTIONSORT_H