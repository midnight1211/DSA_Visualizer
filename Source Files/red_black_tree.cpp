#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\red_black_tree.h"

// Constructor
RedBlackTree::RedBlackTree() : root(nullptr) {}

// Left rotate
void RedBlackTree::rotateLeft(Node* &node) {
    Node* nodeRight = node->right;
    node->right = nodeRight->left;

    if (node->right != nullptr)
        node->right->parent = node;

    nodeRight->parent = node->parent;

    if (node->parent == nullptr) 
        root = nodeRight;
    else if (node == node->parent->left)
        node->parent->left = nodeRight;
    else
        node->parent->right = nodeRight;

    nodeRight->left = node;
    node->parent = nodeRight;
}

// Right Rotate
void RedBlackTree::rotateRight(Node* &node) {
    Node* nodeLeft = node->left;
    node->left = nodeLeft->right;

    if (node->left != nullptr)
        node->left->parent = node;

    nodeLeft->parent = node->parent;

    if (node->parent == nullptr)
        root = nodeLeft;
    else if (node == node->parent->left)
        node->parent->left = nodeLeft;
    else
        node->parent->right = nodeLeft;

    nodeLeft->right = node;
    node->parent = nodeLeft;
}

// Fix violations after insertion
void RedBlackTree::fixViolation(Node* &node) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;

    while ((node != root) && (node->color == 0) && (node->parent->color == 0)) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            if (uncle != nullptr && uncle->color == 0) {
                grandparent->color = 0;
                parent->color = 1;
                uncle->color = 1;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateRight(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            Node* uncle = grandparent->left;

            if (uncle != nullptr && uncle->color == 0) {
                grandparent->color = 0;
                parent->color = 1;
                uncle->color = 1;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateLeft(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = 1; // Ensure root is black
}

// Insert a new node
void RedBlackTree::insert(int data) {
    Node* node = new Node(data);
    if (root == nullptr) {
        node->color = 1;
        root = node;
    } else {
        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr) {
            parent = current;
            if (node->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        node->parent = parent;
        if (node->data < parent->data)
            parent->left = node;
        else
            parent->right = node;

        fixViolation(node);
    }
}

// Inorder traversal
void RedBlackTree::inorderHelper(Node* node) const {
    if (node == nullptr) return;
    inorderHelper(node->left);
    std::cout << node->data << " ";
    inorderHelper(node->right);
}

// Public inorder function
void RedBlackTree::inorder() const {
    inorderHelper(root);
} 