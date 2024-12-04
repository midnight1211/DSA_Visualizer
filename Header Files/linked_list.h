#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

template <typename T>
class SinglyLinkedList {
    private:
        struct Node {
            T data;
            Node* next;
            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* head;
        size_t size_;

    public:
        SinglyLinkedList() : head(nullptr), size_(0) {}

        void pushFront(const T& value);
        void pushBack(const T& value);
        bool popFront();
        bool popBack();
        bool remove(const T& value);
        bool contians(const T& value) const;
        size_t size() const { return size_; }
};

template <typename T>
class DoublyLinkedList {
    private:
        struct Node {
            T data;
            Node* prev'
            Node* next;
            Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
        };

        Node* head;
        Node* tail;
        size_t size_;

    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr), size_(0) {}

        void pushFront(const T& value);

};

#endif