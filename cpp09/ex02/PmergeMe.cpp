#include "PmergeMe.hpp"

#include <climits>
#include <cctype>
#include <stdexcept>

static size_t jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    size_t prev2 = 0;
    size_t prev1 = 1;
    for (size_t i = 2; i <= n; ++i)
    {
        size_t current = prev1 + (2 * prev2);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}

static std::vector<size_t> build_insertion_order(size_t count)
{
    std::vector<size_t> order;
    if (count == 0)
        return order;

    order.push_back(0);
    size_t previous_jacob = 1;
    size_t jacob_index = 3;
    while (order.size() < count)
    {
        size_t current_jacob = jacobsthal(jacob_index);
        if (current_jacob > count)
            current_jacob = count;
        for (size_t i = current_jacob; i > previous_jacob && order.size() < count; --i)
            order.push_back(i - 1);
        previous_jacob = current_jacob;
        ++jacob_index;
    }
    return order;
}

template <typename Container>
static void insert_sorted(Container &container, int value)
{
    typename Container::iterator position = std::lower_bound(container.begin(), container.end(), value);
    container.insert(position, value);
}

template <typename Container>
static void ford_johnson_sort(Container &values)
{
    if (values.size() <= 1)
        return;

    Container main_chain;
    std::vector<int> pending;
    bool has_odd = (values.size() % 2) != 0;
    int odd_value = 0;

    for (size_t i = 0; i + 1 < values.size(); i += 2)
    {
        int first = values[i];
        int second = values[i + 1];
        if (first < second)
        {
            main_chain.push_back(second);
            pending.push_back(first);
        }
        else
        {
            main_chain.push_back(first);
            pending.push_back(second);
        }
    }
    if (has_odd)
        odd_value = values[values.size() - 1];

    ford_johnson_sort(main_chain);

    std::vector<size_t> order = build_insertion_order(pending.size());
    for (size_t i = 0; i < order.size(); ++i)
        insert_sorted(main_chain, pending[order[i]]);
    if (has_odd)
        insert_sorted(main_chain, odd_value);

    values.swap(main_chain);
}

PmergeMe::PmergeMe()
    : vec(1), deq(1)
{
}

void PmergeMe::add(std::string s)
{
    if (s.empty())
        throw std::invalid_argument("invalid input");

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            throw std::invalid_argument("invalid input");
    }

    long long n;
    std::stringstream ss(s);
    char remaining;
    if (!(ss >> n) || (ss >> remaining) || n < 0 || n > INT_MAX)
        throw std::invalid_argument("invalid input");

    if (this->vec.empty())
        this->vec.push_back(std::vector<int>());
    if (this->deq.empty())
        this->deq.push_back(std::deque<int>());

    this->vec[0].push_back(static_cast<int>(n));
    this->deq[0].push_back(static_cast<int>(n));
}

void PmergeMe::sort_vector()
{
    if (this->vec.empty() || this->vec[0].size() <= 1)
        return;
    ford_johnson_sort(this->vec[0]);
}

void PmergeMe::sort_deque()
{
    if (this->deq.empty() || this->deq[0].size() <= 1)
        return;
    ford_johnson_sort(this->deq[0]);
}

PmergeMe::~PmergeMe()
{
}
