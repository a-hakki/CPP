#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <cmath>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}

ScalarConverter::~ScalarConverter()
{
}

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

int count_char(const std::string &str, char c)
{
    int count = 0;
    size_t i = 0;

    while (i < str.length())
    {
        if (str[i] == c)
            count++;
        i++;
    }
    return count;
}

bool isValidInt(const std::string &s)
{
    return (!s.empty()
        && s.find_first_not_of("0123456789") == std::string::npos);
}

bool isValidDouble(const std::string &s)
{
    return (!s.empty()
        && count_char(s, '.') == 1
        && s.find_first_not_of("0123456789.") == std::string::npos);
}

bool isValidFloat(const std::string &s)
{
    if (s.empty() || s[s.length() - 1] != 'f')
        return false;

    std::string tmp = s.substr(0, s.length() - 1);

    return (!tmp.empty()
        && count_char(tmp, '.') == 1
        && tmp.find_first_not_of("0123456789.") == std::string::npos);
}

int detectType(const std::string &input)
{
    std::string s = input;

    trim(s);

    if (s.empty())
        return -1;

    bool negative = false;

    if (s[0] == '-')
    {
        negative = true;
        s = s.substr(1);
    }

    if (isValidInt(s))
        return (negative ? NINT : INT);

    if (isValidDouble(s))
        return (negative ? NDOUBLE : DOUBLE);

    if (isValidFloat(s))
        return (negative ? NFLOAT : FLOAT);

    return -1;
}

bool parseDouble(const std::string &str, double &value)
{
    std::istringstream iss(str);

    if (!(iss >> value) || !iss.eof())
        return false;

    if (std::isinf(value) || std::isnan(value))
        return false;

    return true;
}

void printChar(double value)
{
    std::cout << "char: ";

    if (value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<unsigned char>(value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";
}

void printInt(double value)
{
    std::cout << "int: ";

    if (value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";
}

void printFloat(double value)
{
    std::cout << "float: ";

    if (value < -std::numeric_limits<float>::max()
        || value > std::numeric_limits<float>::max())
        std::cout << "impossible\n";
    else
        std::cout << std::fixed << std::setprecision(1)
                  << static_cast<float>(value) << "f\n";
}

void printDouble(double value)
{
    std::cout << "double: ";

    std::cout << std::fixed << std::setprecision(1)
              << value << "\n";
}

void ScalarConverter::convert(const std::string &string)
{
    int type;
    double value;
    std::string input = string;

    trim(input);

    if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return;
    }

    if (input == "+inf" || input == "+inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
        return;
    }

    if (input == "-inf" || input == "-inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
        return;
    }

    if (input.length() == 1 && !std::isdigit(input[0]))
        type = CHAR;
    else
        type = detectType(input);

    switch (type)
    {
        case CHAR:
            value = static_cast<double>(input[0]);
            break;

        case FLOAT:
        case NFLOAT:
        {
            std::string tmp = input;

            tmp.erase(tmp.length() - 1);

            if (!parseDouble(tmp, value))
            {
                std::cerr << "Invalid input\n";
                return;
            }
            break;
        }

        case INT:
        case NINT:
        case DOUBLE:
        case NDOUBLE:
        {
            if (!parseDouble(input, value))
            {
                std::cerr << "Invalid input\n";
                return;
            }
            break;
        }

        default:
            std::cerr << "Invalid input\n";
            return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}