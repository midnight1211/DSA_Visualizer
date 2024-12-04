#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\skip_list.h"

// Constructor
SkipList::SkipList(int maxLevel, float probability) : maxLevel(maxLevel), probability(probability), currentLevel(0) {
    header = new Node(-1, maxLevel);
    std::srand(std::time(nullptr));
}

// Generate a random level
int SkipList::randomLevel() {
    int level = 0;
    while (static_cast<float>(std::rand()) / RAND_MAX < probability && level < maxLevel) {
        level++;
    }
    return level;
}

// Insert a value
void SkipList::insert(int value) {
    std::vector<Node*> update(maxLevel + 1);
    Node* current = header;

    for (int i = currentLevel; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->value != value) {
        int newLevel = randomLevel();
        if (newLevel > currentLevel) {
            for (int i = currentLevel + 1; i <= newLevel; i++) {
                update[i] = header;
            }
            currentLevel = newLevel;
        }

        Node* newNode = new Node(value, newLevel);
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

// Search for a value
bool SkipList::search(int value) const {
    Node* current = header;
    for (int i = currentLevel; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    return current != nullptr && current->value == value;
}

// Remove a value
void SkipList::remove(int value) {
    std::vector<Node*> update(maxLevel + 1);
    Node* current = header;

    for (int i = currentLevel; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current != nullptr && current->value == value) {
        for (int i = 0; i <= currentLevel; i++) {
            if (update[i]->forward[i] != current) break;
            update[i]->forward[i] = current->forward[i];
        }

        delete current;

        while (currentLevel > 0 && header->forward[currentLevel] == nullptr) {
            currentLevel--;
        }
    }
}

// Display the skip list
void SkipList::display() const {
    for (int i = currentLevel; i >= 0; i--) {
        Node* current = header->forward[i];
        std::cout << "Level " << i << ": ";
        while (current != nullptr) {
            std:: cout << current->value << " ";
            current = current->forward[i];
        }
        std::cout << std::endl;
    }
}