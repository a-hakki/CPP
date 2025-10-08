#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int j, i = 1;
        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                std::cout<<(char)std::toupper(av[i][j]);
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
}