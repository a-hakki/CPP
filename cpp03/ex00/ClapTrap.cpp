#include "ClapTrap.hpp"

ClapTrap::ClapTrap(str N)
    : Name(N), Hit (10), Energy(10), Attack(0);
{
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    // TODO: insert return statement here
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string &target)
{
}

void ClapTrap::takeDamage(unsigned int amount)
{
}

void ClapTrap::beRepaired(unsigned int amount)
{
}

~ClapTrap::Clap
