#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>

template <typename K, typename V>
class Dictionary {
    private:
        static const size_t INITIAL_SIZE = 16;
        static const float LOAD_FACTOR = 0.75f;

        struct Entry {
            K key;
            V value;
            Entry* next;
            bool isDeleted;

            Entry(const K& k, const V& v) : key(k), value(v), next(nullptr). isDeleted(false) {}
        };

        std::vector<Entry*> Buckets;
        size_t size_;
        size_t capacity_;

        size_t hash(const K& key) const {
            return std::hash<K>()(key) % capacity_;
        }

        void rehash();
    public:
        Dictionary() : buckets(INITIAL_SIZE, nullptr), size_(0), capacity_(INITIAL_SIZE) {}

        ~Dictionary() {
            clear();
        }

        void put(const K& key, const V& value);
        bool get(const K& key, const V& value) const;
        bool remove(ocnst K& key);
        void clear();

        size_t size() const { return size_; }
        bool isEmpty() const { return size_ == 0; }
        bool containsKey(const K& key) const;
        std::vector<K> keys() const;
        std::vector<V> values() const;  
};

#endif