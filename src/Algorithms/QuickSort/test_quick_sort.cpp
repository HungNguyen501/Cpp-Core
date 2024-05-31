#include <gtest/gtest.h>
#include "quick_sort.h"

TEST(TestQuickeSort, tc1) {
    int a[] = {18, 5, 7, 9, 11, 6, 7, 4, 15};
    mrroot501::quickSort(a, 0, sizeof(a) / sizeof(int) - 1);
    std::string actual = "";
    for (int i : a) {
        actual += (std::to_string(i) + " ");
    }
    EXPECT_EQ(actual, "4 5 6 7 7 9 11 15 18 ");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
