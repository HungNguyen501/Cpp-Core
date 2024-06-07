#include <iostream>
#include <gtest/gtest.h>
#include "linked_list.h"
using namespace std;

TEST(TestLinkedList, testIntType) {
    int int_input[] = {0, 2, 3, 4, 5, 6, 1, 1, 1, 7, 8, 9, 1, 1, 10};
    mrroot501::LinkedList<int> my_list = mrroot501::LinkedList<int>();
    for (int i = 0; i < 15; i++) {
        mrroot501::LLNode<int> *node = new mrroot501::LLNode<int>(int_input[i]);
        my_list.append(node);
    }
    EXPECT_EQ(my_list.print(), "0 2 3 4 5 6 1 1 1 7 8 9 1 1 10 ");
    my_list.remove(1);
    EXPECT_EQ(my_list.print(), "0 2 3 4 5 6 7 8 9 10 ");
}

TEST(TestLinkedList, testStringType) {
    string str_input[] = {"a", "b", "c", "d", "e", "f", "g", "h", "a"};
    mrroot501::LinkedList<string> my_list = mrroot501::LinkedList<string>();
    for (int i = 0; i < 9; i++) {
        mrroot501::LLNode<string> *node = new mrroot501::LLNode<string>(str_input[i]);
        my_list.append(node);
    }
    EXPECT_EQ(my_list.print(), "a b c d e f g h a ");
    my_list.remove("a");
    EXPECT_EQ(my_list.print(), "b c d e f g h ");
}

TEST(TestLinkedList, testLLWithOneElement) {
    string str_input[] = {"a"};
    mrroot501::LinkedList<string> my_list = mrroot501::LinkedList<string>();
    for (int i = 0; i < 1; i++) {
        mrroot501::LLNode<string> *node = new mrroot501::LLNode<string>(str_input[i]);
        my_list.append(node);
    }
    my_list.remove("b");
    EXPECT_EQ(my_list.print(), "a ");
    my_list.remove("a");
    EXPECT_EQ(my_list.print(), "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
