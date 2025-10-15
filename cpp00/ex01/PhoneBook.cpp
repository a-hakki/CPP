#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
    : current_index(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact()
{
    str line[5];
    str word[5] =
    {
        "first name     : ",
        "last name      : ",
        "nickname       : ",
        "phone number   : ",
        "darkest secret : "
    };
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter your " << word[i];
        std::getline(std::cin, line[i]);
        if (line[i].empty())
        {
            std::cout << "phonebook : Contact can't have empty fields" << std::endl;
            return ;
        }
    }
    this->contact[current_index % 8].set_first(line[0]);
    this->contact[current_index % 8].set_last(line[1]);
    this->contact[current_index % 8].set_nick(line[2]);
    this->contact[current_index % 8].set_phone(line[3]);
    this->contact[current_index % 8].set_secret(line[4]);
    current_index++;
}

void PhoneBook::search_contac()
{
    std::cout << this->contact[0].get_first();
}
