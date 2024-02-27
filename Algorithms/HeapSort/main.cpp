#include "iostream"
using namespace std;

/*
    HeapSort: https://www.programiz.com/dsa/heap-sort
    Time complexity: O(nlogn) for all cases (best case, average case and worst case)
        Build_fist_heap_tree: n/2*logn
        Build_heap_for_remaining_tree: nlogn
*/

void heapify(int arr[], int n, int rootElement) {
    int largestElement = rootElement;
    int leftChild = 2 * rootElement + 1;
    int rightChild = 2 * rootElement + 2;
    if (leftChild < n && arr[largestElement] < arr[leftChild]) {
        largestElement = leftChild;
    }
    if (rightChild < n && arr[largestElement] < arr[rightChild]) {
        largestElement = rightChild;
    }
    if (rootElement != largestElement) {
        swap(arr[rootElement], arr[largestElement]);
        heapify(arr, n, largestElement);
    }
}

void heapSort(int arr[], int n) {
    // Build first heap tree from (n/2-1)-th node that is deepest node having child node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move root node of heap tree to right side of array
        heapify(arr, i, 0); // Heapify remaining tree
    }
}

int main() {
    int arr[] = {9, 7, 11, 32, 45, 0, 1, 27, 28, 45, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
