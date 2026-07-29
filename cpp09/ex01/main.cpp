#include "RPN.hpp"


void trim(std::string& str){
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        str = "";
        return;
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    str = str.substr(first, (last - first + 1));
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "ERROR"<<std::endl, 1);
    if (!av[1][0])
        return (std::cerr << "ERROR"<<std::endl, 1);
    std::string str(av[1]);
    trim(str);
    if (str.empty())
        return (std::cerr << "ERROR"<<std::endl, 1);    
    RPN rpn(str);
    return (0);
}