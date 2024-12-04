#include "C:/Users/marle/PycharmProjects/DSA_Visualizer_frontend/Back-End Development/Header Files/array.h"
#include <iostream>
#ifndef STACK_H
#define STACK_H
#define MAX 1000000

class Stack {
    int top;
public:
    DynamicArray<int> a[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

#endif //STACK_H