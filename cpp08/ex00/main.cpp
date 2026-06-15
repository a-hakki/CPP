#include "easyfind.hpp"

int main()
{
    // Test with a vector of integers
    {   
        std::vector<int> vec;
        for (int i = 0; i < 10; i++)
            vec.push_back(i);
        try
        {
            std::cout << easyfind(&vec, 5) << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Not found" << std::endl;
        }
    }

    return 0;
}