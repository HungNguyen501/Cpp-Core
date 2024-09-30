#include <iostream>
#include "interval_tree.h"
using namespace std;

int main() {
    mrroot501::IntervalTree<int> tree;
    cout << tree.inserted(15, 20) << "\n";
    cout << tree.inserted(10, 12) << "\n";
    cout << tree.inserted(17, 19) << "\n";
    cout << tree.inserted(5, 7) << "\n";
    cout << tree.inserted(12, 15) << "\n";
    cout << tree.inserted(30, 40) << "\n";
    tree.traversalInorder();
    mrroot501::ITNode<int> *n1 = tree.findOverlapping(new mrroot501::ITNode<int>(35, 50));
    cout << "35-50 overlaps with " << n1->getFromValue() << "-" << n1->getToValue() << "\n";
    return 0;
}
