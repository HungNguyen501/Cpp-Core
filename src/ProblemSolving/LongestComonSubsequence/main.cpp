#include <iostream>
#include <tuple>
#include <vector>
#include <gtest/gtest.h>

int findLongestCommonSubsequence(std::string text1, std::string text2) {
    int n = text1.size(), m = text2.size();
    int matrix[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                matrix[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = std::max(matrix[i][j - 1], matrix[i - 1][j]);
            }
        }
    }
    return matrix[n][m];
}

TEST(TestExtraLongFactorial, tc1) {
    EXPECT_EQ(findLongestCommonSubsequence("AGGTAB", "GXTXAYB"), 4);
    EXPECT_EQ(findLongestCommonSubsequence("abcde", "ace"), 3);
    EXPECT_EQ(findLongestCommonSubsequence("abc", "abc"), 3);
    EXPECT_EQ(findLongestCommonSubsequence("abc", "def"), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
