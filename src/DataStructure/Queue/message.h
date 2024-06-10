#ifndef _MRROOT501_MESSAGE_H_
#define _MRROOT501_MESSAGE_H_

namespace mrroot501 {

template <class T>
class Header {
public:
    long timestamp;
    unsigned int index;
    Header();
    Header(unsigned int index);
    Header(unsigned int index, long timestamp);
};

template <class T>
class Message {
public:
    Header<T> header;
    int byte_size;
    std::string payload;
    Message();
    Message(Header<T> header, std::string payload);
    bool isNull();
};

} // namespace mrroot501

#endif