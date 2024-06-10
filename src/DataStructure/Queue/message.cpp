#include <iostream>

namespace mrroot501 {

template <class T>
class Header {
public:
    long timestamp;
    unsigned int index;
    Header() {
        this->timestamp = time(0);
        this->index = 0;
    }
    Header(unsigned int index) {
        this->timestamp = time(0);
        this->index = index;
    }
    Header(unsigned int index, long timestamp) {
        this->timestamp = timestamp;
        this->index = index;
    }
};

template <class T>
class Message {
public:
    Header<T> header;
    unsigned int byte_size;
    std::string payload;
    Message() {
        this->header = Header<T>();
        this->payload = "";
        this->byte_size = 0;
    };
    Message(Header<T> header, std::string payload) {
        this->header = header;
        this->payload = payload;
        this->byte_size = payload.length();
    }
    bool isNull() {
        return (this->payload == "");
    }
};

template class Header<int>;
template class Message<int>;

} // namespace mrroot501