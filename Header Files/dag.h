#ifndef DAG_H
#define DAG_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

class DAG {
    private:
        std::unordered_map<int, std::list<int>> adjList;

    public:
        void addVertex(int vertex);
        void addEdge(int src, int dest);
        void removeEdge(int src, int dest);
        void removeVertex(int vertex);
};

#endif