#include <iostream>
#include <vector>
#include "header.h"
using namespace std;

int main() {
    vector<vector<int>> input = { {15, 18},{1, 3}, {8, 10}, {2, 6}};
    vector<vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> actual = merge(input);
    cout << "Expected: [ ";
    for (vector<int> i: expected) {
        cout << "[" << i[0] << ", " << i[1] << "], ";
    }
    cout << "]\n";
    cout << "Actual: [ ";
    for (vector<int> i: actual) {
        cout << "[" << i[0] << ", " << i[1] << "], ";
    }
    cout << "]\n";
    return 0;
}
