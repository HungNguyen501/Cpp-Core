#include "../Queue/queue.h"

namespace mrroot501 {

template <class T>
class MessageQueue : public Mrroot501Queue<Message<int>> {
public:
    // unsigned int max_length, length;
    // int head, tail;
    // T *arr;
    long byte_size, byte_capacity;
    MessageQueue() {};
    MessageQueue(int max_length, int byte_capacity) {
        this->max_length = max_length;
        this->byte_capacity = byte_capacity;
        this->head = this->tail = this->length = 0;
        this->byte_size = 0;
        this->arr = new T[1000000];
    }
    long getByteSize() {
        return this->byte_size;
    }
    bool isFull() {
        return (this->max_length == this->length || this->byte_capacity <= this->byte_size);
    }
    // bool isEmpty() {
    //     return (this->length == 0);
    // }
    void enqueue(T value) {
        if (isFull() || this->byte_size + value.byte_size > this->byte_capacity) {
            std::cout << "Cannot enqueue beacause queue is full.\n";
            return;
        }
        this->length++;
        this->byte_size += value.byte_size;
        this->arr[this->tail % this->max_length] = value;
        this->tail = this->tail % this->max_length + 1;
    };
    T front() {
        if (this->isEmpty()) {
            return T();
        }
        return this->arr[this->head];
    }
    T dequeue() {
        if (this->isEmpty()) {
            std::cout << "Queue is empty.\n";
            return T();
        }
        T temp = this->front();
        this->length--;
        this->byte_size -= temp.byte_size;
        this->head = (this->head + 1) % this->max_length;
        return temp;
    }
};

template class MessageQueue<Message<int>>;

} // namespace mrroot501
