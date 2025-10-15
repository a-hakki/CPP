#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.hpp"

int main()
{
    PhoneBook	phonebook;
	str			line;
	const str	ADD = "ADD";
	const str   SEARCH = "SEARCH";
	const str   EXIT = "EXIT";

	std::cout << "Hey..., Well this is your contact manager!" << std::endl;
    while (std::getline(std::cin, line))
    {
        if (line == ADD)
            phonebook.add_contact();
        else if (line == SEARCH)
            phonebook.search_contac();
        else if (line == EXIT)
            break;
    }
    return (0);
}