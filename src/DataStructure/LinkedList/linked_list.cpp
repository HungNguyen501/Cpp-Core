#include <iostream>
#include "ll_node.h"

namespace mrroot501 {

template<typename T>
class LinkedList {
public:
    LLNode<T> *head;
    LinkedList();
    LinkedList(T data) {
        this->head = new LLNode<T>(data);
    }
    void append(LLNode<T> *node) {
        LLNode<T> *cur_node = this->head;
        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = node;
    }
    void reverse() {
        LLNode<T> *cur_node = this->head->next;
        LLNode<T> *prev_node = NULL;
        while(cur_node) {
            LLNode<T> *next_node = cur_node->next;
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = next_node;
        }
        this->head->next = prev_node;
    }
    void remove(T data) {
        LLNode<T> *cur_node = this->head->next;
        LLNode<T> *prev_node = this->head;
        while (cur_node) {
            if (cur_node->data == data) {
                LLNode<T> *next_node = cur_node->next;
                prev_node->next = next_node;
                delete cur_node;
                cur_node = next_node;
                continue;
            }
            prev_node = cur_node;
            cur_node = cur_node->next;
        }
    }
    std::string print();
};

template class LinkedList<int>;
template class LinkedList<std::string>;

template <> LinkedList<int>::LinkedList() {
    this->head = new LLNode<int>();
}

template <> LinkedList<std::string>::LinkedList() {
    this->head = new LLNode<std::string>();
}

template <> std::string LinkedList<int>::print()  {
    std::string result = "";
    LLNode<int> *node = this->head->next;
    while(node) {
        result += (std::to_string(node->data) + " ");
        node = node->next;
    }
    return result;
}

template <> std::string LinkedList<std::string>::print()  {
    std::string result = "";
    LLNode<std::string> *node = this->head->next;
    while(node) {
        result += (node->data + " ");
        node = node->next;
    }
    return result;
}

} // namespace mrroot501