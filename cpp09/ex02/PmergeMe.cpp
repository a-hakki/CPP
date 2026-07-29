#include "PmergeMe.hpp"

unsigned int g_comparisons = 0;

t_it_d::t_it_d(int value) : value(value) {}
t_it_d::t_it_d(int v, t_it_d p_it) : value(v) 
{
    it.push_back(p_it);
}
t_it_d::t_it_d(const t_it_d &other) : value(other.value), it(other.it) {}
t_it_d& t_it_d::operator=(const t_it_d &other) 
{
    if (this != &other)
    {
        value = other.value;
        it = other.it;
    }
    return *this;
}

t_it_v::t_it_v(int value) : value(value) {}
t_it_v::t_it_v(int v, t_it_v p_it) : value(v) 
{
    it.push_back(p_it);
}
t_it_v::t_it_v(const t_it_v &other) : value(other.value), it(other.it) {}
t_it_v& t_it_v::operator=(const t_it_v &other) 
{
    if (this != &other)
    {
        value = other.value;
        it = other.it;
    }
    return *this;
}

bool compareAndCount_d(const t_it_d &a, const t_it_d &b)
{
    g_comparisons++;
    return a.value < b.value;
}

bool compareAndCount_v(const t_it_v &a, const t_it_v &b)
{
    g_comparisons++;
    return a.value < b.value;
}

int js(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return (js(n - 1) + (2 * js(n - 2)));
}

std::deque<t_it_d> PmergeMe::mergeInsertion(std::deque<t_it_d> &input)
{
    if (input.size() <= 1)
        return input;
    
    std::deque<t_it_d> next;

    t_it_d leftover(-1);

    if (input.size() % 2)
        leftover = input.back();

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (compareAndCount_d(input[i].value, input[i + 1].value))
        {
            t_it_d bigger = input[i + 1]; 
            bigger.it.push_back(input[i]); 
            next.push_back(bigger);
        }
        else
        {
            t_it_d bigger = input[i]; 
            bigger.it.push_back(input[i + 1]);
            next.push_back(bigger);
        }
    }

    next = mergeInsertion(next);

    if (next.size() == 1)
    {
        t_it_d extracted_element = next[0].it.back();
        next[0].it.pop_back();
        next.push_front(extracted_element);
    }
    else
    {
        std::deque<t_it_d> small;
        for (size_t i = 0; i < next.size(); i++)
        {
            t_it_d extracted_element = next[i].it.back();
            next[i].it.pop_back();
            small.push_back(extracted_element);
        }
    
        next.push_front(small[0]);
        size_t prev_inserted_idx = 0;
        int k = 3;
        size_t added_count = 1;
        while (prev_inserted_idx < small.size() - 1)
        {
            size_t target_idx = js(k) - 1;

            if (target_idx >= small.size())
            {
                target_idx = small.size() - 1;
                if (leftover.value != -1)
                {
                    std::deque<t_it_d>::iterator pos = std::lower_bound(next.begin(), next.end(), leftover, compareAndCount_d);
                    next.insert(pos, leftover);
                }
            }

            for (size_t i = target_idx; i > prev_inserted_idx; i--)
            {
                std::deque<t_it_d>::iterator pos = std::lower_bound(next.begin(), next.begin() + (i + added_count), small[i], compareAndCount_d);
                next.insert(pos, small[i]);
                added_count++;
            }
            prev_inserted_idx = target_idx;
            k++;
        }

    }
    return next;
}

std::vector<t_it_v> PmergeMe::mergeInsertion(std::vector<t_it_v> &input)
{
        if (input.size() <= 1)
        return input;
    
    std::vector<t_it_v> next;

    t_it_v leftover(-1);

    if (input.size() % 2)
        leftover = input.back();

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (compareAndCount_d(input[i].value, input[i + 1].value))
        {
            t_it_v bigger = input[i + 1]; 
            bigger.it.push_back(input[i]); 
            next.push_back(bigger);
        }
        else
        {
            t_it_v bigger = input[i]; 
            bigger.it.push_back(input[i + 1]);
            next.push_back(bigger);
        }
    }

    next = mergeInsertion(next);

    if (next.size() == 1)
    {
        t_it_v extracted_element = next[0].it.back();
        next[0].it.pop_back();
        next.insert(next.begin(), extracted_element);
    }
    else
    {
        std::vector<t_it_v> small;
        for (size_t i = 0; i < next.size(); i++)
        {
            t_it_v extracted_element = next[i].it.back();
            next[i].it.pop_back();
            small.push_back(extracted_element);
        }
    
        next.insert(next.begin(), small[0]);
        size_t prev_inserted_idx = 0;
        int k = 3;
        size_t added_count = 1;
        while (prev_inserted_idx < small.size() - 1)
        {
            size_t target_idx = js(k) - 1;

            if (target_idx >= small.size())
            {
                target_idx = small.size() - 1;
                if (leftover.value != -1)
                {
                    std::vector<t_it_v>::iterator pos = std::lower_bound(next.begin(), next.end(), leftover, compareAndCount_v);
                    next.insert(pos, leftover);
                }
            }

            for (size_t i = target_idx; i > prev_inserted_idx; i--)
            {
                std::vector<t_it_v>::iterator pos = std::lower_bound(next.begin(), next.begin() + (i + added_count), small[i], compareAndCount_v);
                next.insert(pos, small[i]);
                added_count++;
            }
            prev_inserted_idx = target_idx;
            k++;
        }

    }
    return next;
}

PmergeMe::PmergeMe()
{
}

std::deque<int> PmergeMe::get_deq() const
{
    return this->deq;
}

std::vector<int> PmergeMe::get_vec() const
{
    return this->vec;
}

void PmergeMe::add(std::string s)
{
    int n;
    std::stringstream ss(s);
    ss >> n;
    this->vec.push_back(n);
    this->deq.push_back(n);
}

std::deque<int> unfill_d(const std::deque<t_it_d> &it)
{
    std::deque<int> result;
    
    for (size_t i = 0; i < it.size(); i++)
    {
        result.push_back(it[i].value);
    }
    
    return result;
}

std::vector<int> unfill_v(const std::vector<t_it_v> &it)
{
    std::vector<int> result;
    
    for (size_t i = 0; i < it.size(); i++)
    {
        result.push_back(it[i].value);
    }
    
    return result;
}

void PmergeMe::sort_deque(std::deque<t_it_d> &it)
{
    g_comparisons = 0; // Reset before sorting
    it = mergeInsertion(it);

    // std::cout << "Total comparisons made: " << g_comparisons << std::endl;

}

void PmergeMe::sort_vector(std::vector<t_it_v> &it)
{
    g_comparisons = 0; // Reset before sorting
    it = mergeInsertion(it);
    // std::cout << "Total comparisons made: " << g_comparisons << std::endl;
}

PmergeMe::~PmergeMe()
{
}