#include "RPN.hpp"

int    is_operator(char c)
{
int n = 0;
    switch (c) {
        case A: n = A; break;
        case S: n = S; break;
        case M: n = M; break;
        case D: n = D; break;
    }
    return n;
}

void error()
{
    std::cerr << "Error " <<std::endl;
    exit(1);
}

RPN::RPN()
{
}

RPN::RPN(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            this->st.push(str[i] - '0');
        else if (is_operator(str[i]))
            calculate(str[i]);
        else if (str[i] != ' ')
            error();
    }
    if (this->st.size() > 1)
        error();
    std::cout << this->st.top() << std::endl;
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->st = other.st;
    return *this;
}

void RPN::pop()
{
    if (this->st.empty())
        error();
    this->st.pop();
}

void RPN::calculate(char op)
{
    if (this->st.size() < 2)
        error();
    int n = this->st.top();
    this->pop();
    if (op == A)
    {
        n = this->st.top() + n;
    }
    else if (op == S)
        n = this->st.top() - n;
    else if (op == M)
        n = this->st.top() * n;
    else if (op == D && n != 0)
        n = this->st.top() / n;
    else
        error();
    this->pop();
    this->st.push(n);
    return ;
}

RPN::~RPN()
{
}