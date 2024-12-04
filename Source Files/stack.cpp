#include "C:/Users/marle/PycharmProjects/DSA_Visualizer_frontend/Back-End Development/Header Files/stack.h"
#include "C:/Users/marle/PycharmProjects/DSA_Visualizer_frontend/Back-End Development/Header Files/array.h"

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        std::cout << "Stack Overflow" << std::endl;
        return false;
    } else {
        a[++top] = x;
        std::cout << x << " pushed into stack" << std::endl;
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        std::cout << "Stack Underflow" << std::endl;
        return 0;
    } else {
        int x;
        x = a[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        std::cout << "Stack is Empty" << std::endl;
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::isFull() {
    return (top >= (MAX - 1));
}
