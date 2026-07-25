#ifndef RPN_HPP 
# define RPN_HPP

# include <iostream> 
# include <stack>
# include <algorithm>
# include <cctype>

enum    operations{
        A = '+',
        S = '-',
        M = '*',
        D = '/'
};

class RPN
{
    private:
        std::stack<int> st;
    public:
        RPN();
        RPN(std::string str);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        void pop();
        void calculate(char op);

        ~RPN();
};


# endif //RPN_HPP