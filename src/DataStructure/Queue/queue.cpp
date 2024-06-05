#include <iostream>

namespace mrroot501 {

template <typename T>
class Mrroot501Queue {
private:
    unsigned int capacity, size, head, tail;
    T *arr;
public:
    Mrroot501Queue(unsigned int capacity) {
        this->capacity = capacity;
        this->head = this->tail = this->size = 0;
        this->arr = new T[capacity];
    }
    unsigned int getSize() {
        return this->size;
    }
    bool isEmpty() {
        return (this->size == 0);
    }
    bool isFull() {
        return (this->capacity == this->size);
    }
    void enqueue(T value) {
        if (isFull()) {
            std::cout << "Cannot enqueue with value=" << value <<  " beacause queue is full.\n";
            return;
        }
        this->size++;
        this->arr[this->tail % this->capacity] = value;
        this->tail = this->tail % this->capacity + 1;
    };
    T dequeue();
    std::string print();
};

template class Mrroot501Queue<int>;
template class Mrroot501Queue<std::string>;

template <> int Mrroot501Queue<int>::dequeue() {
    if (this->isEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    this->size--;
    int temp = this->arr[this->head];
    this->head = (this->head + 1) % this->capacity;
    return temp;
}

template <> std::string Mrroot501Queue<std::string>::dequeue() {
    if (this->isEmpty()) {
        std::cout << "Queue is empty.\n";
        return "";
    }
    this->size--;
    std::string temp = this->arr[this->head];
    this->head = (this->head + 1) % this->capacity;
    return temp;
}

template <> std::string Mrroot501Queue<int>:: print() {
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
        i = (i + 1) % this->capacity;
    }
    return result;
}

template <> std::string Mrroot501Queue<std::string>:: print() {
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
        i = (i + 1) % this->capacity;
    }
    return result;
}

} // namespace mrroot501
