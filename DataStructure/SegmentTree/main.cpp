#include <iostream>
#include <vector>
#include "SegmentTree.h"
#include "../../UnitTests.h"
using namespace mrroot501;
using namespace std;

int main() {
    vector<int> arr = {3, 1, 53, 10, 11, -2, -10, -39, -43, 39};
    int n = arr.size();
    MaxSegmentTree<int> segmentTree(arr);
    cout << segmentTree.queryRanges(0, 0, n -1, 2, 5) << "\n";
    segmentTree.update(3,-100, 0, 0, n - 1);
    cout << segmentTree.queryRanges(0, 0, n -1, 2, 5) << "\n";
    cout << segmentTree.queryRanges(0, 0, n -1, 4, 9) << "\n";
    return 0;
}
