#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\sparse_table.h"

// Constructor
SparseTable::SparseTable(const std::vector<int>& arr) {
    int n = arr.size();
    int maxLog = std::log2(n) + 1;
    table.resize(maxLog, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        table[0][i] = arr[i];
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            table[j][i] = std::min(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
        }
    }
}

// Query the minimum in the range [L, R]
int SparseTable::query(int L, int R) const {
    int j = std::log2(R - L + 1);
    return std::min(table[j][L], table[j][R - (1 << j) + 1]);
}