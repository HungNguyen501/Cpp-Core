#ifndef _MERGESORT_
#define _MERGESORT_

#include <iostream>

namespace mrroot501 {

/*
    MergeSort: https://www.programiz.com/dsa/merge-sort
    Space complexity: O(n)
    Time complexity
        Best case: O(n*log n)
        Worst case: O(n*log n)
        Average case: O(n*log n)

*/

template<typename T>
void mergeHalfs(T arr[], int leftStart, int rightEnd) {
    if (leftStart >= rightEnd) {return;}
    int leftEnd = (leftStart + rightEnd) / 2;
    int rightStart = leftEnd + 1;
    int left = leftStart, right = rightStart;
    T temp[rightEnd - leftStart + 1];
    int index = 0;
    while (left <= leftEnd && right <= rightEnd)
    {
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left];
            left++;
        }
        else {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }
    while (left <= leftEnd)
    {
        temp[index] = arr[left];
        left++;
        index++;
    }
    while (right <= rightEnd)
    {
        temp[index] = arr[right];
        right++;
        index++;
    }
    for (int i = leftStart; i <= rightEnd; i++) {
        arr[i] = temp[i - leftStart];
    }
}

template<typename T>
void mergeSort(T arr[], int leftStart, int rightEnd) {
    if (leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd) / 2;
    mergeSort(arr, leftStart, middle);
    mergeSort(arr, middle + 1, rightEnd);
    mergeHalfs(arr, leftStart, rightEnd);
}

} // namespace mrroot501

#endif
