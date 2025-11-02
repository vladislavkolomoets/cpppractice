#include "MyVector.h"

MyVector::MyVector(size_t _size) : MyVector(_size, 0)
{
}

MyVector::MyVector(size_t _size, int value) : size(_size)
{
    capacity = size > 0 ? size * capacity_coef : 1; // 

    arr = new int[capacity];

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}

MyVector::MyVector(const int* _array, size_t array_size)
{
    if (_array != nullptr)
    {
        size = array_size;

        capacity = size > 0 ? size * capacity_coef : 1;

        arr = new int[capacity];

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

MyVector::MyVector(const MyVector& other)
{
    if (other.arr != nullptr && other.capacity > 0)
    {
        size = other.size;

        capacity = other.capacity;

        arr = new int[capacity];

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

int& MyVector::at(size_t index)
{
    if (index >= size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }
    return arr[index];
}

const int& MyVector::at(size_t index) const
{
    if (index >= size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }
    return arr[index];
}

size_t MyVector::getSize() const
{
    return size;
}

size_t MyVector::getCapacity() const
{
    return capacity;
}
 
bool MyVector::empty() const
{
    if (arr == nullptr)
    {
        return true;
    }

    return size == 0;
}

void MyVector::push_back(int value)
{
    if (size == 0)
    {
        size++;
        capacity = size * capacity_coef;
        
        arr = new int[capacity];

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

        int* new_arr = new int[capacity];

        for (size_t i = 0; i < size - 1; i++)
        {
            new_arr[i] = arr[i];
        }

        new_arr[size - 1] = value; // warning

        delete[] arr;

        arr = new_arr;
    }
}

void MyVector::pop_back()
{
    if (size > 0)
    {
        size--;
    }
}

void MyVector::insert(size_t pos, int value)
{
    if (pos > size)
    {
        std::cerr << "position is out of range!" << std::endl; 
    }
    else
    {
        size++;

        /*
            if this->array was empty (capacity == 0) => capacity = 1
            if not capacity = capacity * capacity_coef
        */
        size_t new_capacity = (capacity == 0) ? 1 : capacity * capacity_coef;

        int* new_arr = new int[new_capacity];

        for (size_t i = 0; i < pos; i++)
        {
            new_arr[i] = arr[i];
        }

        new_arr[pos] = value;

        for (size_t i = pos + 1; i < size; i++)
        {
            new_arr[i] = arr[i - 1]; // warning
        }

        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }
}

void MyVector::erase(size_t pos)
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

void MyVector::clear()
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    size = 0;
}

MyVector& MyVector::operator=(const MyVector& other)
{
    if (this == &other) return *this;

    if (other.arr != nullptr && capacity > 0)
    {
        delete[] arr;

        size = other.size;

        capacity = other.capacity;

        arr = new int[capacity];

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

int& MyVector::operator[](size_t index)
{
    if (index > size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return arr[index];
}

const int& MyVector::operator[](size_t index) const
{
    if (index > size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return arr[index];
}

bool MyVector::operator==(const MyVector& other) const
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

bool MyVector::operator!=(const MyVector& other) const
{
    return !(*this == other);
}

MyVector::~MyVector()
{
    delete[] arr;
}

std::ostream& operator<<(std::ostream& os, const MyVector& vec)
{
    for (size_t i = 0; i < vec.size; i++)
    {
        os << vec.arr[i] << std::endl;
    }

    return os;
}