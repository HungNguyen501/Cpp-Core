#ifndef _MRROOT501_HASH_TABLE_H_
#define _MRROOT501_HASH_TABLE_H_

namespace mrroot501 {

template<typename T>
class Mrroot501HashTable {
public:
    Mrroot501HashTable();
    Mrroot501HashTable(int space);
    void add(T value);
    void remove(T value);
    void removeRandom();
    void printHashTable();
};

} // namespace mrroot501

#endif // _MRROOT501_HASH_TABLE_H_
