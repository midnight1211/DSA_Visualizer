#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\bst.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    clear(root);
}

template <typename T>
void BinarySearchTree<T>::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
    insert(root, value);
}

template <typename T>
void BinarySearchTree<T>::insert(Node*& node, const T& value) {
    if (node == nullptr) {
        node = new Node(value);        
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
}

template <typename T>
bool BinarySearchTree<T>::search(const T& value) const {
    return search(root, value) != nullptr;
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::search(Node* node, const T& value) const {
    if (node == nullptr || node->data == value) {
        return node;
    }
    if (value < node->data) {
        return search(node->left, value);
    }
    return search(node->right, value);
}

template <typename T>
void BinarySearchTree<T>::inorder() const {
    inorder(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::inorder(Node* node) const {
    if (node) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

template <typename T>
void BinarySearchTree<T>::preorder() const {
    preorder(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::preorder(Node* node) const {
    if (node) {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

template <typename T>
void BinarySearchTree<T>::postorder() const {
    postorder(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::postorder(Node* node) const {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}

template <typename T>
void BinarySearchTree<T>::deleteNode(const T& value) {
    if (node == nullptr) {
        return node;
    }
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::deleteNode(Node* node, const T& value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::minValueNode(Node* node) const {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}