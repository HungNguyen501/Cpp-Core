#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

namespace mrroot501 {

template<typename T>
class Node {
public:
    T data;
    Node *next;
    Node(T d);
};

template<typename T>
class LinkedList {
public:
    LinkedList(Node<T> node);
    void append(Node<T> node);
    // void reverse();
    // void del(Node<T> *head, T data);
    void show();
};

} // namespace mrroot501

#endif
