#include <iostream>
#include <vector>
#include <string>
#include "../../UnitTests.h"
using namespace std;

/*
    Article: https://www.scaler.com/topics/longest-palindromic-substring/
    Time complexity: O(n^2)
    Space complexity: O(1)
*/

int expandArrountCenter(string s, int left, int right) {
    int i = left, j = right;
    while (s[i] == s[j] && i >= 0 && j < s.length())
    {
        i--;
        j++;
    }
    return j - i - 1;
}

string findLongestPalindromicSubstring(string s) {
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

int main() {
    vector<tuple<string, string>> testCases = {
        {"nothing","n"},
        {"abcbedrardea","edrarde"},
        {"findnitianhere","indni"},
        {"axdabcddcbaaaa", "abcddcba"}
    };
    for (int tc = 0; tc < testCases.size(); tc++) {
        string expected = get<1>(testCases[tc]);
        runTest<string>(findLongestPalindromicSubstring(get<0>(testCases[tc])), expected);
    }

    return 0;
}
