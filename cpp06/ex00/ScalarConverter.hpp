#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

typedef std::string str;

class ScalarConverter 
{
    private:
        ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &);
        ScalarConverter(const ScalarConverter &);
        ~ScalarConverter();

    public:
        static void convert(const str &s);
};



#endif //SCALARCONVERTER_HPP
