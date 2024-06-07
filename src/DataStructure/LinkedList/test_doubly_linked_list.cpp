#include <iostream>
#include <gtest/gtest.h>
#include "doubly_linked_list.h"
using namespace std;

TEST(TestDoublyLinkedList, testIntType) {
    int int_input[] = {0, 2, 3, 4, 5, 6, 1, 1, 1, 7, 8, 9, 1, 1, 10};
    mrroot501::DoublyLinkedList<int> my_list = mrroot501::DoublyLinkedList<int>();
    for (int i = 0; i < 15; i++) {
        mrroot501::DLLNode<int> *node = new mrroot501::DLLNode<int>(int_input[i]);
        my_list.append(node);
    }
    cout << my_list.print() << "\n";
    // EXPECT_EQ(my_list.print(), "0 2 3 4 5 6 1 1 1 7 8 9 1 1 10 ");
    my_list.remove(1);
    // EXPECT_EQ(my_list.print(), "0 2 3 4 5 6 7 8 9 10 ");
    cout << my_list.print() << "\n";
}

TEST(TestDoublyLinkedList, testStringType) {
    string str_input[] = {"a", "b", "c", "d", "e", "f", "g", "h", "a"};
    mrroot501::DoublyLinkedList<string> my_list = mrroot501::DoublyLinkedList<string>();
    for (int i = 0; i < 9; i++) {
        mrroot501::DLLNode<string> *node = new mrroot501::DLLNode<string>(str_input[i]);
        my_list.append(node);
    }
    // EXPECT_EQ(my_list.print(), "a b c d e f g h a ");
    cout << my_list.print() << "\n";
    my_list.remove("a");
    // EXPECT_EQ(my_list.print(), "b c d e f g h ");
    cout << my_list.print() << "\n";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
