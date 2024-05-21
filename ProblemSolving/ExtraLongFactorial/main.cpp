#include <iostream>
#include <vector>
#include <tuple>
#include "extra_long_factorial.h"
using namespace std;

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[0m"

int main() {
    vector<tuple<int, string>> testCases;
    testCases.push_back({0, "0"});
    testCases.push_back({1, "1"});
    testCases.push_back({20, "2432902008176640000"});
    testCases.push_back({27, "10888869450418352160768000000"});
    testCases.push_back({31, "8222838654177922817725562880000000"});
    for (int tc = 0; tc < testCases.size(); tc++) {
        string actual = mrroot501::extraLongFactorial(get<0>(testCases[tc]));
        string expected = get<1>(testCases[tc]);
        if ( actual != expected) {
            cout << "<Failed>";
        } else {
            cout << BOLD_ON << "<Passed>" << BOLD_OFF;
        }
        cout << " Test case " << tc + 1 << ": ";
        cout << "expected=" << expected << " vs "
            << "actual=" << actual << "\n";
    }

    return 0;
}
