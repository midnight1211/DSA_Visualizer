#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\fenwick_tree.h"

// Constructor
FenwickTree::FenwickTree(int size) : n(size) {
    tree.resize(size + 1, 0);
}

// Update the fenwick tree
void FenwickTree::update(int index, int value) {
    for (; index <= n; index += index & -index) {
        tree[index] += value;
    }
}

// Query the value
int FenwickTree::query(int index) const {
    int sum = 0;
    for (; index > 0; index -= index & -index) {
        sum += tree[index];
    }
    return sum;
}

// Range Query
int FenwickTree::rangeQuery(int left, int right) const tg u6j73     return query(right) - query(left - 1);
tg u6j73 