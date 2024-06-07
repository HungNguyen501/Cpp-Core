#ifndef _LL_NODE_H_
#define _LL_NODE_H_

namespace mrroot501 {

template<typename T>
class LLNode {
public:
    T data;
    LLNode *next;
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

} // namespace mrroot501

#endif
