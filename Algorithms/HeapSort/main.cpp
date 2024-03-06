#include "iostream"
#include "HeapSort.h"
using namespace mrroot501;
using namespace std;

/*
    HeapSort: https://www.programiz.com/dsa/heap-sort
    Time complexity: O(nlogn) for all cases (best case, average case and worst case)
        Build_fist_heap_tree: n/2*logn
        Build_heap_for_remaining_tree: nlogn
*/

int main() {
    int arr1[] = {9, 7, 11, 32, 45, 0, 1, 27, 28, 45, 9};
    int arr2[] = {9, 7, 11, 32, 45, 0, 1, 27, 28, 45, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    HeapNode<int> *heapTree1 = new HeapNode<int>[n];
    HeapNode<int> *heapTree2 = new HeapNode<int>[n];
    for (int i = 0; i < n; i++) {
        heapTree1[i] = arr1[i];
        heapTree2[i] = arr2[i];
    }
    MaxHeap<int> maxHeap = MaxHeap<int>(heapTree1, n);
    MinHeap<int> minHeap = MinHeap<int>(heapTree2, n);
    maxHeap.heapSort();
    minHeap.heapSort();
    cout << "MaxHeap: ";
    for (int i = 0; i < maxHeap.size; i++) {
        cout << maxHeap.pointer[i].data << " ";
    }
    cout << "\n";
    cout << "MinHeap: ";
    for (int i = 0; i < minHeap.size; i++) {
        cout << minHeap.pointer[i].data << " ";
    }
    cout << "\n";
    return 0;
}
