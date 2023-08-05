#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedListNode {
public:
    int data;
    LinkedListNode* next;

    LinkedListNode(int value);
};

class LinkedList {
private:
    LinkedListNode* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void append(int value);
    void prepend(int value);
    bool remove(int value);
    bool search(int value) const;

    bool isEmpty() const;
    int getSize() const;
};

#endif // LINKED_LIST_H
