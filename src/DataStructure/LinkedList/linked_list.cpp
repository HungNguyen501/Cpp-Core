#include <iostream>

namespace mrroot501 {

template<typename T>
class Node {
public:
    T data;
    Node *next, *prev;
    Node(T value) {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

template class Node<int>;
template class Node<std::string>;
template<typename T>
class LinkedList {
private:
    Node<T> *head, *tail;
    unsigned int size;
public:
    LinkedList(Node<T> node) {
        this->size = 0;
        head->next = &node;
        tail->prev = &node;
        node.prev = head;
        node.next = tail;
    }
    void append(Node<T> node) {
        this->size++;
        Node<T> *temp = this->tail->prev;
        temp->next = &node;
        node.prev = temp;
        node.next = this->tail;
        this->tail->prev = &node;
    }
    // void reverse() {
    //     Node<T>* cur = this->head->next;
    //     Node<T>* prev = this->tail;
    //     while(cur->next != this->tail) {
    //         Node<T>* nextNode = cur->next;
    //         cur->next = prev;
    //         cur->prev = nextNode;
    //         prev = cur;
    //         cur = nextNode;
    //     }
        
    // }

    // void del(Node<T> *head, T data) {
    //     if (head->data == data) {
    //         head = head->next;
    //         return;
    //     }
    //     Node<T> *r = head->next;
    //     Node<T> *last_node = head;
    //     while (r) {
    //         if (r->data == data) {
    //             last_node->next = r->next;
    //             r = nullptr;
    //             return;
    //         }
    //         last_node = r;
    //         r = r->next;
    //     }
    // }

    void show() {
        Node<T> *start = this->head->next;
        while(start != this->tail) {
            std::cout << start->data << " ";
            start = start->next;
        }
        std::cout << "\n";
    }
};

template class LinkedList<int>;
template class LinkedList<std::string>;

} // namespace mrroot501
