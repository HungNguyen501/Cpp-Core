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
    Node<T>* insert(Node<T> *head, T data);
    Node<T>* reverse(Node<T>* node);
    void del(Node<T> *head, T data);
    void display(Node<T> *head);
};

} // namespace mrroot501

#endif
