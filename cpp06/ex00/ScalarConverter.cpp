#include "ScalarConverter.hpp"

void trim(std::string &s)
{
    size_t start = 0;
    while (start < s.length() && std::isspace(s[start]))
        start++;

    size_t end = s.length();
    while (end > start && std::isspace(s[end - 1]))
        end--;

    s = s.substr(start, end - start);
}

void ScalarConverter::convert(const str &string)
{
    str s = string;
    if (s.length() > 1)
        trim(s);
     

    // printChar
    // printInt
    // printfloat
    // printdouble
}