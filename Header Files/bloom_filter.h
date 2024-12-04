#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <iostream>
#include <vector>
#include <bitset>
#include <functional>

class BloomFilter {
    private:
        std::bitset<1000> bitset;
        int numHashFunctions;

        int hash1(const std::string& str) const;
        int hash2(const std::string& str) const;

    public:
        BloomFilter(int numHashFunctions);
        void add(const std::string & str);
        bool contains(const std::string& str) const;
};

#endif