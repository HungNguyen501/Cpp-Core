#include <iostream>
#include <vector>

namespace mrroot501 {

std::string extraLongFactorial(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    std::string result = "";
    std::vector<int> factorial;
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
        result += std::to_string(factorial[i]);
    }
    return result;
}

}