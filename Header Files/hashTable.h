#pragma once
#include <vector>
#include <functional>
#include <stdexcept>
#include <optional>
#include <list>

#ifndef HASHTABLE_H
#define HASHTABLE_H

template <typename K, typename V>
class HashTable {
private:
    struct Node {
        K key;
        V value;
        bool isDeleted;
        Node* next;
        
        Node(const K& k, const V& v) 
            : key(k), value(v), isDeleted(false), next(nullptr) {}
    };
    
    std::vector<Node*> buckets;
    size_t size_;
    size_t numBuckets_;
    float maxLoadFactor_;
    
    static const size_t INITIAL_CAPACITY = 16;
    static constexpr float DEFAULT_MAX_LOAD_FACTOR = 0.75f;
    
    size_t hash(const K& key) const {
        return std::hash<K>{}(key) % numBuckets_;
    }
    
    void rehash(size_t newSize);
    
public:
    // Iterator class declarations
    class iterator;
    class const_iterator;
    
    // Constructors & Destructor
    HashTable();
    explicit HashTable(size_t initialCapacity);
    HashTable(const HashTable& other);
    HashTable(HashTable&& other) noexcept;
    ~HashTable();
    
    // Assignment operators
    HashTable& operator=(const HashTable& other);
    HashTable& operator=(HashTable&& other) noexcept;
    
    // Element access
    V& at(const K& key);
    const V& at(const K& key) const;
    V& operator[](const K& key);
    
    // Iterators
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    
    // Capacity
    bool empty() const;
    size_t size() const;
    size_t max_size() const;
    
    // Modifiers
    void clear();
    std::pair<iterator, bool> insert(const K& key, const V& value);
    std::pair<iterator, bool> insert_or_assign(const K& key, const V& value);
    template<typename... Args>
    std::pair<iterator, bool> emplace(Args&&... args);
    iterator erase(const_iterator pos);
    size_t erase(const K& key);
    void swap(HashTable& other) noexcept;
    
    // Lookup
    iterator find(const K& key);
    const_iterator find(const K& key) const;
    size_t count(const K& key) const;
    bool contains(const K& key) const;
    std::pair<iterator, iterator> equal_range(const K& key);
    
    // Bucket interface
    size_t bucket_count() const;
    size_t max_bucket_count() const;
    size_t bucket_size(size_t n) const;
    size_t bucket(const K& key) const;
    
    // Hash policy
    float load_factor() const;
    float max_load_factor() const;
    void max_load_factor(float ml);
    void rehash(size_t count);
    void reserve(size_t count);
    
    // Observers
    std::vector<K> keys() const;
    std::vector<V> values() const;
};

#endif