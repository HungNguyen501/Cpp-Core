#include <iostream>

namespace mrroot501 {

template<typename T>
class LLNode {
public:
    T data;
    LLNode *next;
    LLNode();
    LLNode(T value) {
        this->data = value;
        this->next = NULL;
    }
};

template class LLNode<int>;
template class LLNode<std::string>;

template <> LLNode<int>::LLNode() {
    this->data = -1;
    this->next = NULL;
}

template <> LLNode<std::string>::LLNode() {
    this->data = "";
    this->next = NULL;
}

// Doubly Linked List Node
template<typename T>
class DLLNode {
public:
    T data;
    DLLNode *next, *prev;
    DLLNode();
    DLLNode(T value) {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

template class DLLNode<int>;
template class DLLNode<std::string>;

template <> DLLNode<int>::DLLNode() {
    this->data = -1;
    this->next = NULL;
    this->prev = NULL;
}

template <> DLLNode<std::string>::DLLNode() {
    this->data = "";
    this->next = NULL;
    this->prev = NULL;
}

} // namespace mrroot501
