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
    EXPECT_EQ(0, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
