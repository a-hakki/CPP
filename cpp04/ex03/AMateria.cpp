#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
    : type("default")
{
}

AMateria::AMateria(const std::string &type)
    : type(type)
{
}

AMateria::AMateria(const AMateria &other)
    : type(other.type)
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}
