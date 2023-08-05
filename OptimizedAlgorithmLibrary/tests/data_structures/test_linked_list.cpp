#include "linked_list.h"
#include <iostream>

int main() {
    LinkedList linkedList;
    linkedList.append(10);
    linkedList.append(20);
    linkedList.append(30);
    linkedList.prepend(5);
    linkedList.remove(20);

    std::cout << "Searching for 10: " << (linkedList.search(10) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 20: " << (linkedList.search(20) ? "Found" : "Not Found") << std::endl;

    std::cout << "Size of the Linked List: " << linkedList.getSize() << std::endl;

    return 0;
}
