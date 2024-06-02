#include <iostream>
#include <gtest/gtest.h>
#include "stack.h"
using namespace std;

TEST(TestStack, testIntType) {
    mrroot501::Stack <int> s;
    cout << "size=" << s.size() << "\n";
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout << "size=" << s.size() << "\n";
    EXPECT_EQ(int(s.size()), 2);
    s.printStack();
    EXPECT_EQ(0, 0);
}

TEST(TestStack, testStringType) {
    mrroot501::Stack <string> s;
    cout << "size=" << s.size() << "\n";
    s.pop();
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.pop();
    cout << "size=" << s.size() << "\n";
    s.printStack();
    EXPECT_EQ(0, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
