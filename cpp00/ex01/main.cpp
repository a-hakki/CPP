#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.hpp"

using namespace std;
int main()
{
    PhoneBook	phonebook;
	str			line;
	const str	ADD = "ADD";
	const str   SEARCH = "SEARCH";
	const str   EXIT = "EXIT";

	std::cout << "Hey..., Well this is your contact manager!" << std::endl;
    std::cout << "Commands list -> ADD, SEARCH or EXIT!" << std:: endl;
    while (std::getline(std::cin, line))
    {
        if (line == ADD)
            phonebook.add_contact();
        else if (line == SEARCH)
            phonebook.search_contac();
        else if (line == EXIT)
            break;
        std::cout << "Commands list -> ADD, SEARCH or EXIT!" << std:: endl;
    }
    return (0);
}