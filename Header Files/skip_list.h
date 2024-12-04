#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class SkipList {
    private:
        struct Node {
            int value;
            std::vector<Node*> forward;

            Node(int value, int level) : value(value), forward(level +1, nullptr) {}
        };

        Node* header;
        int maxLevel;
        int currentLevel;
        float probability;

        int randomLevel();
    
    public:
        SkipList(int maxLevel, float probability);
        void insert(int value);
        bool search(int value) const;
        void remove(int value);
        void display() const;
};

#endif