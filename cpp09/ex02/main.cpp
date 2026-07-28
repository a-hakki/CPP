# include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if (ac < 2)
        return std::cerr << "Error" << std::endl, 1;
    try
    {
        size_t i = 1;
        PmergeMe p;
        while (av[i])
        {
            p.add(std::string(av[i]));
            i++;
        }
        p.sort_vector();
        p.sort_deque();
    }
    catch (const std::exception &)
    {
        return std::cerr << "Error" << std::endl, 1;
    }
    return 0;
}