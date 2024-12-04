#include "C:/Users/marle/PycharmProjects/DSA_Visualizer_frontend/Back-End Development/Header Files/trie.h"
TrieNode::TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        children[i] = DynamicArray<TrieNode*>();
    }
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;

    for (char c : word) {
        int index = c - 'a';
        if (!current->children[index].isPresent(index)) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* current = root;

    for (char c : word) {
        int index = c - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current->isEndOfWord;
}

bool Trie::startsWith(const std::string& prefix) {
    TrieNode* current = root;

    for (char c : prefix) {
        int index = c - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return true;
}

TrieNode* Trie::deleteHelper(TrieNode* node, const std::string& word, int depth) {
    if (!node) return nullptr;

    if (depth == word.length()) {
        node->isEndOfWord = false;

        if (isEmpty(node)) {
            delete node;
            node = nullptr;
        }
        return node;
    }

    int index = word[depth] - 'a';
    node->children[index] = deleteHelper(node->children[index], word, depth+1);
    if (isEmpty(node) && !node->isEndOfWord) {
        delete node;
        node = nullptr;
    }
    return node;
}

bool Trie::isEmpty(TrieNode* node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i])
            return false;
    }
    return true;
}

void Trie::lexicographicTraversalHelper(TrieNode* node, string prefix, std::vector<std::string>& result) {
    if (node->isEndOfWord) {
        result.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            lexicographicTraversalHelper(node->children[i], prefix + char(i + 'a'), result);
        }
    }
}

void Trie::deleteWord(const std::string& word) {
    deleteHelper(root, word, 0);
}

std::vector<std::string> Trie::getAllWordsLexicographic() {
    std::vector<std::string> result;
    lexicographicTraversalHelper(root, "", result);\
    return result;
}

void Trie::compress() {
    compressNode(root);
}

bool Trie::patternMatch(const std::string& pattern) {
    return patternMatchHelper(root, pattern, 0);
}

std::string findingLongestPrefix(const std::string& word) {
    TrieNode* current = root;
    std::string prefix = "";
    std::string longestValidPrefix = "";

    for (char c : word) {
        int index = c - 'a';
        if (!current->children[index]) {
            break;
        }

        prefix += c;
        current = current->children[index];
        if (current->isEndOfWord) {
            longestValidPrefix = prefix;
        }
    }
    
    return longestValidPrefix;
}

void Trie::compressNode(TrieNode* node) {
    if (!node)
        return;

    int childCount = 0;
    int lastChild = -1;
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            childCount++;
            lastChild = i;
        }
    }

    if (childCount == 1 && !node->isEndOfWord) {
        TrieNode* child = node->children[lstChild];
        node->isEndOfWord = child->isEndOfWord;
        for (int i = 0; i < 26; i++) {
            node->children[i] = child->children[i];
        }
        delete child;
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            compressNode(node->children[i]);
        }
    }
}

bool Trie::patternHelper(TrieNode* node, const std::string& pattern, int depth) {
    if (!node)
        return false;
    if (depth == pattern.length())
        return node->isEndOfWord;

    if (pattern[depth] == '.') {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] && patternHelper(node->children[i], patteern, depth + 1)) {
                return true;
            }
        }
        return false;
    } else {
        int index = pattern[depth] - 'a';
        return node->children[index] && patternMatchHelper(node->children[index], pattern, depth + 1);
    }
}