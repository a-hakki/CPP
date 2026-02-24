#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>

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

int detectType(std::string &trimmed)
{
    trim(trimmed);
    if (trimmed.empty())
        return -1;
    if (trimmed.find_first_not_of("0123456789") == std::string::npos)
        return INT;
    if (trimmed.find_first_not_of("0123456789.") == std::string::npos)
        return DOUBLE;
    if (trimmed.find_first_not_of("0123456789.f") == std::string::npos)
        return FLOAT;
    return -1;
}

void ScalarConverter::convert(const std::string &string)
{
    std::string trimmed = string;
    int t;

    if (string == "nan" || string == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << string << "f\n";
        std::cout << "double: " << string << "\n";
        return;
    }
    if (string.length() == 1 && !std::isdigit(string[0]))
        t = CHAR;
    else
        t = detectType(trimmed);
    switch (t)
    {
        case CHAR:
            {
                if (!std::isprint(string[0]))
                {
                    std::cerr << "Non displayable character\n";
                    return;
                }
                std::cout << "char: '" << string[0] << "'\n";
                std::cout << "int: " << static_cast<int>(string[0]) << "\n";
                std::cout << "float: " << static_cast<float>(string[0]) << ".0f\n";
                std::cout << "double: " << static_cast<double>(string[0]) << ".0\n";
            }
            break;
        case INT:
            {
                int value;
                std::istringstream iss(trimmed);
                iss >> value;
                std::cout << "char: " << (value >= 0 && value <= 127 && std::isprint(static_cast<unsigned char>(value)) ? std::string("'") + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << "\n";
                std::cout << "int: " << value << "\n";
                std::cout << "float: " << static_cast<float>(value) << ".0f\n";
                std::cout << "double: " << static_cast<double>(value) << ".0\n";
            }
            break;
        case FLOAT:
            {
                float value;
                std::istringstream iss(trimmed);
                iss >> value;
                int intVal = static_cast<int>(value);
                std::cout << "char: " << (intVal >= 0 && intVal <= 127 && std::isprint(static_cast<unsigned char>(intVal)) ? std::string("'") + std::string(1, static_cast<char>(intVal)) + "'" : "Non displayable") << "\n";
                std::cout << "int: " << static_cast<int>(value) << "\n";
                std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f\n";
                std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << "\n";
            }
            break;
        case DOUBLE:
            {
                double value;
                std::istringstream iss(trimmed);
                iss >> value;
                int intVal = static_cast<int>(value);
                std::cout << "char: " << (intVal >= 0 && intVal <= 127 && std::isprint(static_cast<unsigned char>(intVal)) ? std::string("'") + std::string(1, static_cast<char>(intVal)) + "'" : "Non displayable") << "\n";
                std::cout << "int: " << static_cast<int>(value) << "\n";
                std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
                std::cout << "double: " << std::fixed << std::setprecision(1) << value << "\n";
            }
            break;
        default:
            std::cerr << "Invalid input\n";
    }
}