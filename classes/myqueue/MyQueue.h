#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <vector>
#include <iostream>

template <typename T>
class MyQueue
{
private:
    std::vector<T> array{};    
    
public:
    MyQueue() = default;
    
    MyQueue(const std::vector<T>& _array);
    
    void push(const T& value);
    
    T pop();
    
    T front();
    
    T back();
    
    size_t size() const;
    
    bool empty() const;
    
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyQueue<U>& q);
};

#include "MyQueue.hpp" 

#endif // MYQUEUE_H