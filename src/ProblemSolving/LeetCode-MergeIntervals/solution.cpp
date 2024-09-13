#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> *a, vector<int> *b) {
    vector<int> temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(vector<vector<int>>& intervals, int left, int right) {
    if (left >= right) return;
    int pivot = intervals[(left + right) / 2][0];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (intervals[i][0] < pivot) i++;
        while (intervals[j][0] > pivot) j--;

        if(i <= j) swap(&intervals[i++], &intervals[j--]);
    }

    quickSort(intervals, left, j);
    quickSort(intervals, i, right);
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    quickSort(intervals, 0, intervals.size() -1);
    vector<vector<int>> output;
    output.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++) {
        if (output.back()[1] >= intervals[i][0]) {
            output.back()[1] = max(output.back()[1], intervals[i][1]);
        } else {
            output.push_back(intervals[i]);
        }
    }
    return output;
}
