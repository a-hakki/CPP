#include "PmergeMe.hpp"


int js(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return (js(n - 1) + (2 * js(n - 2)));
}

std::vector<int> generator(int n)
{
    std::vector<int> temp;

    int next;
    int current = 0;
    int i = 1;

    while (i <= n) {
        next = js(i);
        if (next >= n)
            next = n;
        for (int j = next - 1; j >= current; j--) {
            temp.push_back(j);
        }
        if (next == n)
            break;

        i++;
        current = next;
    }
    return temp;
}

PmergeMe::PmergeMe()
    : vec(0)
{
}

void PmergeMe::add(std::string s)
{
    int n;
    std::stringstream ss(s);
    ss >> n;
    this->vec[0].push_back(n);
    this->deq[0].push_back(n);
}

void PmergeMe::sort_vector()
{

    if (this->vec[0].size() == 1)
        return ;
    std::cout<< " vect size : " << this->vec.size() << std::endl;
    for (size_t i = 0; i < this->vec.size(); i+=2)
    {
        big.push_back(std::max(vec[i], vec[i + 1]));
        small.push_back(std::min(vec[i], vec[i + 1]));
    }
    if (this->vec.size() % 2)
        left = vec[this->vec.size() - 1];
    temp = big;
    this->vec = big;
    sort_vector();

    size_t len = small.size();

    return ;
}

void PmergeMe::sort_deque()
{
}

PmergeMe::~PmergeMe()
{
}