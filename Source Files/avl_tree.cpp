#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\avl_tree.h"

// Constructor
AVLTree::AVLTree() : root(nullptr) {}

// Get height of the node
int AVLTree::height(Node* node) {
    return node ? node->height : 0;
}

// Get balance factor of the node
int AVLTree::getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right rotate
AVLTree::Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
AVLTree::Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return x;
}

// Insert a key
AVLTree::Node* AVLTree::insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicates are not allowed

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left left case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    
    // Right Right case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Delete a key
AVLTree::Node* AVLTree::deleteNode(Node* node, int key) {
    if (!node) return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else
        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp; // Copy the contents of the non-empty child
            }
            delete temp;
        } else {
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (!node) return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    
    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Pre-order traversal
void AVLTree::preOrder(Node* node) const {
    if (node) {
        std::cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Public insert function
void AVLTree::insert(int key) {
    root = insert(root, key);
}

// Public delete function
void AVLTree::deleteKey(int key) {
    root = deleteNode(root, key);
}

// Public pre-order function
void AVLTree::preOrder() const {
    preOrder(root);
}