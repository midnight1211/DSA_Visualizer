#ifndef SPARSE_TABLE_H
#define SPARSE_TABLE_H

#include <iostream>
#include <vector>
#include <cmath>

class SparseTable {
    private:
        std::vector<std::vector<int>> table;
        std::vector<int> log;

    public:
        SparseTable(const std::vector<int>& arr);
        int query(int L, int R) const;
};

#endif