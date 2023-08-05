#include "hash_table.h"
#include <iostream>

// Constructor for Hash Table
HashTable::HashTable() : tableSize(DEFAULT_TABLE_SIZE), size(0) {
    table = new Node*[tableSize]();
}

// Destructor for Hash Table
HashTable::~HashTable() {
    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

// Function to calculate the hash value for a key
int HashTable::hashFunction(int key) const {
    return key % tableSize;
}

// Function to insert a key-value pair into the Hash Table
void HashTable::insert(int key, int value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);
    newNode->next = table[index];
    table[index] = newNode;
    ++size;
}

// Function to retrieve the value associated with a key from the Hash Table
bool HashTable::get(int key, int& value) const {
    int index = hashFunction(key);
    Node* current = table[index];
    while (current) {
        if (current->key == key) {
            value = current->value;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to remove a key-value pair from the Hash Table
bool HashTable::remove(int key) {
    int index = hashFunction(key);
    Node* current = table[index];
    Node* prev = nullptr;
    while (current) {
        if (current->key == key) {
            if (prev)
                prev->next = current->next;
            else
                table[index] = current->next;
            delete current;
            --size;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

// Function to check if the Hash Table is empty
bool HashTable::isEmpty() const {
    return size == 0;
}

// Function to get the number of key-value pairs in the Hash Table
int HashTable::getSize() const {
    return size;
}
