# include "PmergeMe.hpp"


void fill_d(std::deque<t_it_d> &it,const PmergeMe &p)
{
    for (size_t i = 0; i < p.get_deq().size(); i++)
    {
        it.push_back(t_it_d(p.get_deq()[i]));
    }
}
void fill_v(std::vector<t_it_v> &it,const PmergeMe &p)
{
    for (size_t i = 0; i < p.get_deq().size(); i++)
    {
        it.push_back(t_it_v(p.get_deq()[i]));
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

        struct timeval start, end;
        long long time_deque, time_vector;

        gettimeofday(&start, NULL);
        p.sort_deque(it_d);
        gettimeofday(&end, NULL);
        time_deque = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);

        gettimeofday(&start, NULL);
        p.sort_vector(it_v);
        gettimeofday(&end, NULL);
        time_vector = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);


        std::cout << "After:  ";
        for (size_t i = 0; i < num_elements; i++)
            std::cout << it_d[i].value << (i + 1 < num_elements ? " " : "");
        std::cout << std::endl;


        std::cout << "Time to process a range of " << num_elements 
                  << " elements with std::deque : " << time_deque << " us" << std::endl;

        std::cout << "Time to process a range of " << num_elements 
                  << " elements with std::vector : " << time_vector << " us" << std::endl;

    }
    catch (const std::exception &)
    {
        return std::cerr << "Error" << std::endl, 1;
    }
    return 0;
}