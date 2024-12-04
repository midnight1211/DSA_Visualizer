#ifndef SUFFIX_ARRAY_H
#define SUFFIX_ARRAY_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SuffixArray {
    private:
        std::string text;
        std::vector<int> suffixArray;

        void buildSuffixArray();

    public:
        SuffixArray(const std::string& text);
        void display() const;
        bool search(const std::string& pattern) const;
        std::vector<int> buildLCP() const;
        int countOccurrences(const std::string& pattern) const;
        void findAllOccurrences(const std::string& pattern, std::vector<int>& occurrences) const;
};

#endif
