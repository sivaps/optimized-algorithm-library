#include "linked_list.h"
#include <iostream>

// Constructor for LinkedList Node
LinkedListNode::LinkedListNode(int value) : data(value), next(nullptr) {}

// Constructor for Singly Linked List
LinkedList::LinkedList() : head(nullptr), size(0) {}

// Destructor for Singly Linked List
LinkedList::~LinkedList() {
    while (head) {
        LinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to add a node to the end of the linked list
void LinkedList::append(int value) {
    LinkedListNode* newNode = new LinkedListNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        LinkedListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}

// Function to insert a node at the beginning of the linked list
void LinkedList::prepend(int value) {
    LinkedListNode* newNode = new LinkedListNode(value);
    newNode->next = head;
    head = newNode;
    ++size;
}

// Function to remove the first occurrence of a value from the linked list
bool LinkedList::remove(int value) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == value) {
        LinkedListNode* temp = head;
        head = head->next;
        delete temp;
        --size;
        return true;
    }

    LinkedListNode* current = head;
    while (current->next) {
        if (current->next->data == value) {
            LinkedListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            --size;
            return true;
        }
        current = current->next;
    }

    return false;
}

// Function to search for a value in the linked list
bool LinkedList::search(int value) const {
    LinkedListNode* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to check if the linked list is empty
bool LinkedList::isEmpty() const {
    return size == 0;
}

// Function to get the number of nodes in the linked list
int LinkedList::getSize() const {
    return size;
}
