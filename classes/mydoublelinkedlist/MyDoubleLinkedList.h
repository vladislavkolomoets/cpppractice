#ifndef MYDOUBLELINKEDLIST_H
#define MYDOUBLELINKEDLIST_H

#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
    
    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template<typename T>
class MyDoubleLinkedList
{
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t length{};
    
public:
    MyDoubleLinkedList() = default;
    MyDoubleLinkedList(const T& value);
    MyDoubleLinkedList(const MyDoubleLinkedList& other);
    
    MyDoubleLinkedList& operator=(const MyDoubleLinkedList& other);
    
    void push_back(const T& value);
    void push_front(const T& value);
    
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    
    void pop_back();
    void pop_front();
    
    void insert(size_t position, const T& value);
    
    void erase(size_t position);
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    size_t size() const;
    bool empty() const;
    
    void clear();
    
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyDoubleLinkedList<U>& dl);

    ~MyDoubleLinkedList();
};

#include "MyDoubleLinkedList.hpp"

#endif // MYDOUBLELINKEDLIST_H