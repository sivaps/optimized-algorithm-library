#include "binary_tree.h"

// Constructor for Binary Tree Node
BinaryTreeNode::BinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}

// Destructor for Binary Tree Node (recursive)
BinaryTreeNode::~BinaryTreeNode() {
    delete left;
    delete right;
}

// Constructor for Binary Tree
BinaryTree::BinaryTree() : root(nullptr) {}

// Destructor for Binary Tree
BinaryTree::~BinaryTree() {
    delete root;
}

// Function to insert a value into the Binary Tree
void BinaryTree::insert(int value) {
    if (root == nullptr) {
        root = new BinaryTreeNode(value);
    } else {
        insertRecursive(root, value);
    }
}

// Recursive function to insert a value into the Binary Tree
void BinaryTree::insertRecursive(BinaryTreeNode* node, int value) {
    if (value < node->data) {
        if (node->left == nullptr) {
            node->left = new BinaryTreeNode(value);
        } else {
            insertRecursive(node->left, value);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new BinaryTreeNode(value);
        } else {
            insertRecursive(node->right, value);
        }
    }
}

// Function to search for a value in the Binary Tree
bool BinaryTree::search(int value) const {
    return searchRecursive(root, value);
}

// Recursive function to search for a value in the Binary Tree
bool BinaryTree::searchRecursive(const BinaryTreeNode* node, int value) const {
    if (node == nullptr) {
        return false;
    }

    if (value == node->data) {
        return true;
    } else if (value < node->data) {
        return searchRecursive(node->left, value);
    } else {
        return searchRecursive(node->right, value);
    }
}
