#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>

class Graph {
    private:
        std::unordered_map<int, std::list<int>> adjList;

    public:
        void addVertex(int vertex);
        void addEdge(int src, int dest);
        void removeEdge(int src, int dest);
        void removeVertex(int vertex);
        void display() const;
}

#endif