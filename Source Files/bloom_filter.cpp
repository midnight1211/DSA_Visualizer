#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\bloom_filter.h"

// Constructor
BloomFilter::BloomFilter(int numHashFunctions) : numHashFunctions(numHashFunctions) {}

// Hash function 1
int BloomFilter::hash1(const std::string& str) const {
    std::hash<std::string> hashFn;
    return hashFn(str) % bitset.size();
}

// Hash function 2
int BloomFilter::hash2(const std::string& str) const {
    std::hash<std::string> hashFn;
    return (hashFn(str) / 37) % bitset.size();
}

// Add a string to the Bloom Filter
void BloomFilter::add(const std::string& str) {
    int hash1Value = hash1(str);
    int hash2Value = hash2(str);
    bitset.set(hash1Value);
    bitset.set(hash2Value);
}

// Check if the string is in the Bloom Filter
bool BloomFilter::contains(const std::string& str) const {
    int hash1Value = hash1(str);
    int hash2Value = hash2(str);
    return bitset.test(hash1Value) && bitset.test(hash2Value)
}