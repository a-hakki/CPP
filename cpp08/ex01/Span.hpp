#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>



class Span {
    private:
        std::vector<int> _N;
        unsigned int _Limit_N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span & operator=(const Span &other);

        void addNumber(int N);
        int shortestSpan();
        int longestSpan();

        void print();

        ~Span();
};

#endif //SPAN_HPP