#include <iostream>
#include <gtest/gtest.h>
using namespace std;

int* preCals(int arr[], int n) {
    static int preCals[10000];
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += arr[i];
        preCals[i] = count;
    }
    return preCals;
}

int rangeSumQuery(int left, int right, int preCals[]) {
    int preLeftHalf = (left == 0) ? 0 : preCals[left - 1];
    return preCals[right] - preLeftHalf;
}

TEST(TestLongestPalindromicSubstring, tc1) {
    int arr[] =  {-2, 0, 3, -5, 2, -1};
    vector<tuple<vector<int>, int>> testCases;
    testCases.push_back({{0, 2}, 1});
    testCases.push_back({{2, 5}, -1});
    testCases.push_back({{0, 5}, -3});
    int n = sizeof(arr)/ sizeof(int);
    int* rangeSum = preCals(arr, n);
    EXPECT_EQ(rangeSumQuery(0, 2, rangeSum), 1);
    EXPECT_EQ(rangeSumQuery(2, 5, rangeSum), -1);
    EXPECT_EQ(rangeSumQuery(0, 5, rangeSum), -3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
