#ifndef MYDOUBLELINKEDLIST_HPP
#define MYDOUBLELINKEDLIST_HPP

template<typename T>
MyDoubleLinkedList<T>::MyDoubleLinkedList(const T& value)
{
    head = new Node<T>(value);
    tail = head;
    length++;
}

template<typename T>
MyDoubleLinkedList<T>::MyDoubleLinkedList(const MyDoubleLinkedList& other)
{
    auto current = other.head;
    while (current != nullptr)
    {
        push_back(current->data);
        current = current->next;
    }
}

template<typename T>
MyDoubleLinkedList<T>& MyDoubleLinkedList<T>::operator=(const MyDoubleLinkedList& other)
{
    if (this != &other)
    {
        clear();
        auto current = other.head;
        while (current != nullptr)
        {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}

template<typename T>
void MyDoubleLinkedList<T>::push_back(const T& value)
{
    auto new_node = new Node<T>(value);
    
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    
    length++;
}

template<typename T>
void MyDoubleLinkedList<T>::push_front(const T& value)
{
    auto new_node = new Node<T>(value);
    
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
    
    length++;
}

template<typename T>
T& MyDoubleLinkedList<T>::front()
{
    if (head == nullptr)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return head->data;
}

template<typename T>
const T& MyDoubleLinkedList<T>::front() const
{
    if (head == nullptr)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return head->data;
}

template<typename T>
T& MyDoubleLinkedList<T>::back()
{
    if (tail == nullptr)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return tail->data;
}

template<typename T>
const T& MyDoubleLinkedList<T>::back() const
{
    if (tail == nullptr)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    return tail->data;
}

template<typename T>
void MyDoubleLinkedList<T>::pop_back()
{
    if (tail == nullptr) return;
    
    auto temp = tail;
    tail = tail->prev;
    
    if (tail != nullptr)
        tail->next = nullptr;
    else
        head = nullptr; // List is now empty
        
    delete temp;
    length--;
}

template<typename T>
void MyDoubleLinkedList<T>::pop_front()
{
    if (head == nullptr) return;
    
    auto temp = head;
    head = head->next;
    
    if (head != nullptr)
        head->prev = nullptr;
    else
        tail = nullptr; // List is now empty
        
    delete temp;
    length--;
}

template<typename T>
void MyDoubleLinkedList<T>::insert(size_t position, const T& value)
{
    if (position > length)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    
    if (position == 0)
    {
        push_front(value);
    }
    else if (position == length)
    {
        push_back(value);
    }
    else
    {
        auto new_node = new Node<T>(value);
        auto current = head;
        
        for (size_t i = 0; i < position; ++i)
        {
            current = current->next;
        }
        
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;
        
        length++;
    }
}

template<typename T>
void MyDoubleLinkedList<T>::erase(size_t position)
{
    if (position >= length)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    if (position == 0)
    {
        pop_front();
    }
    else if (position == length - 1)
    {
        pop_back();
    }
    else
    {
        auto current = head;
        
        for (size_t i = 0; i < position; ++i)
        {
            current = current->next;
        }
        
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
        delete current;
        length--;
    }
}

template<typename T>
T& MyDoubleLinkedList<T>::operator[](size_t index)
{
    if (index >= length)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    auto temp = head;
    for (size_t i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
const T& MyDoubleLinkedList<T>::operator[](size_t index) const
{
    if (index >= length)
    {
        std::cerr << "index is out of range!" << std::endl;
    }

    auto temp = head;
    for (size_t i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
size_t MyDoubleLinkedList<T>::size() const
{
    return length;
}

template<typename T>
bool MyDoubleLinkedList<T>::empty() const
{
    return length == 0;
}

template<typename T>
void MyDoubleLinkedList<T>::clear()
{
    auto current = head;
    while (current != nullptr)
    {
        auto next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const MyDoubleLinkedList<T>& dl)
{
    auto temp = dl.head;
    while (temp != nullptr)
    {
        os << temp->data;
        if (temp->next != nullptr)
            os << " <-> ";
        temp = temp->next;
    }
    return os;
}

template<typename T>
MyDoubleLinkedList<T>::~MyDoubleLinkedList()
{
    clear();
}

#endif // MYDOUBLELINKEDLIST_HPP