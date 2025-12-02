#include <iostream>
#include "Point.hpp"

int main()
{
    Point a(10, 20);
    Point b(15, 30);
    Point c(15, 20);
    Point p(15, 30);

    std::cout << std::boolalpha;
    std::cout << "Triangle vertices: " << a << ", " << b << ", " << c << std::endl;
    std::cout << "Point " << p << " belongs to the triangle? " << bsp(a, b, c, p) << std::endl;

    return 0;
}