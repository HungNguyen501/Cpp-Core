#include <iostream>
#include <vector>
#include "SegmentTree.h"
#include "../../UnitTests.h"
using namespace mrroot501;
using namespace std;

int main() {
    vector<int> arr = {-28,-39,53,65,11,-56,-65,-39,-43,97};
    int n = arr.size();
    SegmentTree<int> segmentTree(arr);
    cout << segmentTree.querySumRanges(0, 0, n -1, 5, 6) << "\n";
    segmentTree.update(9,27, 0, 0, n - 1);
    cout << segmentTree.querySumRanges(0, 0, n -1, 2,3) << "\n";
    cout << segmentTree.querySumRanges(0, 0, n -1, 6,7) << "\n";
    segmentTree.update(1,-82, 0, 0, n - 1);
    segmentTree.update(3,-72, 0, 0, n - 1);
    cout << segmentTree.querySumRanges(0, 0, n -1, 3,7) << "\n";
    cout << segmentTree.querySumRanges(0, 0, n -1, 1,8) << "\n";
    segmentTree.update(5,13, 0, 0, n - 1);
    segmentTree.update(4,-67, 0, 0, n - 1);

    return 0;
}
