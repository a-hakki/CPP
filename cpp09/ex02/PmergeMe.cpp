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

std::vector<int> PmergeMe::mergeInsertion(std::vector<int> input)
{
    if (input.size() <= 1)
        return input;

    std::vector<std::pair<int,int> > pairs;
    int leftover = -1;

    // 1. Create pairs
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];

        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    // 2. Save odd element
    if (input.size() % 2)
        leftover = input.back();

    // 3. Extract big values
    std::vector<int> big;
    for (size_t i = 0; i < pairs.size(); i++)
        big.push_back(pairs[i].second);

    // 4. Recursive sort
    big = mergeInsertion(big);

    // 5. Rebuild pairs according to sorted big values
    

    // 6. Build main chain
    // TODO

    // 7. Insert pending using Jacobsthal order
    // TODO

    // 8. Insert leftover
    // TODO

    return input;
}

PmergeMe::PmergeMe()
{
}

void PmergeMe::add(std::string s)
{
    int n;
    std::stringstream ss(s);
    ss >> n;
    this->vec.push_back(n);
    this->deq.push_back(n);
}

void PmergeMe::sort_vector()
{
    this->vec = mergeInsertion(this->vec);
}
void PmergeMe::sort_deque()
{
    this->deq = mergeInsertion(this->deq);
}

PmergeMe::~PmergeMe()
{
}