#include <iostream>
#include <cassert>

#include "MyQueue.h"

void testMyQueue()
{
    // Test 1: Default constructor
    {
        MyQueue<int> q;
        assert(q.size() == 0);
        assert(q.empty());
        std::cout << "Passed: Test 1 Default constructor\n";
    }
    
    // Test 2: Constructor from vector
    {
        std::vector<int> vec = {1, 2, 3};
        MyQueue<int> q(vec);
        assert(q.size() == 3);
        assert(!q.empty());
        std::cout << "Passed: Test 2 Constructor from vector\n";
    }
    
    // Test 3: Push operation
    {
        MyQueue<int> q;
        q.push(10);
        assert(q.size() == 1);
        assert(q.front() == 10);
        assert(q.back() == 10);
        
        q.push(20);
        assert(q.size() == 2);
        assert(q.front() == 10);
        assert(q.back() == 20);
        
        q.push(30);
        assert(q.size() == 3);
        assert(q.front() == 10);
        assert(q.back() == 30);
        
        std::cout << "Passed: Test 3 Push operation\n";
    }
    
    // Test 4: Pop operation
    {
        std::vector<int> vec = {1, 2, 3};
        MyQueue<int> q(vec);
        
        assert(q.pop() == 1);
        assert(q.size() == 2);
        assert(q.front() == 2);
        
        assert(q.pop() == 2);
        assert(q.size() == 1);
        assert(q.front() == 3);
        
        assert(q.pop() == 3);
        assert(q.size() == 0);
        assert(q.empty());
        
        std::cout << "Passed: Test 4 Pop operation\n";
    }
    
    // Test 6: Mixed operations
    {
        MyQueue<int> q;
        q.push(100);
        q.push(200);
        assert(q.pop() == 100);
        q.push(300);
        assert(q.pop() == 200);
        q.push(400);
        assert(q.pop() == 300);
        assert(q.pop() == 400);
        assert(q.empty());
        
        std::cout << "Passed: Test 5 Mixed operations\n";
    }
    
    std::cout << "All tests passed successfully!\n";
}

int main() 
{
    testMyQueue();
    
    return 0;
}