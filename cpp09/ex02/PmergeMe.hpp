#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <deque>

class PmergeMe
{
    private:
        std::vector<std::vector<int> > vec;
        std::deque<std::deque<int> > deq;
    public:
        PmergeMe();
        void add(std::string s);
        void sort_vector();
        void sort_deque();
        ~PmergeMe();
};



#endif //PMERGEME_HPP