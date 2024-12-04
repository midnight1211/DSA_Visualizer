#include "C:/Users/marle/PycharmProjects/DSA_Visualizer_frontend/Back-End Development/Header Files/queue.h"

Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Underflow error" << std::endl;
        exit(EXIT_FAILURE);
    }

    int x = arr[front];
    std::cout << "Removing " << x << std::endl;

    front = (front + 1) % capacity;
    return x;
}

void Queue::enqueue(int x) {
    if (isFull()) {
        std::cout << "Overflow error" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Inserting " << x << std::endl;

    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
}

int Queue::peek() {
    if (isEmpty()) {
        std::cout << "Underflow error" << std::endl;
        exit(EXIT_FAILURE);
    }

    return arr[front];
}

int Queue::size() {
    return count;
}

bool Queue::isEmpty() {
    return (size() == 0);
}

bool Queue::isFull() {
    return (size() == capacity);
}