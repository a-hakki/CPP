#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "ERROR"<<std::endl, 1);
    std::string str(av[1]);
    RPN rpn(str);
    return (0);
}