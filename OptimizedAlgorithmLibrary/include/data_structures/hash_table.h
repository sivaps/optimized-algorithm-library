#ifndef HASH_TABLE_H
#define HASH_TABLE_H

class HashTable {
private:
    struct Node {
        int key;
        int value;
        Node* next;

        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    static const int DEFAULT_TABLE_SIZE = 10;

    Node** table;
    int tableSize;
    int size;

    int hashFunction(int key) const;

public:
    HashTable();
    ~HashTable();

    void insert(int key, int value);
    bool get(int key, int& value) const;
    bool remove(int key);

    bool isEmpty() const;
    int getSize() const;
};

#endif // HASH_TABLE_H
