#include <iostream>
#include <vector>
#include <tuple>
#include "../../UnitTests.h"
using namespace std;

int* preCals(int arr[], int n) {
    static int preCals[10000];
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += arr[i];
        preCals[i] = count;
    }
    return preCals;
}

int rangeSumQuery(int left, int right, int preCals[]) {
    int preLeftHalf = (left == 0) ? 0 : preCals[left - 1];
    return preCals[right] - preLeftHalf;
}

int main() {
    int arr[] =  {-2, 0, 3, -5, 2, -1};
    vector<tuple<vector<int>, int>> testCases;
    testCases.push_back({{0, 2}, 1});
    testCases.push_back({{2, 5}, -1});
    testCases.push_back({{0, 5}, -3});
    int n = sizeof(arr)/ sizeof(arr[0]);
    int* rangeSum = preCals(arr, n);
    for (int tc = 0; tc < testCases.size(); tc++) {
        int expected = get<1>(testCases[tc]);
        int actual = rangeSumQuery(get<0>(testCases[tc])[0], get<0>(testCases[tc])[1], rangeSum);
        runTest<int>(actual, expected);
    }
    
    return 0;
}
