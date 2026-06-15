#include "Span.hpp"

Span::Span()
    :_Limit_N(0)
{
}

Span::Span(unsigned int N)
    :_Limit_N(N)
{
}

Span::Span(const Span &other)
{
    this->_N = other._N;
    this->_Limit_N = other._Limit_N;
}

Span& Span::operator=(const Span &other)
{
    if (this == &other)
        return *this;
    this->_N = other._N;
    this->_Limit_N = other._Limit_N;
    return *this;
}

void Span::addNumber(int N)
{
    if (this->_N.size() == this->_Limit_N)
        throw std::overflow_error("span is full or can't be fulled");
    this->_N.push_back(N);
}

int Span::shortestSpan()
{
    if (this->_N.size() < 2)
        throw std::invalid_argument("span is too small");
    std::vector<int> tmp = this->_N;
    std::sort(tmp.begin(), tmp.end());
    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; i++)
    {
        int span = tmp[i + 1] - tmp[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (this->_N.size() < 2)
        throw std::invalid_argument("span is too small");
    std::vector<int> tmp = this->_N;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

void Span::print()
{
    for (size_t i = 0; i < this->_N.size(); i++)
    {
        std::cout<< "Span [" << i <<"] : "<< this->_N[i] << std::endl;
    }
}

Span::~Span()
{
}
