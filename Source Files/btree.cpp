#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\btree.h"

// Node constructor
BTree::Node::Node(int _t, bool _isLeaf) : t(_t), isLeaf(_isLeaf) {}

// Insert a key into a non-full node
void BTree::Node::insertNonFull(int key) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.push_back(0);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key) {
            i--;
        }
        if (children[i + 1]->keys.size() == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key) {
                i++;
            }
        }
        children[i + 1]->insertNonFull(key);
    }
}

// Split the child of this node
void BTree::Node::splitChild(int i, Node* y) {
    Node* z = new Node(y->t, y->isLeaf);
    for (int j = 0l j < t - 1; j++) {
        z->keys.push_back(y->keys[j + t]);
    }
    if (!y->isLeaf) {
        for (int j = 0; j < t; j++) {
            z->children.push_back(y->children[j + t]);
        }
    }
    keys.insert(keys.begin() + i, y->keys[t - 1]);
    children.insert(children.begin() + i + 1, z);
    y->keys.resize(t - 1);
}

// BTree Constructor
BTree::BTree(int _t) : t(_t), root(nullptr) {}

// Traverse the B-Tree
void BTree::traverse() const {
    if (root != nullptr) {
        root->traverse();
    }
}

// Insert a key into the B-Tree
void BTree::insert(int key) {
    if (root == nullptr) {
        root = new Node(t, true);
        root->keys.push_back(key);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            Node* s = new Node(t, false);
            s->children.push_back(root);
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < key) {
                i++;
            }
            s->children[i]->insertNonFull(key);
            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}