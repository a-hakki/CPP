#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <sys/time.h>
# include <iostream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <deque>


struct t_it_d
{
    int                 value;
    std::deque<t_it_d>  it;

    t_it_d(int value);
    t_it_d(int value, t_it_d p_it);
    t_it_d(const t_it_d &other);
    
    // It is best practice to include the assignment operator 
    // since you use: leftover = input.back();
    t_it_d& operator=(const t_it_d &other);

    bool operator==(const t_it_d& other) const {
        return this->value == other.value;
    }
};

struct t_it_v
{
    int                 value;
    std::deque<t_it_v>  it;

    t_it_v(int value);
    t_it_v(int value, t_it_v p_it);
    t_it_v(const t_it_v &other);
    
    // It is best practice to include the assignment operator 
    // since you use: leftover = input.back();
    t_it_v& operator=(const t_it_v &other);

    bool operator==(const t_it_v& other) const {
        return this->value == other.value;
    }
};


class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;

        std::deque<t_it_d> mergeInsertion(std::deque<t_it_d> &input);
        std::vector<t_it_v> mergeInsertion(std::vector<t_it_v> &input);
        // std::deque<int> mergeInsertion();

    public:
        PmergeMe();
        std::deque<int> get_deq() const;
        std::vector<int> get_vec() const;
        void add(std::string s);
        void sort_deque(std::deque<t_it_d> &it);
        void sort_vector(std::vector<t_it_v> &it);
        ~PmergeMe();
};

#endif //PMERGEME_HP