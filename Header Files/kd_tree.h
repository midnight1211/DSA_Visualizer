#ifndef KD_TREE_H
#define KD_TREE_H

#include <iostream>
#include <vector>

class KDTree {
    private:
        struct Node {
            std::vector<int> point;
            Node* left;
            Node* right;

            Node(const std::vector<int>& point) : point(point), left(nullptr), right(nullptr) {}
        };

        Node* root;
        int k;

        Node* insert(Node* node, const std::vector<int>& point, int depth);
        void rangeSearch(Node* node, const std::vector<int>& lower, const std::vector<int>& upper, int depth, std::vector<std::vector<int>>& result) const;

    public:
        KDTree(int k);;
        void insert(const std::vector<int>& point);
        std::vector<std::vector<int>> rangeSearch(const std::vector<int>& lower, const std::vector<int>& upper) const;
};

#endif