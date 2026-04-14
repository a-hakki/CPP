#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; i++)
    {
        Base *instance = generate();

        std::cout << "identify(Base*): ";
        identify(instance);
        std::cout << "identify(Base&): ";
        identify(*instance);
        std::cout << std::endl;
        delete instance;
    }
    return 0;
}