#include <iostream>

typedef std::string str;

int main()
{
	str string = "HI THIS IS BRAIN";
	str	*stringPTR = &string;
	str	&stringREF = string;

	std::cout << "This is the memory address of the string variable: " << &string << std::endl;
	std::cout << "This is the memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "This is the memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string is : " << string << std::endl;
	std::cout << "The value pointed to by stringPTR is : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is : " << stringREF << std::endl;

    return (0);
}