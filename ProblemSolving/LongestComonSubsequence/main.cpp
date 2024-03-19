#include <iostream>
#include <string>
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
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << findLongestCommonSubsequence(s1, s2) << "\n";
    return 0;
}

