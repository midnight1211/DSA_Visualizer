#ifndef MAP_H
#define MAP_H

template <typename K, typename V>
class Map {
    enum Color { RED, BLACK };

    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;
        Node* parent;
        Color color;
        Node(const K& k, const V& v) : key(k), value(v), left(nullptr), right(nullptr). color(RED) {}
    };

    Node* root;
    size_t count;

    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void fixInsertion(Node* k);
    void transplant(Node* u, Node* v);
    void fixDeletion(Node* x);
    Node* minimum(Node* node);
    void deleteNode(Node* node);

    public:
        Map() : root(nullptr), count(0) {}

        void insert(const K& key, const V& value);
        bool contains(const K& key) const;
        V& operator[](const K& key);
        void erase(const K& key);
        size_t size() const { return count; }
        bool isEmpty() const { return count == 0; }
        void clear(); 

        class Iterator;
        Iterator begin();
        Iterator end();
};

#endif // MAP_H