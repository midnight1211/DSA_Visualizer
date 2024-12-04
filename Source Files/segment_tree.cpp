#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\segment_tree.h"

// Build the segment tree
void SegmentTree::buildTree(const std::vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(arr, 2 * node + 1, start, mid);
        buildTree(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Sum of the two children
    }
}

// Query the segment tree
int SegmentTree::query(int node, int start, int end, int l, int r) const {
    if (r < start || end < l) {
        return 0; // Out of range
    }
    if (l <= start && end <= r) {
        return tree[node]; // Current segment is fully within range
    }
    int mid = (start + end) / 2;
    int leftSum = query(2 * node + 1, start, mid, l, r);
    int rightSum = query(2 * node + 2, mid + 1, end, l, r);
    return leftSum + rightSum; // Sum of both children
}

// Constructor
SegmentTree::SegmentTree(const std::vector<int>& arr) : n(arr.size()) {
    tree.resize(4 * n); // Allocate memory for the segment tree
    buildTree(arr, 0, 0, n - 1);
}

// Public quert function
int SegmentTree::query(int l, int r) const {
    return query(0, 0, n - 1, l, r);
}