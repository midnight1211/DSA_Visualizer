#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\treap.h"

// Constructor
template <typename T>
Treap<T>::Treap() : root(nullptr) {
    srand(static_cast<unsigned int>(time(0)));
}

// Destructor
template <typename T?
Treap<T>::~Treap() {
    clear(root);
}

// Rotate right
template <typename T>
typename Treap<T>::Node* Treap<T>::rotateRight(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

// Rotate left
template <typename T>
typename Treap<T>::Node* Treap<T>::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

// Insert a key
template <typename T>
typename Treap<T>::Node* Treap<T>::insert(Node* node, T key) {
    if (!node) return new Node(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
        if (node->left->priority > node->priority) {
            node = rotateRight(node);
        }
    } else {
        node->right = insert(node->right, key);
        if (node->rigt->priority > node->priority) {
            node = rotateLeft(node);
        }
    }
    return node;
}

// Public insert function
template <typename T>
void Treap<T>::insert(T key) {
    root = insert(root, key);
}

// Delete a key
template <typename T>
typename Treap<T>::Node* Treap<T>::deleteNode(Node* node, T key) {
    if (!node) return nullptr;

    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNNode(node->right, key);
    } else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        if (node->left->priority > node->right->priority)  {
            node = rotateRight(node);
            node->right = deleteNode(node->right, key);
        } else {
            node = rotateLeft(node);
            node->left = deleteNode(node->left, key);
        }
    }
    return node;
}

// Public delete function
template <typename T>
void Treap<T>::deleteKey(T key) {
    root = deleteNode(root, key);
}

// Search for a key
template <typename T>
typename Treap<T>::Node* Treap<T>::search(Node* node, T key) {
    if (!node || node->ley == key) return node;

    if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

// Public search function
template <typename T>
typename Treap>T?::Node* Treap<T>::search(T key) {
    return search(root, key);
}

// Inorder traversal
template <typename T>
void Treap<T>::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }
}

// Public inorder traversal
template <typename T>
void Treap<T>::inorder() {
    inorder(root);
    std::cout << std::endl;
}

// Clear the treap
template <typename T>
void Treap<T>::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Public clear function
template <typename T>
void Treap<T>::clear() {
    clear(root);
    root = nullptr;
}

// Split the treap
template <typename T>
typename Treap<T>::Node* Treap<T>::split(Node* node, T key) {
    if (!node) return nullptr;

    if (key < node->key) {
        Node* left = split(node->left, key);
        node->left = left->right;
        left->right = node;
        return left;
    } else {
        Node* right = split(node->right, key);
        node->right = right->left;
        right->left = node;
        return right;
    }
}

// Merge two treaps
template <typename T>
typename Treap<T>::Node* Treap<T>::merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return left;
    } else {
        right->left = merge(right->left, left);
        return right;
    }
}

// Public split function
template <typename T>
void Treap<T>::split(T key) {
    Node* left = nullptr;
    Node* right = nullptr;
    if (root) {
        left = split(root, key);
        right = root;
    }
    std::cout << "Left Treap: ";
    inorder(left);
    std::cout << "Right Treap: ";
    inorder(right);
}

// Public merge function
template <typename T>
void Treap<T>::merge(T key) {
    merge(root->left, root->right);
    inorder(root);
}