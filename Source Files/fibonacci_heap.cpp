#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\fibonacci_heap.h"

// Constructor
FibonacciHeap::FibonacciHeap() : minNode(nullptr), numNodes(0) {}

// Destructor
FibonacciHeap::~FibonacciHeap() { default; }

// Link two nodes
void FibonacciHeap::link(Node* y, Node* x) {
    // Remove y from the root list
    y->prev->next = y->next;
    y->next->prev = y->prev;

    // Make y a child of x
    y->next = x->child;
    if (x->child != nullptr) {
        x->child->prev = y;
    }
    x->child = y;
    y->parent = x;
    x->degree++;
    y->marked = false;
}

// Insert a new node
void FibonacciHeap::insert(int key) {
    Node* newNode = new Node(key);
    if (minNode == nullptr) {
        minNode = newNode;
    } else {
        // Add newNode to the root list
        newNode->next = minNode;
        newNode->prev = minNode->prev;
        minNode->prev->next = newNode;
        minNode->prev = newNode;

        // Update minNode if necessary
        if (key < minNode->key) {
            minNode = newNode;
        }
    }
    numNodes++;
}

// Merge two Fibonacci heaps
void FibonacciHeap::merge(FibonacciHeap* other) {
    if (other->minNode == nullptr) return;

    // Merge the root lists
    Node* min1 = minNode;
    Node* min2 = other->minNode;

    min1->prev->next = min2;
    min2->prev->nect = min1;
    Node* temp = min1->prev;
    min1->prev = min2->prev;
    min2->prev = temp;

    // Update minNode
    if (min2->key < min1->key) {
        minNode = min2;
    }

    numNodes += other->numNodes;
    other->minNode = nullptr;
    other->numNodes = 0;
}

// Extract the minimum node
Node* FibonacciHeap::extractMin() {
    Node* z = minNode;
    if (z != nullptr) {
        // Add children of z to the root list
        if (z->child != nullptr) {
            Node* child = z->child;
            do {
                child->parent = nullptr;
                child = child->nextl
            } while (child != z->child);
        }

        // Remove z from the root list
        z->prev->next = z->next;
        z->next->prev = z->prev;

        if (z == z->next) {
            minNode = nullptr;
        } else {
            minNode = z->next;
            consolidate();
        }
        numNodes--;
    }
    return z;
}

// Consolidate the trees in the root list
void FibonacciHeap::consolidate() {
    int maxDegree = static_cast<int>(std::log(numNodes) / std::log(2)) + 1;
    std::vector<Node*> degreeTable(maxDegree, nullptr);

    Node* current = minNode;
    Node* end = minNode;

    do {
        Node* x = current;
        int d = x->degree;
        while (degreeTable[d] != nullptr) {
            Node* y = degreeTable[d];
            if (x->key > y->key) {
                std::swap(x, y);
            }
            link(y, x);
            degreeTable[d] = nullptr;
            d++;
        }
        degreeTable[d] = x;
        current = current->next;
    } while (current != end);

    minNode = nullptr;
    for (Node* node : degreeTable) {
        if (node != nullptr) {
            if (minNode == nullptr) {
                minNode = node;
            } else {
                // Add node to the root list
                node->next = minNode;
                node->prev = minNode->prev;
                minNode->prev->next = node;
                minNode->prev = node;

                // Update minNode if necessary
                if (node->key < minNode->key) {
                    minNode = node;
                }
            }
        }
    }
}

// Decrease the key of a node
void FibonacciHeap::decreaseKey(Node* x, int k) {
    if (k > x->key) {
        throw std::invalid_argument("New key is greater than current key");
    }
    x->key = k;
    Node* y = x->parent;
    if (x->key < minNode->key) {
        minNode = x;
    }
}

// Delete a node
void FibonacciHeap::deleteNode(Node* x) {
    decreaseKey(x, std::numeric_limits<int>::min());
    extractMin();
}

// Find the minimum node
Node* FibonacciHeap::findMin() const {
    return minNode;
}

// Check if the heap is empty
bool FibonacciHeap::isEmpty() const {
    return minNode == nullptr;
}

// Display the heap (for debugging)
void FibonacciHeap::display(Node* node, int level) const {
    if (node == nullptr) return;
    Node* current = node;
    do {
        std::cout << std::string(level, ' ') << current->key << std::endl;
        display(current->child, level + 1);
        current = current->next;
    } while (current != node);
}

void FibonacciHeap::display() const {
    display(minNode);
}