# include "PmergeMe.hpp"





int main(int ac, char **av)
{
    if (ac < 2)
        return std::cerr << "Error" << std::endl, 1;
    size_t i = 1;

    PmergeMe p;

    while (av[i])
    {
        // validation the argument
        std::string temp(av[i]);
        if (!temp.find_first_not_of("0123456789"))
            return std::cerr << "Error" << std::endl, 1;
        
        // fill the containers
        
        p.add(std::string(av[i]));
        i++;
    }
    p.sort_vector();
    p.sort_deque();

    
    return 0;
}