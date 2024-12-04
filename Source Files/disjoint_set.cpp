#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\disjoint_set.h"

// Constructor
DisjointSet::DisjointSet(int size) : parent(size), rank(size, 0) {
    for (int i = 0; i < size; i++) {
        parent[i] = i;
    }
}

// Find the root of the set
int DisjointSet::find(int element) {
    if (parent[element] != element) {
        parent[element] = find(parent[element]);
    }
    return parent[element];
}

// Union two sets
void DisjointSet::unionSets(int set1, int set2) {
    int root1 = find(set1);
    int root2 = find(set2);

    if (root1 != root2) {
        if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}