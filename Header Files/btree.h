#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>

class BTree {
    private:
        struct Node {
            std::vector<int> keys;
            std::vector<Node*> children;
            bool isLeaf;
            int t; // Minimum degree

            Node(int _t, bool _isLeaf);
            void insertNonFull(int key);
            void splitChild(int i, Node* y);
        };

        Node* root;
        int t; // Minimum degree

    public:
        BTree(int _t);
        void traverse() const;
        void insert(int key);
};

#endif