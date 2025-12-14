#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
: WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow 😼" << std::endl;
}
