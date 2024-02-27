#include <iostream>
using namespace std;

/*
    QuickSort: https://www.programiz.com/dsa/quick-sort
    Time complexity:
        Stability: No
        Space complexity: O(logn)
        Time complexity:
            Best case: O(nlogn), when pivot element is always the middle element or near to the middle element of array
            Average case: O(nlogn)
            Worst case: O(n2), it occurs when the pivot element picked is either the smallest or the greatest element of sub array,
                It leads to the case in which one sub-array is always empty and another contains n-1 elements.
*/

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int l, int r) {
    if (l >= r) return;

    int pivot = arr[l];
    int i = l;
    int j = r;

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if(i <= j) swap(&arr[i++], &arr[j--]);
    }

    quickSort(arr, l, j);
    quickSort(arr, i, r);
}

int main() {
    int arr[] = {18, 5, 7, 9, 11, 6, 7, 4, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}