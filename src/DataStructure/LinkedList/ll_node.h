#ifndef _LL_NODE_H_
#define _LL_NODE_H_

namespace mrroot501 {

template<typename T>
class LLNode {
public:
    LLNode();
    LLNode(T d);
};

template<typename T>
class DLLNode {
public:
    T data;
    DLLNode *next, *prev;
    DLLNode();
    DLLNode(T d);
};

template<typename T>
class SLLNode {
public:
    T data;
    SLLNode *next;
    SLLNode();
    SLLNode(T d);
};

} // namespace mrroot501

#endif
