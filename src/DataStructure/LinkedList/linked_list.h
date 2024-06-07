#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "ll_node.h"

namespace mrroot501 {

template<typename T>
class LinkedList {
public:
    LLNode<T> *head;
    LinkedList();
    LinkedList(T data);
    void append(LLNode<T> *node);
    void reverse();
    void remove(T data);
    std::string print();
};

} // namespace mrroot501

#endif