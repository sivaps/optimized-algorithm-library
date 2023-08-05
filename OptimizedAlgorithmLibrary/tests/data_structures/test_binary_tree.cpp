#include "binary_tree.h"
#include <iostream>

int main() {
    BinaryTree binaryTree;
    binaryTree.insert(10);
    binaryTree.insert(5);
    binaryTree.insert(15);
    binaryTree.insert(2);
    binaryTree.insert(7);

    std::cout << "Searching for 5: " << (binaryTree.search(5) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 8: " << (binaryTree.search(8) ? "Found" : "Not Found") << std::endl;

    return 0;
}
