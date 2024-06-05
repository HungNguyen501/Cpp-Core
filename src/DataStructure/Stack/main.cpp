#include <iostream>
#include <gtest/gtest.h>
#include "stack.h"
using namespace std;

TEST(TestStack, testIntType) {
    mrroot501::Stack <int> tc1;
    EXPECT_EQ(tc1.size(), 0);
    tc1.pop();
    tc1.push(1);
    tc1.push(2);
    tc1.push(3);
    tc1.pop();
    EXPECT_EQ(tc1.size(), 2);
    tc1.printStack();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
