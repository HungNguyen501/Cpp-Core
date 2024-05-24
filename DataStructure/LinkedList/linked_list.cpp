#include <iostream>

namespace mrroot501 {

template<typename T>
class Node {
public:
    T data;
    Node *next;
    Node(T d) {
        data=d;
        next=NULL;
    }
};

template<typename T>
class LinkedList {
public:
    Node<T>* insert(Node<T> *head, T data) {
        if (head == NULL) {
            return new Node<T>(data);
        } else {
            Node<T> *cur = insert(head->next, data);
            head->next = cur;
            return head;
        }
    }

    Node<T>* reverse(Node<T>* node) {
        Node<T>* cur = node;
        Node<T>* prev = NULL;
        while(cur) {
            Node<T>* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }

    void del(Node<T> *head, T data) {
        if (head->data == data) {
            head = head->next;
            return;
        }
        Node<T> *r = head->next;
        Node<T> *last_node = head;
        while (r) {
            if (r->data == data) {
                last_node->next = r->next;
                r = nullptr;
                return;
            }
            last_node = r;
            r = r->next;
        }
    }

    void display(Node<T> *head) {
        Node<T> *start=head;
        while(start) {
            std::cout<<start->data<<" ";
            start=start->next;
        }
        std::cout << std::endl;
    }
};

template class Node<int>;
template class LinkedList<int>;

} // namespace mrroot501
