#include <iostream>
#include "../../Algorithms/HeapSort/heap_sort.h"
using namespace std;

#define ARRAY_SIZE 4

int *mergeKArrays(int arr[][ARRAY_SIZE], int numBulks) {
    // Store output array
    int *output = new int[numBulks * ARRAY_SIZE];
    int pointer[numBulks];
    // Create an heap node array containing first element of child arrays in parent array
    mrroot501::HeapNode<int> *heapArray = new mrroot501::HeapNode<int>[numBulks];
    for (int i = 0; i < numBulks; i++) {
        heapArray[i].data = arr[i][0];
        heapArray[i].index = i;
        pointer[i] = 1;
    }
    // Create a new MinHeap
    mrroot501::MinHeap<int> *minHeap = new mrroot501::MinHeap<int>(heapArray, numBulks);
    for (int i = 0; i < numBulks * ARRAY_SIZE; i++) {
        // Get the minimum element of minHeap and store it in output
        int rootIndex =  minHeap->getRoot().index;
        output[i] = minHeap->getRoot().data;
        if (pointer[rootIndex] < ARRAY_SIZE ) {
            minHeap->getPointer()[0].data = arr[rootIndex][pointer[rootIndex]];
            pointer[rootIndex]++;
        } else {
            minHeap->getPointer()[0].data = INT32_MAX;
        }
        minHeap->heapify(minHeap->getSize(), 0);
    }
    return output;
}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[][ARRAY_SIZE] = {
        {2, 6, 12, 34},
        {1, 9, 20, 157},
        {23, 34, 90, 837}
    };
    int numBulks = sizeof(arr) / sizeof(arr[0]);
    int *output = mergeKArrays(arr, numBulks);
    printArray(output, numBulks * ARRAY_SIZE);
    return 0;
}