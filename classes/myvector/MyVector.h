#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

class MyVector
{
private:
    int* arr = nullptr;
    size_t size{};
    size_t capacity{};
    const double capacity_coef = 2.;

public:
    MyVector() = default;
    MyVector(size_t _size);
    MyVector(size_t _size, int value);
    MyVector(const int* _array, size_t array_size);
    MyVector(const MyVector& other);

    int& at(size_t index);
    const int& at(size_t index) const;
    //size_t size();
    //size_t capacity();
    size_t getSize();
    size_t getCapacity();
    bool empty();

    void push_back(int value);
    void pop_back();
    void insert(size_t pos, int value);
    void erase(size_t pos);
    void clear();

    MyVector& operator=(const MyVector& other);
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    bool operator==(const MyVector& other);
    bool operator!=(const MyVector& other);
    friend std::ostream& operator<<(std::ostream& os, const MyVector& vec);

    ~MyVector();
};

#endif // MYVECTOR_H