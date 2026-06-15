#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
    try {
        std::cout << "-- Basic example --" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.print();
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;

        std::cout << "\n-- Overflow test --" << std::endl;
        try {
            sp.addNumber(42);
        } catch (const std::overflow_error &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "\n-- Small-span exceptions --" << std::endl;
        try {
            Span empty(10);
            empty.shortestSpan();
        } catch (const std::invalid_argument &e) {
            std::cout << "Expected exception (empty): " << e.what() << std::endl;
        }
        try {
            Span one(10);
            one.addNumber(1);
            one.longestSpan();
        } catch (const std::invalid_argument &e) {
            std::cout << "Expected exception (one element): " << e.what() << std::endl;
        }

        std::cout << "\n-- Large test (10k) --" << std::endl;
        const unsigned int SZ = 10000;
        Span big(SZ);
        std::vector<int> nums;
        nums.reserve(SZ);
        for (int i = 0; i < (int)SZ; ++i)
            nums.push_back(i);
        std::srand(42);
        std::random_shuffle(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i)
            big.addNumber(nums[i]);
        std::cout << "big.shortestSpan(): " << big.shortestSpan() << std::endl;
        std::cout << "big.longestSpan():  " << big.longestSpan() << std::endl;

        std::cout << "\n-- Copy / assignment --" << std::endl;
        Span copy = big;
        std::cout << "copy.longestSpan(): " << copy.longestSpan() << std::endl;
        Span assigned(1);
        assigned = big;
        std::cout << "assigned.shortestSpan(): " << assigned.shortestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
