#include <iostream>
#include <gtest/gtest.h>

/*
    Article: https://www.scaler.com/topics/longest-palindromic-substring/
    Time complexity: O(n^2)
    Space complexity: O(1)
*/

int expandArrountCenter(std::string s, int left, int right) {
    int i = left, j = right;
    while (s[i] == s[j] && i >= 0 && j < s.length())
    {
        i--;
        j++;
    }
    return j - i - 1;
}

std::string findLongestPalindromicSubstring(std::string s) {
    if (s.length() <= 0) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int lenFromOddCenter = expandArrountCenter(s, i, i);
        int lenFromEvenCenter = expandArrountCenter(s, i, i + 1);
        int maxLen = (lenFromEvenCenter > lenFromOddCenter ? lenFromEvenCenter : lenFromOddCenter);
        if (maxLen > end - start + 1) {
            start = i - (maxLen - 1)/2;
            end = start + maxLen - 1;
        }
    }
    return s.substr(start, end - start + 1);
}

TEST(TestLongestPalindromicSubstring, tc1) {
    EXPECT_EQ(findLongestPalindromicSubstring("nothing"), "n");
    EXPECT_EQ(findLongestPalindromicSubstring("abcbedrardea"), "edrarde");
    EXPECT_EQ(findLongestPalindromicSubstring("findnitianhere"), "indni");
    EXPECT_EQ(findLongestPalindromicSubstring("axdabcddcbaaaa"), "abcddcba");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
