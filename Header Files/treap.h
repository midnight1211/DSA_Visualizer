#ifndef TREAP_H
#define TREAP_H

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Treap {
    private:
        struct Node {
            T key;
            int priority;
            Node* left;
            Node* right;

            Node(T k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
        };

        Node* root;

        Node* rotateRight(Node* node);
        Node* rotateLeft(Node* node);
        Node* insert(Node* node, T key);
        Node* deleteNode(Node* node, T key);
        Node* search(Node* node);
        void inorder(Node* node);
        void clear(Node* node);
        Node* split(Node* node, T key);
        Node* merge(Node* left, Node* right);

    public:
        Treap();
        ~Treap();

        void insert(T key);
        void deleteKey(T key);
        Node* search(T key);
        void inorder();
        void clear();
        void split(T key);
        void merge(T key);
};

#endif