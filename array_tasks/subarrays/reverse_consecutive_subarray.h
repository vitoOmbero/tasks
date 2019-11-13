#ifndef REVERSE_CONSECUTIVE_SUBARRAY_H
#define REVERSE_CONSECUTIVE_SUBARRAY_H


#include "subarray.h"

void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void reverse_subarray(int arr[], int i, int j)
{
    while (i < j)
    {
        swap(arr, i, j);
        i++, j--;
    }
}

int* reverse_each_subgroup(int array[], int start_index, int end_index, int subgroup_length)
{
    // return if sub-array length is less than m
    if (subgroup_length > end_index - start_index + 1) {
        return array;
    }

    // reverse every consecutive m elements
    for (int i = start_index; i <= end_index; i = i + subgroup_length)
    {
        // check if subarray length is atleast m
        if (i + subgroup_length - 1 <= end_index) {
            reverse_subarray(array, i, i + subgroup_length - 1);
        }
    }

    return array;
}

#endif // REVERSE_CONSECUTIVE_SUBARRAY_H
