#ifndef FIBONACCI_HEAP_H
#define FIBONACCI_HEAP_H

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

struct Node {
    int key;
    int degree;
    bool marked;
    Node* parent;
    Node* child;
    Node* next;
    Node* prev;

    Node(int k) : key(k), degree(0), marked(false), parent(nullptr), child(nullptr), next(this), prev(this)
};

class FibonacciHeap {
    private:
        Node* minNode;
        int numNodes;

        void link(Node* y, Node* x);
        void consolidate();

    public:
        FibonacciHeap();
        ~FibonacciHeap();

        void insert(int key);
        void merge(FibonacciHeap* other);
        Node* extractMin();
        void decreaseKey(Node* x, int k);
        void deleteNode(Node* x);
        Node* findMin() const;
        bool isEmpty() const;
        void display(Node* node, int level = 0) const;
        void display() const;
};

#endif