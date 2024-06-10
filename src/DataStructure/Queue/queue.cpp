#include <iostream>
#include "message.h"

namespace mrroot501 {

template <class T>
class Mrroot501Queue {
public:
    unsigned int max_length, length;
    int head, tail;
    T *arr;
    Mrroot501Queue() {};
    Mrroot501Queue(unsigned int max_length) {
        this->max_length = max_length;
        this->head = this->tail = this->length = 0;
        this->arr = new T[max_length];
    }
    unsigned int getSize() {
        return this->length;
    }
    bool isEmpty() {
        return (this->length == 0);
    }
    bool isFull() {
        return (this->max_length == this->length);
    }
    void enqueue(T value) {
        if (isFull()) {
            std::cout << "Cannot enqueue beacause queue is full.\n";
            return;
        }
        this->length++;
        this->arr[this->tail % this->max_length] = value;
        this->tail = this->tail % this->max_length + 1;
    };
    T dequeue();
    std::string print();
};

template class Mrroot501Queue<int>;
template class Mrroot501Queue<std::string>;
template class Mrroot501Queue<Message<int>>;

template <> int Mrroot501Queue<int>::dequeue() {
    if (this->isEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    this->length--;
    int temp = this->arr[this->head];
    this->head = (this->head + 1) % this->max_length;
    return temp;
}

template <> std::string Mrroot501Queue<std::string>::dequeue() {
    if (this->isEmpty()) {
        std::cout << "Queue is empty.\n";
        return "";
    }
    this->length--;
    std::string temp = this->arr[this->head];
    this->head = (this->head + 1) % this->max_length;
    return temp;
}

template <> Message<int> Mrroot501Queue<Message<int>>::dequeue() {
    if (this->isEmpty()) {
        std::cout << "Queue is empty.\n";
        return Message<int>();
    }
    this->length--;
    Message<int> temp = this->arr[this->head];
    this->head = (this->head + 1) % this->max_length;
    return temp;
}

template <> std::string Mrroot501Queue<int>::print() {
    std::string result = "";
    if (this->isEmpty()) {
        return result;
    }
    int i = this->head;
    while (1) {
        result += (std::to_string(this->arr[i]) + " ");
        if (i == this->tail -1) {
            break;
        }
        i = (i + 1) % this->max_length;
    }
    return result;
}

template <> std::string Mrroot501Queue<std::string>::print() {
    std::string result = "";
    if (this->isEmpty()) {
        return result;
    }
    int i = this->head;
    while (1) {
        result += (this->arr[i] + " ");
        if (i == this->tail -1) {
            break;
        }
        i = (i + 1) % this->max_length;
    }
    return result;
}

template <> std::string Mrroot501Queue<Message<int>>::print() {
    std::cout << "This function is not implemented yet.\n";
    return "";
}

} // namespace mrroot501
