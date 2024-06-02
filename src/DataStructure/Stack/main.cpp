#include <iostream>
#include <gtest/gtest.h>
#include "stack.h"
using namespace std;

TEST(TestStack, testIntType) {
    mrroot501::Stack <int> tc1;
    cout << "size=" << tc1.size() << "\n";
    tc1.pop();
    tc1.push(1);
    tc1.push(2);
    tc1.push(3);
    tc1.pop();
    cout << "size=" << tc1.size() << "\n";
    tc1.printStack();
}

TEST(TestStack, testStringType) {
    mrroot501::Stack <string> tc2;
    cout << "size=" << tc2.size() << "\n";
    tc2.pop();
    tc2.push("a");
    tc2.push("a");
    tc2.push("a");
    tc2.push("a");
    tc2.push("a");
    tc2.push("a");
    tc2.pop();
    tc2.printStack();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
