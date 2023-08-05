#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value);
    ~BinaryTreeNode();
};

class BinaryTree {
private:
    BinaryTreeNode* root;

    void insertRecursive(BinaryTreeNode* node, int value);
    bool searchRecursive(const BinaryTreeNode* node, int value) const;

public:
    BinaryTree();
    ~BinaryTree();

    void insert(int value);
    bool search(int value) const;
};

#endif // BINARY_TREE_H
