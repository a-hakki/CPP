#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("default")
{
    this->Hit = 100;
    this->Energy = 100;
    this->Attack = 30;
    std::cout << "FragTrap " << this->Name << " created." << std::endl;
}

FragTrap::FragTrap(std::string Name)
    : ClapTrap(Name)
{
    this->Hit = 100;
    this->Energy = 100;
    this->Attack = 30;
    std::cout << "FragTrap " << this->Name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other)
{
    std::cout << "FragTrap " << this->Name << " copied." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->Name << " destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->Hit > 0)
        std::cout << "FragTrap " << this->Name << " highFivesGuys !!" << std::endl;
    else
        std::cout << this->Name <<" can't do a highFives because He's dead already" << std::endl;
}
