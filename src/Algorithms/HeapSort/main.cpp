#include "iostream"
#include "heap_sort.h"
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
    mrroot501::HeapNode<int> *heapTree1 = new mrroot501::HeapNode<int>[n];
    mrroot501::HeapNode<int> *heapTree2 = new mrroot501::HeapNode<int>[n];
    for (int i = 0; i < n; i++) {
        heapTree1[i] = arr1[i];
        heapTree2[i] = arr2[i];
    }
    mrroot501::MaxHeap<int> *maxHeap = new mrroot501::MaxHeap<int>(heapTree1, n);
    mrroot501::MinHeap<int> *minHeap = new mrroot501::MinHeap<int>(heapTree2, n);
    maxHeap->heapSort();
    minHeap->heapSort();
    cout << "MaxHeap: ";
    for (int i = 0; i < maxHeap->getSize(); i++) {
        cout << maxHeap->getPointer()[i].data << " ";
    }
    cout << "\n";
    cout << "MinHeap: ";
    for (int i = 0; i < minHeap->getSize(); i++) {
        cout << minHeap->getPointer()[i].data << " ";
    }
    cout << "\n";
    return 0;
}
