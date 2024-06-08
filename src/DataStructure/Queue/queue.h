#ifndef _MESSAGE_QUEUE_H_
#define _MESSAGE_QUEUE_H_

namespace mrroot501 {

template <typename T>
class Mrroot501Queue {
public:
    unsigned int capacity, size;
    int head, tail;
    T *arr;
    Mrroot501Queue();
    Mrroot501Queue(unsigned int capacity);
    unsigned int getSize();
    bool isEmpty();
    bool isFull();
    void enqueue(T value);
    T dequeue();
    std::string print();
};

} // namespace mrroot501

#endif
