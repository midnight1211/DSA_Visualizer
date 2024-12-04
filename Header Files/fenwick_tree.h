#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <iostream>
#include <vector>

class FenwickTree {
    private:
        std::vector<int> tree;
        int n;

    public:
        FenwickTree(int size);
        void update(int index, int value);
        int query(int index) const;
        int rangeQuery(int left, int right) const;
};

#endif