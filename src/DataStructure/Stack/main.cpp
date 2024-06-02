#include <iostream>
#include <gtest/gtest.h>
#include "stack.h"
using namespace std;

TEST(TestStack, testIntType) {
    mrroot501::Stack <int> tc1;
    // int actual_size;
    // actual_size = s.size();
    // EXPECT_EQ(actual_size, 0);
    cout << "size=" << tc1.size() << "\n";
    tc1.pop();
    tc1.push(1);
    tc1.push(2);
    tc1.push(3);
    tc1.pop();
    // actual_size = s.size();
    cout << "size=" << tc1.size() << "\n";
    // EXPECT_EQ(actual_size, 2);
    tc1.printStack();
}

TEST(TestStack, testStringType) {
    mrroot501::Stack <string> tc2;
    // int actual_size;
    // actual_size = s.size();
    cout << "size=" << tc2.size() << "\n";
    // EXPECT_EQ(actual_size, 0);
    // s.pop();
    // s.push("a");
    // s.push("a");
    // s.push("a");
    // s.push("a");
    // s.push("a");
    // s.push("a");
    // s.pop();
    // // actual_size = s.size();
    // cout << "size=" << s.size() << "\n";
    // // EXPECT_EQ(actual_size, 5);
    // s.printStack();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
