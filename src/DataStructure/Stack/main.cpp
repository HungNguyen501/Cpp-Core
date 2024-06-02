#include <iostream>
#include <gtest/gtest.h>
#include "stack.h"
using namespace std;

TEST(TestStack, testIntType) {
    mrroot501::Stack <int> s;
    int actual_size;
    actual_size = s.size();
    // EXPECT_EQ(actual_size, 0);
    cout << "size=" << actual_size << "\n";
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    actual_size = s.size();
    cout << "size=" << actual_size << "\n";
    // EXPECT_EQ(actual_size, 2);
    s.printStack();
}

TEST(TestStack, testStringType) {
    mrroot501::Stack <string> s;
    int actual_size;
    actual_size = s.size();
    cout << "size=" << actual_size << "\n";
    // EXPECT_EQ(actual_size, 0);
    s.pop();
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.pop();
    actual_size = s.size();
    cout << "size=" << actual_size << "\n";
    // EXPECT_EQ(actual_size, 5);
    s.printStack();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
