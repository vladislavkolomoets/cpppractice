#include "MyVector.h"

MyVector::MyVector(size_t _size) : MyVector(_size, 0)
{
}

MyVector::MyVector(size_t _size, int value) : size(_size)
{
    capacity = size * capacity_coef;

    arr = new int[capacity];

    for (int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}

MyVector::MyVector(const int* _array, size_t array_size)
{
    if (_array != nullptr)
    {
        size = array_size;

        capacity = size * capacity_coef;

        arr = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            arr[i] = _array[i];
        }
    }
}

MyVector::MyVector(const MyVector& other)
{
    size = other.size;

    capacity = size * capacity_coef;

    arr = new int[capacity];

    for (int i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
}

int& MyVector::at(size_t index)
{
    if (index < 0 || index > size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }
    return arr[index];
}

const int& MyVector::at(size_t index) const
{
    if (index < 0 || index > size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }
    return arr[index];
}

size_t MyVector::getSize()
{
    return size;
}

size_t MyVector::getCapacity()
{
    return capacity;
}

bool MyVector::empty()
{
    if (arr == nullptr)
    {
        return true;
    }
    return size == 0 ? true : false;
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
    else if (size > 0 && size < capacity)
    {
        size++;
        arr[size - 1] = value;
    }
    else if (size == capacity)
    {
        size++;
        capacity = size * capacity_coef;

        int* new_arr = new int[capacity];

        for (int i = 0; i < size - 1; i++)
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
    size--;
}

void MyVector::insert(size_t pos, int value)
{
    if (pos < 0 || pos > size)
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

        for (int i = 0; i < pos; i++)
        {
            new_arr[i] = arr[i];
        }

        new_arr[pos] = value;

        for (int i = pos + 1; i < size; i++)
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
    if (pos < 0 || pos > size)
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
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    size = 0;
}

MyVector& MyVector::operator=(const MyVector& other)
{
    size = other.size;

    capacity = size * capacity_coef;

    arr = new int[capacity];

    for (int i = 0; i < size; i++)
    {
        arr[i] = other.arr[i]; // warning
    }

    return *this;
}

int& MyVector::operator[](size_t index)
{
    if (index < 0 || index > size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return arr[index];
}

const int& MyVector::operator[](size_t index) const
{
    if (index < 0 || index > size)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return arr[index];
}

bool MyVector::operator==(const MyVector& other)
{
    if (size != other.size)
    {
        return false;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != other.arr[i])
        {
            return false;
        }
    }

    return true;
}

bool MyVector::operator!=(const MyVector& other)
{
    if (size != other.size)
    {
        return true;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != other.arr[i])
        {
            return true;
        }
    }

    return false;
}

MyVector::~MyVector()
{
    delete[] arr;
}

std::ostream& operator<<(std::ostream& os, const MyVector& vec)
{
    for (int i = 0; i < vec.size; i++)
    {
        os << vec.arr[i] << std::endl;
    }

    return os;
}