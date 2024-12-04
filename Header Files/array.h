#include <iostream>
#include <stdexcept>
#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class DynamicArray {
  private:
    T* data;
    int size;
    int capacity;

    void resize(int newCapacity);

    public:
      DynamicArray(int initialCapacity = 2) : size(0), capacity(initialCapacity) {
        data = new T[initialCapacity];
      }
      ~DynamicArray();
      int getSize() const;
      int getCapacity() const;
      void insert(const T& element);
      void remove();
      T& operator[](int index);
      const T& operator[](int index) const;
};
#endif //ARRAY_H
