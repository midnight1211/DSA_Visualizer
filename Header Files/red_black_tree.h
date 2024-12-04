#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>

class RedBlackTree {
    private:
        struct Node {
            int data;
            bool color; // 0 for Red, 1 for black
            Node *left, *right, *parent;

            Node(int data) : data(data), color(0), left(nullptr), right(nullptr), parent(nullptr) {}
        };

        Node* root;

        void rotateLeft(Node* &node);
        void rotateRight(Node* &node);
        void fixViolation(Node* &node);
        void inorderHelper(Node* node) const;

    public:
        RedBlackTree();
        void insert(int data);
        void inorder() const;
};

#endif