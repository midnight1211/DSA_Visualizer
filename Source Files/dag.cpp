#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\dag.h"

// Add a vertex to the DAG
void DAG::addVertex(int vertex) {
    adjList[vertex];
}

// Add a directed edge to the DAG
void DAG::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
}

// Remove a directed edge from the DAG
void DAG::removeEdge(int src, int dest) {
    if (adjList.find(src) != adjList.end()) {
        adjList[src].remove(dest);
    }
}

// Remove a vertex from the DAG
void DAG::removeVertex(int vertex) {
    for (auto& pair : adjList) {
        pair.second.remove(vertex);
    }
    adjList.erase(vertex);
}