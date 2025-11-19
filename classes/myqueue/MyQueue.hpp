#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP

#include "MyQueue.h"

template <typename T>
MyQueue<T>::MyQueue(const std::vector<T>& _array)
{
    array = _array;
}

template <typename T>
void MyQueue<T>::push(const T& value)
{
    array.push_back(value);
}

template <typename T>
T MyQueue<T>::pop()
{
    if (array.size() == 0)
    {
        std::cerr << "queue is empty!" << std::endl;
    }
    
    auto temp = array[0];
        
    //array.erase(0);
    array.erase(array.begin());
        
    return temp;
}

template <typename T>
T MyQueue<T>::front()
{
    return array.front();
}

template <typename T>
T MyQueue<T>::back()
{
    return array.back();
}

template <typename T>
size_t MyQueue<T>::size() const
{
    return array.size();   
}

template <typename T>
bool MyQueue<T>::empty() const
{
    return array.empty();   
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyQueue<T>& q)
{
    for (const auto el : q.array)
    {
        os << el << " ";
    }
    
    os << std::endl;
    
    return os;
}

#endif // MYQUEUE_HPP