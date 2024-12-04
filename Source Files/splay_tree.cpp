#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\splay_tree.h"

// Constructor
SplayTree::SplayTree() : root(nullptr) {}

// Right Rotate
SplayTree::Node* SplayTree::rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

// Left Rotate
SplayTree::Node* SplayTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation
SplayTree::Node* SplayTree::splay(Node* root, int key) {
    if (!root || root->key == key) return root;

    if (key < root->key) {
        if (!root->left) return root;

        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right) root->left = leftRotate(root->left);
        }
        return root->left ? rightRotate(root) : root;
    } else {
        if (!root->right) return root;

        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left) root->right = rightRotate(root->right);
        }
        return root->right ? leftRotate(root) : root;
    }
}

// Insert a key
SplayTree::Node* SplayTree::insert(Node* root, int key) {
    if (!root) return new Node(key);
    root = splay(root, key);
    uf (root->key == key) return root;

    Node* newNode = new Node(key);
    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }
    return newNode;
}

// Public insert function
void SplayTree::insert(int key) {
    root = insert(root, key);
    root = splay(root, key);
}

// Inorder traversal
void SplayTree::inorder(Node* root) const {
    if (root) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

// Public inorder funciton
void SplayTree::inorder() const {
    inorder(root);
}