#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[0m"

string extraLongFactorial(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    string result = "";
    vector<int> factorial;
    factorial.push_back(2);
    for (int i = 3; i <= n; i++) {
        int tempScore = 0;
        for (int j = 0; j < factorial.size(); j++) {
            tempScore = factorial[j] * i + tempScore;
            factorial[j] = tempScore % 10;
            tempScore /= 10;

            if (j == factorial.size() - 1 && tempScore > 0) {
                factorial.push_back(tempScore);
                break;
            }
        }
    }
    for (int i = factorial.size() - 1; i >= 0; i--) {
        result += to_string(factorial[i]);
    }
    return result;
}

int main() {
    vector<tuple<int, string>> testCases;
    testCases.push_back({0, "0"});
    testCases.push_back({1, "1"});
    testCases.push_back({20, "2432902008176640000"});
    testCases.push_back({27, "10888869450418352160768000000"});
    testCases.push_back({31, "8222838654177922817725562880000000"});
    for (int tc = 0; tc < testCases.size(); tc++) {
        string actual = extraLongFactorial(get<0>(testCases[tc]));
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
