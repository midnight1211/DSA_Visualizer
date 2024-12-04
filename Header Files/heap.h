#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
    private:
        std::vector<int> heap;

        void heapifyUp(int index);
        void heapifyDown(int index);

    public:
        void insert(int value);
        int extractMin();
        int top() const;
        bool isEmpty() const;
        int size() const;
        void clear();
        void buildHeap(const std::vector<int>& elements);
        void printHeap() const;
};

class MaxHeap {
    private:
        std::vector<int> heap;

        void heapifyUp(int index);
        void heapifyDown(int index);
    public:
        void insert(int value);
        int extractMax();
        int top() const;
        bool isEmpty() const;
        int size() const;
        void clear();
        void buildHeap(const std::vector<int>& elements);
        void printHeap() const;
}