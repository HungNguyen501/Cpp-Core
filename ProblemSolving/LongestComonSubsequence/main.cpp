#include <iostream>
#include <string>
#include "../../UnitTests.h"
using namespace std;

int findLongestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    int matrix[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                matrix[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
            }
        }
    }
    return matrix[n][m];
}

int main() {
    vector<tuple<tuple<string, string>, int>> testCases = {
        {{"AGGTAB", "GXTXAYB"}, 4},
        {{"abcde", "ace"}, 3},
        {{"abc", "abc"}, 3},
        {{"abc", "def"}, 0}
    };
    for (int tc = 0; tc < testCases.size(); tc++) {
        string text1 = get<0>(get<0>(testCases[tc]));
        string text2 = get<1>(get<0>(testCases[tc]));
        int expected = get<1>(testCases[tc]);
        runTest<int>(findLongestCommonSubsequence(text1, text2), expected);
    }
    return 0;
}

