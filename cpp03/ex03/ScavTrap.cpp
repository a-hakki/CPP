#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("default")
{
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 20;
    std::cout << "ScavTrap " << this->Name << " created." << std::endl;
}

ScavTrap::ScavTrap(std::string Name)
    : ClapTrap(Name)
{
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 20;
    std::cout << "ScavTrap " << this->Name << " created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap " << this->Name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->Name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        this->Energy--;
        std::cout << "ScavTrap " << this->Name << " attacks " << target << "."<< std::endl;
    }
    else if (this->Hit <= 0)
        std::cout << "ScavTrap " << this->Name << " is dead and cannot attack." << std::endl;
    else
        std::cout << "ScavTrap " << this->Name << " has no energy to attack." << std::endl;
}

void ScavTrap::guardGate()
{
    if (this->Hit > 0)
        std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode." << std::endl;
    else
        std::cout << "ScavTrap " << this->Name << " is dead and cannot enter Gate keeper mode." << std::endl;
}
