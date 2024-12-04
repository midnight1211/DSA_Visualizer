#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\kd_tree.h"

// Constructor
KDTree::KDTree(int k) : root(nullptr), k(k) {}

// Insert a point into the K-D Tree
KDTree::Node* KDTree::insert(Node* node, const std::vector<int>& point, int depth) {
    if (node == nullptr) {
        return new Node(point);
    }


    int cd = depth % k;
    if (point[cd] < node->point[cd]) {
        node->left = insert(node->left, point, depth + 1);
    } else {
        node->right = insert(node->right, point, depth + 1);
    }
    return node;
}

// Public insert function
void KDTree::insert(const std::vector<int>& point) {
    root = insert(root, point, 0);
}

// Range search
void KDTree::rangeSearch(Node* node, const std::vector<int>& lower, const std::vector<int>& upper, int depth, std::vector<std::vector<int>>& result) const {
    if (node == nullptr) return;

    bool inside = true;
    for (int i = 0; i < k; i++) {
        if (node->point[i] < lower[i] || node->point[i] > upper[i]) {
            inside = false;
            break;
        }
    }

    if (inside) {
        result.push_back(node->point);
    }

    int cd = depth % k;
    if (lower[cd] < node->point[cd]) {
        rangeSearch(node->left, lower, upper, depth + 1, result);
    }
    if (upper[cd] > node->point[cd]) {
        rangeSearch(node->right, lower, upper, depth + 1, result);
    }
}

// Public range search function
std::vector<std::vector<int>> KDTree::rangeSearch(const std::vector<int>& lower, const std::vector<int>& upper) const {
    std::vector<std::vector<int>> result;
    rangeSearch(root, lower, upper, 0, result);
    return result;
}