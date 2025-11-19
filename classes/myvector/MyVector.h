#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

template <typename T>
class MyVector
{
private:
    T* arr = nullptr;
    size_t size{};
    size_t capacity{};
    const double capacity_coef = 2.;

public:
    MyVector() = default;
    MyVector(size_t _size);
    MyVector(size_t _size, T value);
    MyVector(const T* _array, size_t array_size);
    MyVector(const MyVector<T>& other);

    T& at(size_t index);
    const T& at(size_t index) const;
    size_t getSize() const;
    size_t getCapacity() const;
    bool empty() const;

    void push_back(T value);
    void pop_back();
    void insert(size_t pos, T value);
    void erase(size_t pos);
    void clear();

    MyVector<T>& operator=(const MyVector<T>& other);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    bool operator==(const MyVector<T>& other) const;
    bool operator!=(const MyVector<T>& other) const;
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyVector<U>& vec);

    ~MyVector();
};

#include "MyVector.hpp"

#endif // MYVECTOR_H