#include <cassert>
#include <iostream>

#include "MyVector.h"

void testMyVector()
{
    // Test 1: Default constructor
    {
        MyVector v;
        assert(v.getSize() == 0);
        assert(v.getCapacity() == 0);
        assert(v.empty());
        std::cout << "Passed: Test 1 Default constructor\n";
    }

    // Test 2: Constructor with size
    {
        MyVector v(5);
        assert(v.getSize() == 5);
        assert(v.getCapacity() >= 5);
        for (size_t i = 0; i < 5; ++i)
        {
            assert(v[i] == 0);
        }
        std::cout << "Passed: Test 2 Constructor with size\n";
    }

    // Test 3: Constructor with size and value
    {
        MyVector v(3, 42);
        assert(v.getSize() == 3);
        for (size_t i = 0; i < 3; ++i)
        {
            assert(v[i] == 42);
        }
        std::cout << "Passed Test 3: Constructor with size and value\n";
    }

    // Test 4: Constructor with array
    {
        int arr[] = { 1, 2, 3, 4, 5 };
        MyVector v(arr, 5);
        assert(v.getSize() == 5);
        for (size_t i = 0; i < 5; ++i)
        {
            assert(v[i] == arr[i]);
        }
        std::cout << "Passed Test 4: Constructor with array\n";
    }

    // Test 5: push_back
    {
        MyVector v;
        assert(v.empty());

        v.push_back(10);
        assert(v.getSize() == 1);
        assert(v[0] == 10);

        v.push_back(20);
        assert(v.getSize() == 2);
        assert(v[0] == 10);
        assert(v[1] == 20);

        v.push_back(30);
        assert(v.getSize() == 3);
        assert(v[0] == 10);
        assert(v[1] == 20);
        assert(v[2] == 30);
        assert(v.getCapacity() >= 3);

        std::cout << "Passed: Test 5: push_back\n";
    }

    // Test 6: pop_back
    {
        MyVector v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        assert(v.getSize() == 3);
        v.pop_back();
        assert(v.getSize() == 2);
        assert(v[0] == 1);
        assert(v[1] == 2);

        v.pop_back();
        assert(v.getSize() == 1);
        assert(v[0] == 1);

        v.pop_back();
        assert(v.getSize() == 0);
        assert(v.empty());

        // Pop back on empty vector
        v.pop_back();
        assert(v.getSize() == 0);

        std::cout << "Passed: Test 6: pop_back\n";
    }

    // Test 7: Insert at beginning
    {
        int arr[] = { 2, 3 };
        MyVector v(arr, 2);
        v.insert(0, 1);

        assert(v.getSize() == 3);
        assert(v[0] == 1);
        assert(v[1] == 2);
        assert(v[2] == 3);
        std::cout << "Passed: Test 7: Insert at beginning\n";
    }

    // Test 8: Insert in middle
    {
        int arr[] = { 1, 2, 3 };
        MyVector v(arr, 3);
        v.insert(1, 99);

        assert(v.getSize() == 4);
        assert(v[0] == 1);
        assert(v[1] == 99);
        assert(v[2] == 2);
        assert(v[3] == 3);
        std::cout << "Passed: Test 8: Insert in middle\n";
    }

    // Test 9: Insert at end
    {
        int arr[] = { 1, 2, 3 };
        MyVector v(arr, 3);
        v.insert(3, 4);

        assert(v.getSize() == 4);
        assert(v[0] == 1);
        assert(v[1] == 2);
        assert(v[2] == 3);
        assert(v[3] == 4);
        std::cout << "Passed: Test 9: Insert at end\n";
    }

    // Test 10: Erase from beginning
    {
        int arr[] = { 1, 2, 3, 4 };
        MyVector v(arr, 4);
        v.erase(0);

        assert(v.getSize() == 3);
        assert(v[0] == 2);
        assert(v[1] == 3);
        assert(v[2] == 4);
        std::cout << "Passed: Test 10: Erase from beginning\n";
    }

    // Test 11: Erase from middle
    {
        int arr[] = { 10, 20, 30, 40 };
        MyVector v(arr, 4);
        v.erase(1);

        assert(v.getSize() == 3);
        assert(v[0] == 10);
        assert(v[1] == 30);
        assert(v[2] == 40);
        std::cout << "Passed: Test 11: Erase from middle\n";
    }

    // Test 12: Erase from end
    {
        int arr[] = { 1, 2, 3, 4 };
        MyVector v(arr, 4);
        v.erase(3);

        assert(v.getSize() == 3);
        assert(v[0] == 1);
        assert(v[1] == 2);
        assert(v[2] == 3);
        std::cout << "Passed: Test 12: Erase from end\n";
    }

    // Test 13: Clear
    {
        int arr[] = { 1, 2, 3 };
        MyVector v(arr, 3);
        assert(v.getSize() == 3);

        v.clear();
        assert(v.getSize() == 0);
        assert(v.empty());

        // Clear empty vector
        v.clear();
        assert(v.getSize() == 0);
        assert(v.empty());

        std::cout << "Passed: Test 13: Clear\n";
    }

    // Test 14: Copy constructor
    {
        int arr[] = { 1, 2, 3 };
        MyVector original(arr, 3);
        MyVector copy = original;

        assert(copy.getSize() == 3);
        assert(copy[0] == 1);
        assert(copy[1] == 2);
        assert(copy[2] == 3);

        // Modify original, copy should not change
        original[0] = 100;
        assert(copy[0] == 1); 

        std::cout << "Passed: Test 14: Copy constructor\n";
    }

    // Test 15: Assignment operator
    {
        int arr1[] = { 1, 2, 3 };
        int arr2[] = { 4, 5, 6, 7 };
        MyVector v1(arr1, 3);
        MyVector v2(arr2, 4);

        v1 = v2;
        assert(v1.getSize() == 4);
        assert(v1[0] == 4);
        assert(v1[1] == 5);
        assert(v1[2] == 6);
        assert(v1[3] == 7);

        // Self-assignment
        v1 = v1;
        assert(v1.getSize() == 4);
        assert(v1[0] == 4);

        std::cout << "Passed: Test 15: Assignment operator\n";
    }

    // Test 16: Equality and inequality operators
    {
        int arr1[] = { 1, 2, 3 };
        int arr2[] = { 1, 2, 3 };
        int arr3[] = { 1, 2, 4 };
        int arr4[] = { 1, 2 };

        MyVector v1(arr1, 3);
        MyVector v2(arr2, 3);
        MyVector v3(arr3, 3);
        MyVector v4(arr4, 2);

        assert(v1 == v2);
        assert(!(v1 == v3));
        assert(!(v1 == v4));

        assert(v1 != v3);
        assert(v1 != v4);
        assert(!(v1 != v2));

        std::cout << "Passed: Test 16: Equality and inequality operators\n";
    }

    // Test 17: At method
    {
        int arr[] = { 10, 20, 30 };
        MyVector v(arr, 3);

        assert(v.at(0) == 10);
        assert(v.at(1) == 20);
        assert(v.at(2) == 30);

        // Test const version
        const MyVector& const_v = v;
        assert(const_v.at(0) == 10);
        assert(const_v.at(1) == 20);
        assert(const_v.at(2) == 30);

        std::cout << "Passed: Test 17: At method\n";
    }

    // Test 18: Empty vector operations
    {
        MyVector v;

        assert(v.empty());
        assert(v.getSize() == 0);

        v.pop_back();
        v.clear();

        assert(v.empty());
        assert(v.getSize() == 0);

        std::cout << "Passed: Test 18 passed: Empty vector operations\n";
    }

    std::cout << "All done!" << std::endl;
}

int main()
{
    testMyVector();

    return 0;
}