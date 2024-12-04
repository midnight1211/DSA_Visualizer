#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <iostream>

class SplayTree {
    private:
        struct Node {
            int key;
            Node* left;
            Node* right;

            Node(int value) : key(value), left(nullptr), right(nullptr) {}
        };

        Node* root;

        Node* rightRotate(Node* y);
        Node* leftRotate(Node* x);
        Node* splay(Node* root, int key);
        Node* insert(Node* root, int key);
        void inorder(Node* root) const;

    public:
        SplayTree();
        void insert(int key);
        void inorder() const;
}

#endif