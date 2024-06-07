#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include "ll_node.h"

namespace mrroot501 {

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    void append(DLLNode<T> *node);
    void remove(T data);
    std::string print();
};

} // namespace mrroot501

#endif
