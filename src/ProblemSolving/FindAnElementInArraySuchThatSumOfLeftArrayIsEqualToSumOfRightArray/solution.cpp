#include <iostream>
using namespace std;

/*
    Link: https://www.geeksforgeeks.org/find-element-array-sum-left-array-equal-sum-right-array/
*/

int findElement(int arr[], int n) {
    int curSum[n];
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += arr[i];
        curSum[i] = temp;
    }
    for (int i = 1; i < n - 1; i++) {
        if (curSum[i] - arr[i] == curSum[n-1] - curSum[i]) {
            return arr[i];
        }
    }
    
    return -1;
}
