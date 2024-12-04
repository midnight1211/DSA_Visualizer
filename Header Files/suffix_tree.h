#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class SuffixTree {
    private:
        struct Node{
            std::unordered_map<char, Node*> children;
            int start;
            int* end;
            int suffixIndex;

            Node(int start, int* end) : start(start), end(end), suffixIndex(-1) {}
        };

        Node* root;
        std::string text;

        void buildSuffixTree();
        void insertSuffix(int start);
        void freeTree(Node* node);
    
    public:
        SuffixTree(const std::string text);
        ~SuffixTree();

        void display(Node* node, int level = 0) const;
        Node* getRoot() const { return root; }
        bool search(const std::string& pattern) const;
        int countOccurrences(const std::string& pattern) const;
        void findAllOccurrences(const std::string& pattern, std::vector<int>& occurrences) const;
        std::string serialize() const;
        void deserialize(const std::string& data);
};

#endif