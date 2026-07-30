# include "PmergeMe.hpp"
# include <iostream>
# include <iomanip>
# include <time.h>

void fill_v(std::vector<t_it_v> &it, const PmergeMe &p)
{
    for (size_t i = 0; i < p.get_deq().size(); i++)
    {
        t_it_v new_val = t_it_v(p.get_deq()[i]);
        it.push_back(new_val);
    }
}

void fill_d(std::deque<t_it_d> &it, const PmergeMe &p)
{
    for (size_t i = 0; i < p.get_deq().size(); i++)
    {
        t_it_d new_val = t_it_d(p.get_deq()[i]);
        it.push_back(new_val);
    }
}


int main(int ac, char **av)
{
    if (ac < 2)
        return std::cerr << "Error" << std::endl, 1;
    
    try
    {
        PmergeMe p;
        for (size_t i = 1; av[i]; i++)
            p.add(std::string(av[i]));

        std::deque<t_it_d> it_d;
        std::vector<t_it_v> it_v;
        
        fill_d(it_d, p);
        fill_v(it_v, p);

        size_t num_elements = it_d.size();

        std::cout << "Before: ";
        for (size_t i = 0; i < num_elements; i++)
            std::cout << it_d[i].value << (i + 1 < num_elements ? " " : "");
        std::cout << std::endl;

        struct timespec start_d, end_d;
        clock_gettime(CLOCK_MONOTONIC, &start_d);
        p.sort_deque(it_d);
        clock_gettime(CLOCK_MONOTONIC, &end_d);

        double time_deque = (end_d.tv_sec - start_d.tv_sec) * 1000000.0 + (end_d.tv_nsec - start_d.tv_nsec) / 1000.0;

        struct timespec start_v, end_v;
        clock_gettime(CLOCK_MONOTONIC, &start_v);
        p.sort_vector(it_v);
        clock_gettime(CLOCK_MONOTONIC, &end_v);
        
        double time_vector = (end_v.tv_sec - start_v.tv_sec) * 1000000.0 + (end_v.tv_nsec - start_v.tv_nsec) / 1000.0;

 
        std::cout << "After:  ";
        for (size_t i = 0; i < it_d.size(); i++) {
            std::cout << it_d[i].value << (i + 1 < it_d.size() ? " " : "");
        }
        std::cout << std::endl;
        
        std::cout << "Time to process a range of " << num_elements << " elements with std::deque  : " 
                  << std::fixed << std::setprecision(5) << time_deque << " us" << std::endl;

        std::cout << "Time to process a range of " << num_elements << " elements with std::vector : " 
                  << std::fixed << std::setprecision(5) << time_vector << " us" << std::endl;

    }
    catch (const std::exception &)
    {
        return std::cerr << "Error" << std::endl, 1;
    }
    return 0;
}