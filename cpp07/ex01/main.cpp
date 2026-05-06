#include "iter.hpp"


void foo1(const int &i)
{
    std::cout<<i<< std::endl;
}

int main()
{
    
    const int arr[3] = {5, 6, 18};
    iter(arr, 3, foo1);

    for (size_t i = 0; i < 3; i++)
    {
        std::cout<<arr[i]<< std::endl;
    }
    

}