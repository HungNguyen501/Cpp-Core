#include <iostream>
#include <string>
#include <vector>
#include "header.h"
using namespace std;

int main() {
    // Input
    string allowed = "cad";
    vector<string> words = {"cc","acd","b","ba","bac","bad","ac","d"};
    int expected = 4;
    // Output
    int actual = countConsistentStrings(allowed, words);
    cout << "Actual=" << actual << " vs " << "expected=" << expected << ".\n";
    return 0;
}
