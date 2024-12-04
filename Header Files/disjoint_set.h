#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <iostream>
#include <vector>

class DisjointSet {
    private:
        std::vector<int> parent;
        std::vector<int> rank;
        
    public:
        DisjointSet(int size);
        int find(int element);
        void unionSets(int set1, int set2);
};

#endif