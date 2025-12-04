#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string Name)
    : ClapTrap(Name + "_clap_name"), ScavTrap(Name), FragTrap(Name), Name(Name)
{
    this->Hit = FragTrap::Hit;
    this->Energy = ScavTrap::Energy;
    this->Attack = FragTrap::Attack;
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



