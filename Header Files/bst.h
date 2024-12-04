#ifndef BST_H
#define BST_H

#include <iostream>

template <typename T>
class BinarySearchTree {
    private:
        struct Node {
            T data;
            Node* left;
            Node* right;

            Node (const T& value) : data(value), left(nullptr), right(nullptr);
        };

        Node* root;

        void insert(Node*& node, const T& value);
        Node* search(Node* node, const T& value) const;
        void inorder(Node* node) const;
        void preorder(Node* node) const;
        void postorder(Node* node) const;
        Node* deleteNode(Node* node, const T& value);
        Node* minValueNode(Node* node) const;
        void clear(Node* node);
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(const T& value);
        bool search(const T& value) const;
        void inorder() const;
        void preorder() const;
        void postorder() const;
        void deleteNode(const T& value);
};

#endif