#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "=== Test 1: Empty array ===" << std::endl;
    ARRAY<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    std::cout << "\n=== Test 2: Sized array ===" << std::endl;
    ARRAY<int> arr(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    std::cout << "Array size: " << arr.size() << std::endl;
    std::cout << "arr[0] = " << arr[0] << std::endl;
    std::cout << "arr[1] = " << arr[1] << std::endl;
    std::cout << "arr[2] = " << arr[2] << std::endl;

    std::cout << "\n=== Test 3: Deep copy independence ===" << std::endl;
    ARRAY<int> original(2);
    original[0] = 10;
    original[1] = 20;
    ARRAY<int> copy(original);
    copy[0] = 999;
    std::cout << "Original[0]: " << original[0] << " (should be 10)" << std::endl;
    std::cout << "Copy[0]: " << copy[0] << " (should be 999)" << std::endl;

    std::cout << "\n=== Test 4: Assignment independence ===" << std::endl;
    ARRAY<int> source(2);
    source[0] = 100;
    source[1] = 200;
    ARRAY<int> dest;
    dest = source;
    dest[0] = 555;
    std::cout << "Source[0]: " << source[0] << " (should be 100)" << std::endl;
    std::cout << "Dest[0]: " << dest[0] << " (should be 555)" << std::endl;

    std::cout << "\n=== Test 5: Bounds checking ===" << std::endl;
    try {
        arr[100] = 5;
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught exception (expected): " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Out of bounds read ===" << std::endl;
    try {
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
        int val = arr[10];
        std::cout << "Retrieved value: " << val << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught exception (expected): " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: String array ===" << std::endl;
    ARRAY<std::string> strings(2);
    strings[0] = "Hello";
    strings[1] = "World";
    std::cout << "strings[0]: " << strings[0] << std::endl;
    std::cout << "strings[1]: " << strings[1] << std::endl;

    std::cout << "\n=== Test 8: const access ===" << std::endl;
    const ARRAY<int> const_arr(2);
    std::cout << "const_arr[0]: " << const_arr[0] << std::endl;
    // const_arr[0] = 5; // This should cause a compilation error

    return (0);
}