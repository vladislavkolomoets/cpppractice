#include <iostream>
#include <cassert>

#include "MyDoubleLinkedList.h"


void testDoubleLinkedList()
{
    // Test 1: Default constructor
    {
        MyDoubleLinkedList<int> dl;
        assert(dl.size() == 0);
        assert(dl.empty());
        std::cout << "Passed: Test 1 Default constructor\n";
    }

    // Test 2: Constructor with initial value
    {
        MyDoubleLinkedList<int> dl(42);
        assert(dl.size() == 1);
        assert(!dl.empty());
        assert(dl.front() == 42);
        assert(dl.back() == 42);
        std::cout << "Passed: Test 2 Constructor with initial value\n";
    }

    // Test 3: push_back and push_front
    {
        MyDoubleLinkedList<int> dl;
        dl.push_back(2);
        dl.push_back(3);
        dl.push_front(1);
        
        assert(dl.size() == 3);
        assert(dl.front() == 1);
        assert(dl.back() == 3);
        std::cout << "Passed: Test 3 push_back and push_front\n";
    }

    // Test 4: pop_back and pop_front
    {
        MyDoubleLinkedList<int> dl;
        dl.push_back(1);
        dl.push_back(2);
        dl.push_back(3);
        
        dl.pop_front();
        assert(dl.size() == 2);
        assert(dl.front() == 2);
        
        dl.pop_back();
        assert(dl.size() == 1);
        assert(dl.back() == 2);
        assert(dl.front() == 2);
        
        dl.pop_back();
        assert(dl.empty());
        std::cout << "Passed: Test 4 pop_back and pop_front\n";
    }

    // Test 5: Copy constructor
    {
        MyDoubleLinkedList<int> original;
        original.push_back(1);
        original.push_back(2);
        original.push_back(3);
        
        MyDoubleLinkedList<int> copy(original);
        assert(copy.size() == 3);
        assert(copy.front() == 1);
        assert(copy.back() == 3);
        assert(copy[1] == 2);
        std::cout << "Passed: Test 5 Copy constructor\n";
    }

    // Test 6: Assignment operator
    {
        MyDoubleLinkedList<int> original;
        original.push_back(10);
        original.push_back(20);
        
        MyDoubleLinkedList<int> assigned;
        assigned = original;
        
        assert(assigned.size() == 2);
        assert(assigned.front() == 10);
        assert(assigned.back() == 20);
        std::cout << "Passed: Test 6 Assignment operator\n";
    }

    // Test 7: Subscript operator
    {
        MyDoubleLinkedList<int> dl;
        dl.push_back(100);
        dl.push_back(200);
        dl.push_back(300);
        
        assert(dl[0] == 100);
        assert(dl[1] == 200);
        assert(dl[2] == 300);
        std::cout << "Passed: Test 7 Subscript operator\n";
    }

    // Test 8: Insert 
    {
        MyDoubleLinkedList<int> dl;
        dl.push_back(1);
        dl.push_back(3);
        
        dl.insert(0, 0);
        assert(dl.front() == 0);
        
        dl.insert(2, 2);
        assert(dl[2] == 2);
        
        dl.insert(4, 4);
        assert(dl.back() == 4);
        
        assert(dl.size() == 5);
        std::cout << "Passed: Test 8 Insert\n";
    }

    // Test 9: Erase
    {
        MyDoubleLinkedList<int> dl;
        dl.push_back(1);
        dl.push_back(2);
        dl.push_back(3);
        dl.push_back(4);
        
        dl.erase(1);
        assert(dl.size() == 3);
        assert(dl[1] == 3);
        
        dl.erase(0);
        assert(dl.front() == 3);
        
        dl.erase(1);
        assert(dl.back() == 3);
        assert(dl.size() == 1);
        std::cout << "Passed: Test 9 Erase\n";
    }

    // Test 10: Clear
    {
        MyDoubleLinkedList<int> dl;
        dl.push_back(1);
        dl.push_back(2);
        dl.push_back(3);
        
        dl.clear();
        assert(dl.size() == 0);
        assert(dl.empty());
        std::cout << "Passed: Test 10 Clear\n";
    }

    std::cout << "All tests passed successfully!\n";
}

int main()
{
    testDoubleLinkedList();
    return 0;
}