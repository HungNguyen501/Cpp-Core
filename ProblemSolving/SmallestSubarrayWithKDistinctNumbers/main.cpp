#include <iostream>
#include <fstream>
#include <array>
using namespace std;

/*
Problem: https://www.geeksforgeeks.org/smallest-subarray-k-distinct-numbers/
*/

array<int, 2> solution(int arr[], int n, int k) {
    array<int, 2> results = {-1, -1};
    unordered_map<int, int> map;
    int start = 0, end = n - 1;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int value = arr[i];
        map[value]++;
        r = i;;
        if (map.size() < k) {
            continue;
        }
        while (map.size() == k) {
            int lenWindow = r - l + 1;
            int lenSubArray = end - start + 1;
            if (lenWindow < lenSubArray) {
                start = l;
                end = r;
            }
            int leftValue = arr[l];
            if (map[leftValue] == 1) {
                map.erase(leftValue);
            } else {
                map[leftValue]--;
            }
            l++;
        }
    }
    if (start != 0 || end != n - 1) {
        results[0] = start;
        results[1] = end;
    }
    return results;
}

int main() {
    int expectedOutput[3][2] = {{5, 7}, {-1, -1}, {0, 1}};
    ifstream read;
    read.open("SmallestSubarrayWithKDistinctNumbers/input.txt");
    int tc;
    read >> tc;
    for (int t = 0; t < tc; t++) {
        int n, k;
        read >> n >> k;
        int arr[100000];
        for (int i = 0; i < n; i++) {
            int a;
            read >> a;
            arr[i] = a;
            
        }
        array<int, 2> results = solution(arr, n, k);
        if (results[0] == -1 || results[1] == -1) {
            cout << "Invalid k" << "\n";
        }
        else if (results[0] == expectedOutput[t][0] && results[1] == expectedOutput[t][1]) {
            cout << results[0] << " " << results[1] << "\n";
        } else {
            cout << "Failed testcase " << t + 1 << ": "
                << "expected output (" << expectedOutput[t][0] << ", " << expectedOutput[t][1]
                << ") vs results (" << results[0] << ", " << results[1] << ")" << "\n";
        }
    }

    return 0;
}
