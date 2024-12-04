#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>

class AVLTree {
    private:
        struct Node {
            int key;
            Node* left;
            Node* right;
            int height;

            Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
        };

        Node* root;

        int height(Node* node);
        int getBalance(Node* node);
        Node* rightRotate(Node* y);
        Node* leftRotate(Node* x);
        Node* insert(Node* node, int key);
        Node* minValueNode(Node* node);
        Node* deleteNode(Node* node, int key);
        void preOrder(Node* node) const;

    public:
        AVLTree();
        void insert(int key);
        void deleteKey(int key);
        void preOrder() const;
}