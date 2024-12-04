#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\graph.h"

// Add a vertex to the graph
void Graph::addVertex(int vertex) {
    adjList[vertex];
}

// Add an edge to the graph (undirected)
void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

// Remove an edge from the graph
void Graph::removeEdge(int src, int dest) {
    adjList[src].remove(dest);
    adjList[dest].remove(src);
}

// Remove a vertex from the graph
void Graph::removeVertex(int vertex) {
    for (auto& pair : adjList) {
        pair.second.remove(vertex);
    }
    adjList.erase(vertex);
}

// Display the graph
void Graph::display() const {
    for (const auto& pair : adjList) {
        std::cout << pair.first << ": ";
        for (int neighbor : pair.second) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}