#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\hashTable.h"

template<typename K, typename V>
HashTable<K,V>::HashTable()
    : HashTable(INITIAL_CAPACITY) {}

template<typename K, typename V>
HashTable<K,V>::HashTable(size_t initialCapacity)
    : buckets(initialCapacity, nullptr)
    , size_(0)
    , numBuckets_(initialCapacity)
    , maxLoadFactor_(DEFAULT_MAX_LOAD_FACTOR) {}

template<typename K, typename V>
HashTable<K,V>::HashTable(const HashTable& other)
    : buckets(other.numBuckets_, nullptr)
    , size_(0)
    , numBuckets_(other.numBuckets_)
    , maxLoadFactor_(other.maxLoadFactor_) {
    // Copy all elements
    for (size_t i = 0; i < other.numBuckets_; ++i) {
        Node* current = other.buckets[i];
        while (current != nullptr) {
            if (!current->isDeleted) {
                insert(current->key, current->value);
            }
            current = current->next;
        }
    }
}

template<typename K, typename V>
HashTable<K,V>::HashTable(HashTable&& other) noexcept
    : buckets(std::move(other.buckets))
    , size_(other.size_)
    , numBuckets_(other.numBuckets_)
    , maxLoadFactor_(other.maxLoadFactor_) {
    other.size_ = 0;
    other.numBuckets_ = 0;
}

// Element access
template<typename K, typename V>
V& HashTable<K,V>::at(const K& key) {
    auto it = find(key);
    if (it == end()) {
        throw std::out_of_range("Key not found");
    }
    return it->value;
}

template<typename K, typename V>
V& HashTable<K,V>::operator[](const K& key) {
    auto it = find(key);
    if (it == end()) {
        auto [newIt, inserted] = insert(key, V{});
        return newIt->value;
    }
    return it->value;
}

// Modifiers
template<typename K, typename V>
std::pair<typename HashTable<K,V>::iterator, bool> 
HashTable<K,V>::insert(const K& key, const V& value) {
    if (load_factor() > maxLoadFactor_) {
        rehash(numBuckets_ * 2);
    }
    
    size_t bucket = hash(key);
    Node* current = buckets[bucket];
    
    // Check for existing key
    while (current != nullptr) {
        if (current->key == key && !current->isDeleted) {
            return {iterator(this, bucket, current), false};
        }
        current = current->next;
    }
    
    // Insert new node at front of bucket
    Node* newNode = new Node(key, value);
    newNode->next = buckets[bucket];
    buckets[bucket] = newNode;
    size_++;
    
    return {iterator(this, bucket, newNode), true};
}

template<typename K, typename V>
size_t HashTable<K,V>::erase(const K& key) {
    size_t bucket = hash(key);
    Node* current = buckets[bucket];
    Node* prev = nullptr;
    
    while (current != nullptr) {
        if (current->key == key && !current->isDeleted) {
            if (prev == nullptr) {
                buckets[bucket] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            size_--;
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

// Hash policy
template<typename K, typename V>
void HashTable<K,V>::rehash(size_t newSize) {
    std::vector<Node*> oldBuckets = std::move(buckets);
    size_t oldNumBuckets = numBuckets_;
    
    // Reset to new size
    buckets.resize(newSize);
    std::fill(buckets.begin(), buckets.end(), nullptr);
    numBuckets_ = newSize;
    size_ = 0;
    
    // Reinsert all elements
    for (size_t i = 0; i < oldNumBuckets; ++i) {
        Node* current = oldBuckets[i];
        while (current != nullptr) {
            Node* next = current->next;
            if (!current->isDeleted) {
                insert(current->key, current->value);
            }
            delete current;
            current = next;
        }
    }
}

// Capacity
template<typename K, typename V>
size_t HashTable<K,V>::size() const {
    return size_;
}

template<typename K, typename V>
bool HashTable<K,V>::empty() const {
    return size_ == 0;
}

// Lookup
template<typename K, typename V>
bool HashTable<K,V>::contains(const K& key) const {
    return find(key) != end();
}

// Cleanup
template<typename K, typename V>
HashTable<K,V>::~HashTable() {
    clear();
}

template<typename K, typename V>
void HashTable<K,V>::clear() {
    for (auto& bucket : buckets) {
        Node* current = bucket;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        bucket = nullptr;
    }
    size_ = 0;
}

// ... previous implementations remain the same ...

// Assignment operators
template<typename K, typename V>
HashTable<K,V>& HashTable<K,V>::operator=(const HashTable& other) {
    if (this != &other) {
        clear();
        delete[] buckets;
        
        numBuckets_ = other.numBuckets_;
        size_ = 0;
        maxLoadFactor_ = other.maxLoadFactor_;
        buckets = new Node*[numBuckets_]();
        
        // Copy all elements
        for (size_t i = 0; i < other.numBuckets_; ++i) {
            Node* current = other.buckets[i];
            while (current != nullptr) {
                if (!current->isDeleted) {
                    insert(current->key, current->value);
                }
                current = current->next;
            }
        }
    }
    return *this;
}

template<typename K, typename V>
HashTable<K,V>& HashTable<K,V>::operator=(HashTable&& other) noexcept {
    if (this != &other) {
        clear();
        delete[] buckets;
        
        buckets = other.buckets;
        size_ = other.size_;
        numBuckets_ = other.numBuckets_;
        maxLoadFactor_ = other.maxLoadFactor_;
        
        other.buckets = nullptr;
        other.size_ = 0;
        other.numBuckets_ = 0;
    }
    return *this;
}

// Iterator implementations
template<typename K, typename V>
typename HashTable<K,V>::iterator HashTable<K,V>::begin() {
    for (size_t i = 0; i < numBuckets_; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            if (!current->isDeleted) {
                return iterator(this, i, current);
            }
            current = current->next;
        }
    }
    return end();
}

template<typename K, typename V>
typename HashTable<K,V>::const_iterator HashTable<K,V>::begin() const {
    return const_iterator(const_cast<HashTable*>(this)->begin());
}

template<typename K, typename V>
typename HashTable<K,V>::iterator HashTable<K,V>::end() {
    return iterator(this, numBuckets_, nullptr);
}

template<typename K, typename V>
typename HashTable<K,V>::const_iterator HashTable<K,V>::end() const {
    return const_iterator(const_cast<HashTable*>(this)->end());
}

// Lookup operations
template<typename K, typename V>
typename HashTable<K,V>::iterator HashTable<K,V>::find(const K& key) {
    size_t index = hash(key);
    Node* current = buckets[index];
    
    while (current != nullptr) {
        if (current->key == key && !current->isDeleted) {
            return iterator(this, index, current);
        }
        current = current->next;
    }
    return end();
}

template<typename K, typename V>
std::pair<typename HashTable<K,V>::iterator, bool> 
HashTable<K,V>::insert_or_assign(const K& key, const V& value) {
    auto it = find(key);
    if (it != end()) {
        it->value = value;
        return {it, false};
    }
    return {insert(key, value).first, true};
}

template<typename K, typename V>
template<typename... Args>
std::pair<typename HashTable<K,V>::iterator, bool> 
HashTable<K,V>::emplace(Args&&... args) {
    auto pair = std::make_pair(std::forward<Args>(args)...);
    return insert(pair.first, pair.second);
}

template<typename K, typename V>
bool HashTable<K,V>::try_emplace(const K& key, const V& value) {
    if (contains(key)) return false;
    insert(key, value);
    return true;
}

// Bucket interface
template<typename K, typename V>
size_t HashTable<K,V>::bucket_size(size_t n) const {
    if (n >= numBuckets_) return 0;
    
    size_t count = 0;
    Node* current = buckets[n];
    while (current != nullptr) {
        if (!current->isDeleted) count++;
        current = current->next;
    }
    return count;
}

template<typename K, typename V>
size_t HashTable<K,V>::bucket(const K& key) const {
    return hash(key);
}

template<typename K, typename V>
size_t HashTable<K,V>::max_bucket_count() const {
    return std::numeric_limits<size_t>::max();
}

// Hash policy
template<typename K, typename V>
float HashTable<K,V>::load_factor() const {
    return static_cast<float>(size_) / numBuckets_;
}

template<typename K, typename V>
float HashTable<K,V>::max_load_factor() const {
    return maxLoadFactor_;
}

template<typename K, typename V>
void HashTable<K,V>::max_load_factor(float ml) {
    maxLoadFactor_ = ml;
    if (load_factor() > maxLoadFactor_) {
        rehash(numBuckets_ * 2);
    }
}

template<typename K, typename V>
void HashTable<K,V>::merge(HashTable& source) {
    for (auto it = source.begin(); it != source.end();) {
        if (!contains(it->key)) {
            insert(it->key, it->value);
            auto current = it++;
            source.erase(current);
        } else {
            ++it;
        }
    }
}

template<typename K, typename V>
template<typename InputIt>
void HashTable<K,V>::insert(InputIt first, InputIt last) {
    for (auto it = first; it != last; ++it) {
        insert(it->first, it->second);
    }
}

// Equal range implementation
template<typename K, typename V>
std::pair<typename HashTable<K,V>::iterator, typename HashTable<K,V>::iterator>
HashTable<K,V>::equal_range(const K& key) {
    auto it = find(key);
    if (it == end()) {
        return {it, it};
    }
    auto next = it;
    ++next;
    return {it, next};
}

template<typename K, typename V>
size_t HashTable<K,V>::count(const K& key) const {
    return contains(key) ? 1 : 0;
}

// Swap implementation
template<typename K, typename V>
void HashTable<K,V>::swap(HashTable& other) noexcept {
    std::swap(buckets, other.buckets);
    std::swap(size_, other.size_);
    std::swap(numBuckets_, other.numBuckets_);
    std::swap(maxLoadFactor_, other.maxLoadFactor_);
}