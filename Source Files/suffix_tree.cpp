#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\suffix_tree.h"

// Constructor
SuffixTree::SuffixTree(const std::string& text) : text(text) {
    root = new Node(-1, new int(-1));
    buildSuffixTree();
}

// Destructor
SuffixTree::~SuffixTree() {
    freeTree(root);
}

// Free the tree
void SuffixTree::freeTree(Node* node) {
    for (auto& child : node->children) {
        freeTree(child.second);
    }
    delete node->end;
    delete node;
}

// Build the suffix tree
void SuffixTree::buildSuffixTree() {
    for (int i = 0; i < text.length(); i++) {
        insertSuffix(i);
    }
}

// Insert a suffix into the tree
void SuffixTree::insertSuffix(int start) {
    Node* currentNode = root;
    for (int i = start; i < text.length(); i++) {
        char currentChar = text[i];
        if (currentNode->children.find(currentChar) == currentNode->children.end()) {
            Node* newNode = new Node(i, new int(text.length()));
            currentNode->children[currentChar] = newNode;
            return;
        }
        currentNode = currentNode->children[currentChar];
    }
}

// Display the suffix tree
void SuffixTree::display(Node* node, int level) const {
    for (auto& child : node->children) {
        for (int i = 0; i < level; i++) std::cout << " ";
        std::cout << child.first << " -> ";
        std::cout << text.substr(child.second->start, *(child.second->end) - child.second->start) << std::endl;
        display(child.second, level + 1);
    }
}

bool SuffixTree::search(const std::string& pattern) const {
    Node* currentNode = root;
    int index = 0;

    while (index < pattern.length()) {
        char currentChar = pattern[index];
        if (currentNode->children.find(currentChar) == currentNode->children.end()) {
            return false; // Not found
        }
        currentNode = currentNode->children[currentChar];
        int edgeLength = *(currentNode->end) - currentNode->start;

        // Check if the pattern matches the edge
        for (int i = 0; i < edgeLength && index < pattern.length(); i++, index++) {
            if (text[currentNode->start + i] != pattern[index]) {
                return false; // Not found
            }
        }
    }
    return true; // Found
}

int SuffixTree::countOccurrences(const std::string& pattern) const {
    int count = 0;
    // Implement a search function that counts occurrences
    // This can be done by traversing the tree and counting leaf nodes
    // that correspond to the pattern.
    return count;
}

void SuffixTree::findAllOccurrences(const std::string& pattern, std::vector<int>& occurrences) const {
    Node* currentNode = root;
    int index = 0;

    // Traverse the tree to find the pattern
    // If found, traverse to collect all suffix indices
}

// Serialize the suffix tree to a string
std::string SuffixTree::serialize() const {
    std::ostringstream oss;
    std::function<void(Node*)> serializeNode = [&](Node* node) {
        if (!node) return;
        oss << node->start << " " << *(node->end) << " " << node->suffixIndex << " " << node->children.size() << " ";
        for (const auto& child : node->children) {
            serializeNode(child.second);
        }
    };
    serializeNode(root);
    return oss.str();
}

// Deserialize a suffix tree from a string
void SuffixTree::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::function<Node*(void)> deserializeNode = [&]() {
        int start, end, suffixIndex, numChildren;
        if (!(iss >> start>> end >> suffixIndex >> numChildren)) return nullptr;

        Node* node = new Node(start, new int(end));
        node->suffixIndex = suddixIndex;

        for (int i = 0; i < numChildren; ++i) {
            char childChar;
            iss >> childChar;
            node->children[childChar] = deserializeNode();
        }
        return node;
    };
    root = deserializeNode();
}