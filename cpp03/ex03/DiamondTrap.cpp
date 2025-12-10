#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string Name)
    : ClapTrap(Name), ScavTrap(Name), FragTrap(Name), Name(Name + "_clap_name")
{
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 30;
    std::cout << "DiamondTrap " << this->Name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    *this = other;
    std::cout << "DiamondTrap " << this->Name << " copied." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->Name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->Name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}


