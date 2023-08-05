#include "hash_table.h"
#include <iostream>

int main() {
    HashTable hashTable;
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 30);

    int value;
    if (hashTable.get(2, value)) {
        std::cout << "Value for key 2: " << value << std::endl;
    } else {
        std::cout << "Key 2 not found in the Hash Table." << std::endl;
    }

    hashTable.remove(2);

    if (hashTable.get(2, value)) {
        std::cout << "Value for key 2: " << value << std::endl;
    } else {
        std::cout << "Key 2 not found in the Hash Table." << std::endl;
    }

    std::cout << "Size of the Hash Table: " << hashTable.getSize() << std::endl;

    return 0;
}
