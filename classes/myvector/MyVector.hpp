#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include "MyVector.h"

template <typename T>
MyVector<T>::MyVector(size_t _size) : MyVector(_size, T{})
{
}

template <typename T>
MyVector<T>::MyVector(size_t _size, T value) : size(_size)
{
    capacity = size > 0 ? size * capacity_coef : 1;

    arr = new T[capacity];

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}

template <typename T>
MyVector<T>::MyVector(const T* _array, size_t array_size)
{
    if (_array != nullptr)
    {
        size = array_size;

        capacity = size > 0 ? size * capacity_coef : 1;

        arr = new T[capacity];

        for (size_t i = 0; i < size; i++)
        {
            arr[i] = _array[i];
        }
    }
    else
    {
        size = 0;
        capacity = 0;
        arr = nullptr;
    }
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
    if (other.arr != nullptr && other.capacity > 0)
    {
        size = other.size;

        capacity = other.capacity;

        arr = new T[capacity];

        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    else
    {
        arr = nullptr;
    }
}

template <typename T>
T& MyVector<T>::at(size_t index)
{
    if (index >= size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }
    return arr[index];
}

template <typename T>
const T& MyVector<T>::at(size_t index) const
{
    if (index >= size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }
    return arr[index];
}

template <typename T>
size_t MyVector<T>::getSize() const
{
    return size;
}

template <typename T>
size_t MyVector<T>::getCapacity() const
{
    return capacity;
}
 
template <typename T>
bool MyVector<T>::empty() const
{
    if (arr == nullptr)
    {
        return true;
    }

    return size == 0;
}

template <typename T>
void MyVector<T>::push_back(T value)
{
    if (size == 0)
    {
        size++;
        capacity = size * capacity_coef;
        
        arr = new T[capacity];

        arr[size-1] = value;
    }
    else if (size < capacity)
    {
        size++;
        arr[size - 1] = value;
    }
    else if (size == capacity)
    {
        size++;
        capacity = size * capacity_coef;

        T* new_arr = new T[capacity];

        for (size_t i = 0; i < size - 1; i++)
        {
            new_arr[i] = arr[i];
        }

        new_arr[size - 1] = value;

        delete[] arr;

        arr = new_arr;
    }
}

template <typename T>
void MyVector<T>::pop_back()
{
    if (size > 0)
    {
        size--;
    }
}

template <typename T>
void MyVector<T>::insert(size_t pos, T value)
{
    if (pos > size)
    {
        std::cerr << "position is out of range!" << std::endl; 
    }
    else
    {
        size++;

        size_t new_capacity = (capacity == 0) ? 1 : capacity * capacity_coef;

        T* new_arr = new T[new_capacity];

        for (size_t i = 0; i < pos; i++)
        {
            new_arr[i] = arr[i];
        }

        new_arr[pos] = value;

        for (size_t i = pos + 1; i < size; i++)
        {
            new_arr[i] = arr[i - 1];
        }

        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }
}

template <typename T>
void MyVector<T>::erase(size_t pos)
{
    if (pos >= size)
    {
        std::cerr << "position is out of range!" << std::endl;
    }
    else
    {
        for (size_t i = pos; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }
}

template <typename T>
void MyVector<T>::clear()
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = T{};
    }

    size = 0;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
    if (this == &other) return *this;

    if (other.arr != nullptr && capacity > 0)
    {
        delete[] arr;

        size = other.size;

        capacity = other.capacity;

        arr = new T[capacity];

        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i]; 
        }
    }
    else
    {
        arr = nullptr;
    }

    return *this;
}

template <typename T>
T& MyVector<T>::operator[](size_t index)
{
    if (index > size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return arr[index];
}

template <typename T>
const T& MyVector<T>::operator[](size_t index) const
{
    if (index > size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return arr[index];
}

template <typename T>
bool MyVector<T>::operator==(const MyVector<T>& other) const
{
    if (size != other.size)
    {
        return false;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] != other.arr[i])
        {
            return false;
        }
    }

    return true;
}

template <typename T>
bool MyVector<T>::operator!=(const MyVector<T>& other) const
{
    return !(*this == other);
}

template <typename T>
MyVector<T>::~MyVector()
{
    delete[] arr;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const MyVector<U>& vec)
{
    for (size_t i = 0; i < vec.size; i++)
    {
        os << vec.arr[i] << std::endl;
    }

    return os;
}

#endif // MYVECTOR_CPP