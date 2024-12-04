#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <iostream>
#include <vector>

class SegmentTree {
    private:
        std::vector<int> tree;
        int n;

        void buildTree(const std::vector<int>& arr, int node, int start, int end);
        int query(int node, int start, int end, int l, int r) const;

    public:
        SegmentTree(const std::vector<int>& arr);
        int query(int l, int r) const;
}

#endif