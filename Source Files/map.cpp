template <typename K, typename V>
void Map<K, V>::insert(key, value) {
    Node* node = new Node(key, value);
    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (key < x->key)
            x = x->left;
        else if (key > x->key)
            x = x->right;
        else {
            x->value = value;
            delete node;
            return;
        }
    }

    node->parent = y;
    if (y == nullptr)
        root = node;
    else if (key < y->key)
        y->left = node;
    else
        y->right = node;

    fixInsertion(node);
    count++;
}

template <typename K, typename V>
void Map<K, V>::fixInsertion(Node* k) {
    Node* u;
    while(k->parent != nullptr && k->color == RED) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u != nullptr && u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->prent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u != nullptr && u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root)
            break;
    }
    root->color = BLACK;
}

template <typename K, typename V>
void Map<K, V>::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

template <typename K, typename V>
void Map<K,V>::rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    
    if (x->right != nullptr)
        x->right->parent = y;
        
    x->parent = y->parent;
    
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
        
    x->right = y;
    y->parent = x;
}

template <typename K, typename V>
void Map<K,V>::transplant(Node* u, Node* v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
        
    if (v != nullptr)
        v->parent = u->parent;
}

template <typename K, typename V>
typename Map<K,V>::Node* Map<K,V>::minimum(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template <typename K, typename V>
void Map<K,V>::deleteNode(Node* z) {
    Node* y = z;
    Node* x;
    Color y_original_color = y->color;
    
    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    }
    else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        
        if (y->parent == z)
            x->parent = y;
        else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    
    if (y_original_color == BLACK)
        fixDeletion(x);
        
    delete z;
    count--;
}

template <typename K, typename V>
void Map<K,V>::fixDeletion(Node* x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        }
        else {
            // Mirror image of the above code for right case
            Node* w = x->parent->left;
            // ... similar implementation with left/right swapped
        }
    }
    x->color = BLACK;
}

template <typename K, typename V>
void Map<K,V>::clear() {
    std::function<void(Node*)> deleteRecursive = [&](Node* node) {
        if (node != nullptr) {
            deleteRecursive(node->left);
            deleteRecursive(node->right);
            delete node;
        }
    };
    
    deleteRecursive(root);
    root = nullptr;
    count = 0;
}

// Iterator implementation
template <typename K, typename V>
typename Map<K,V>::Iterator& Map<K,V>::Iterator::operator++() {
    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr)
            current = current->left;
    }
    else {
        Node* parent = current->parent;
        while (parent != nullptr && current == parent->right) {
            current = parent;
            parent = parent->parent;
        }
        current = parent;
    }
    return *this;
}

template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::begin() {
    Node* node = root;
    while (node != nullptr && node->left != nullptr)
        node = node->left;
    return Iterator(node);
}

template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::end() {
    return Iterator(nullptr);
}

template <typename K, typename V>
class Map<K,V>::Iterator {
private:
    Node* current;
    
public:
    Iterator(Node* node) : current(node) {}
    
    const K& key() const { return current->key; }
    V& value() const { return current->value; }
    
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& other) const { return current == other.current; }
    bool operator!=(const Iterator& other) const { return !(*this == other); }
};