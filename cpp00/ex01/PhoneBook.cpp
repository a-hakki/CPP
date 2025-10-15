#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
    : current_index(0), number_of_contact(0)
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
    int i = this->current_index;
    this->contact[i % 8].set_first(line[0]);
    this->contact[i % 8].set_last(line[1]);
    this->contact[i % 8].set_nick(line[2]);
    this->contact[i % 8].set_phone(line[3]);
    this->contact[i % 8].set_secret(line[4]);
    this->current_index++;
    if (this->number_of_contact < 8)
        this->number_of_contact++;
}

void PhoneBook::search_contac()
{
    int index;
    str first;
    str last;
    str nick;
    str phone;
    str secret;

    std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < this->number_of_contact ; i++)
    {
        first = this->contact[i].get_first();
        last = this->contact[i].get_last();
        nick = this->contact[i].get_nick();
        phone = this->contact[i].get_phone();
        secret = this->contact[i].get_secret();
        if (first.length() > 9)
			first = first.substr(0, 9) + ".";
		if (last.length() > 9)
			last = last.substr(0, 9) + ".";
		if (nick.length() > 9)
			nick = nick.substr(0, 9) + ".";
        std::cout << std::setw(10) << i ;
        std::cout << "|" << std::setw(10) << first ;
        std::cout << "|" << std::setw(10) << last ;
        std::cout << "|" << std::setw(10) << nick << std:: endl;
    }

    std::cout << "Enter the index of the contact to display: ";
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= this->number_of_contact) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::cout << "First name     : " << this->contact[index].get_first() << std::endl;
    std::cout << "Last name      : " << this->contact[index].get_last() << std::endl;
    std::cout << "Nickname       : " << this->contact[index].get_nick() << std::endl;
    std::cout << "Phone number   : " << this->contact[index].get_phone() << std::endl;
    std::cout << "Darkest secret : " << this->contact[index].get_secret() << std::endl;
    return ;
}
