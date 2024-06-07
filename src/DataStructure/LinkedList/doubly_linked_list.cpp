#include <iostream>
#include "ll_node.h"

namespace mrroot501 {

template<typename T>
class DoublyLinkedList {
public:
    DLLNode<T> *head, *tail;
    unsigned int size;
    DoublyLinkedList() {
        this->size = 0;
        this->head = new DLLNode<T>();
        this->tail = new DLLNode<T>();
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    void append(DLLNode<T> *node) {
        this->size++;
        DLLNode<T> *last_node = this->tail->prev;
        last_node->next = node;
        this->tail->prev = node;
        node->prev = last_node;
        node->next = this->tail;
    }
    void remove(T data) {
        if (this->size == 0) {
            return;
        }
        DLLNode<T> *node = this->head->next;
        while (node != this->tail) {
            DLLNode<T> *next_node = node->next;
            if (node->data == data) {
                DLLNode<T> *prev_node = node->prev;
                prev_node->next = next_node;
                next_node->prev = prev_node;
                delete node;
                this->size--;
            }
            node = next_node;
        }
    }
    std::string print();
};

template class DoublyLinkedList<int>;
template class DoublyLinkedList<std::string>;

template <> std::string DoublyLinkedList<int>::print()  {
    std::string result = "";
    DLLNode<int> *node = this->head->next;
    while (node != this->tail) {
        result += (std::to_string(node->data) + " ");
        node = node->next;
    }
    return result;
}

template <> std::string DoublyLinkedList<std::string>::print()  {
    std::string result = "";
    DLLNode<std::string> *node = this->head->next;
    while (node != this->tail) {
        result += (node->data + " ");
        node = node->next;
    }
    return result;
}

} // namespace mrroot501
