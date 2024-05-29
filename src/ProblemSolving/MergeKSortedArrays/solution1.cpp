#include <iostream>
using namespace std;

#define ARRAY_SIZE 4

void mergeArrays(int arr1[], int arr2[],  int n1, int n2, int output[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            output[k++] = arr1[i++];
        } else {
            output[k++] = arr2[j++];
        }
    }
    while (i < n1) output[k++] = arr1[i++];
    while (j < n2) output[k++] = arr2[j++];
}  

void mergeKArrays(int arr[][ARRAY_SIZE], int left,  int right, int output[]) {
    // If one array is in range
    if (left == right) {
        for (int l=0; l < ARRAY_SIZE; l++) {
            output[l] = arr[left][l];
        }
        return;
    }
    // If only two array are left then merge them
    if (right == left + 1) {
        mergeArrays(arr[left], arr[right], ARRAY_SIZE, ARRAY_SIZE, output);
        return;
    }

    int len_left = (right - left) / 2 + 1;
    int len_right = (right - left) / 2;
    int left_halve[ARRAY_SIZE * len_left];
    int right_halve[ARRAY_SIZE * len_right];

    mergeKArrays(arr, left, (left + right) / 2, left_halve);
    mergeKArrays(arr, (left + right)/2 + 1, right, right_halve);
    mergeArrays(left_halve, right_halve, ARRAY_SIZE * len_left, ARRAY_SIZE * len_right, output);
}            

void printArray(int arr[], int len) {
    for (int i = 0; i < len ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
	int arr[][ARRAY_SIZE] = {
        {2, 6, 12, 34},
        {1, 9, 20, 1000},
        {23, 34, 90, 2000}
    };
    int num_size = sizeof(arr) / sizeof(arr[0]);
    int output[ARRAY_SIZE * num_size];
    mergeKArrays(arr, 0, 2, output);
    printArray(output, ARRAY_SIZE * num_size - 1);
    return 0;
}