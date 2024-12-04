#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\heap.h"

void MaxHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

void MaxHeap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

int MaxHeap::extractMax() {
    if (heap.empty()) {
        throw std::out_of_range("Heap underflow");
    }
    int maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return maxValue;
}

void MaxHeap::heapifyDown(int index) {
    int size = heap.size();
    while (index < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

int MaxHeap::getMax() const {
    if (heap.empty()) {
        throw std::out_of_range("Heap is empty");
    }
    return heap[0];
}

bool MaxHeap::isEmpty() const {
    return heap.empty();
}

int MaxHeap::size() const {
    return heap.size();
}

void MaxHeap::clear() {
    heap.clear();
}

void MaxHeap::buildHeap(const std::vector<int>& elements) {
    heap = elements;
    for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

void MaxHeap::printHeao() const {
    for (int value : heap){
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void MinHepa::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

void MinHeap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

int MinHeap::extractMin() {
    if (heap.empty()) {
        throw std::out_of_range("Heap underflow");
    }
    int minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return minValue;
}

void MinHeap::heapifyDown(int index) {
    int size = heap.size();
    while (index < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

int MinHeap::getMin() const {
    if (heap.empty()) {
        throw std::out_of_range("Heap is empty");
    }
    return heap[0];
}

bool MinHeap::isEmpty() const {
    return heap.empty();
}

int MinHeap::size() const {
    return heap.size();
}

void MinHeap::clear() {
    heap.clear();
}

void MinHeap::buildHeap(const std::vector<int>& elements) {
    heap = elements;
    for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

void MinHeap::printHeap() const {
    for (int value : heap) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}