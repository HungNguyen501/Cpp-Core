#ifndef _MESSAGE_QUEUE_H_
#define _MESSAGE_QUEUE_H_

#include "message.h"

namespace mrroot501 {

template <class T>
class MessageQueue {
public:
    int max_length, length;
    int head, tail;
    Message<T> *arr;
    long byte_size, byte_capacity;
    MessageQueue();
    MessageQueue(int max_length, int byte_capacity);
    long getByteSize();
    bool isFull();
    bool isEmpty();
    void enqueue(Message<T> value);
    Message<T> front();
    Message<T> dequeue();
};

} // namespace mrroot501

#endif
