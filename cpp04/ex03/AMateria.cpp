#include "AMateria.hpp"

AMateria::AMateria()
    : type("default")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const str &type)
    : type(type)
{
    std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "copy constructor called" << std::endl;
    this->type = other.getType();
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.getType();
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor called" << std::endl;
}

str const &AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter &target)
{
}
