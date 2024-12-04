#include "C:/Users/marle/PycharmProjects/DSA_Visualizer_frontend/Back-End Development/Header Files/array.h"
#include <vector>
#include <string>
#ifndef TRIE_H
#define TRIE_H

class TrieNode {
    bool isEndOfWord;
    DynamicArray<TrieNode*> children[26];

    TrieNode();
};

class Trie {
    private:
        TrieNode* root;
        TrieNode* deleteHelper(TrieNode* node, const std::string& word, int depth);
        bool isEmpty(TrieNode* node);
        void lexicographicTraversalHelper(TrieNode* node, std::string prefix, std::vector<std::string>& result);
        void compressNode(TrieNode* node);
        bool patternMatchHelper(TrieNode* node, const std::string& pattern, int depth);
    public:
        Trie() {
            root = new TrieNode();
        }
        void insert(const std::string& word);
        bool search(const std::string& word);
        bool startsWith(const std::string& prefix);
        void deleteWord(const std::string& word);
        std::vector<std::string> getAllWordsLexicographic();
        void compress();
        bool patternMatch(const std::string& pattern);
        std::string findLongestPrefix(const std::string& word);
};

#endif