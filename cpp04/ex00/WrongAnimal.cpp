#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : type("WrongAnimal")
{
    std::cout << "Animal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = other.type;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}