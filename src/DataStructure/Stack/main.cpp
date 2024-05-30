#include <iostream>
#include <gtest/gtest.h>
#include "stack.h"
using namespace std;

TEST(TestStack, testStringType) {
    mrroot501::Stack <string> s;
    // EXPECT_EQ(s.size(), 0);
    s.pop();
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    EXPECT_EQ(s.size(), 6);
    s.pop();
    EXPECT_EQ(s.size(), 5);
}

TEST(TestStack, testIntType) {
    mrroot501::Stack <int> s;
    // EXPECT_EQ(s.size(), 0);
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.size(), 3);
    s.pop();
    EXPECT_EQ(s.size(), 2);
    s.printStack();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
