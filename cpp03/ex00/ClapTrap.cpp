#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : Name("default"), Hit (10), Energy(10), Attack(0)
{
    std::cout << "ClapTrap " << this->Name << " created." << std::endl;
}

ClapTrap::ClapTrap(str N)
    : Name(N), Hit (10), Energy(10), Attack(0)
{
    std::cout << "ClapTrap " << this->Name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "copy constructor called" << std::endl;
    this->Name = other.Name;
    this->Hit = other.Hit;
    this->Energy = other.Energy;
    this->Attack = other.Attack;
    return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->Name = other.Name;
        this->Hit = other.Hit;
        this->Energy = other.Energy;
        this->Attack = other.Attack;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->Name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        this->Energy--;
        std::cout << "ClapTrap " << this->Name << " attacks " << target << std::endl;
    }
    else if (this->Hit <= 0)
        std::cout << "ClapTrap " << this->Name << " is dead and cannot attack." << std::endl;
    else
        std::cout << "ClapTrap " << this->Name << " has no energy to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->Hit <= 0)
        std::cout << "ClapTrap" << this->Name << " is already death!." << std::endl;
    else
    {
        this->Hit -= amount;
        if (this->Hit < 0)
            this->Hit = 0;
        std::cout << "ClapTrap " << this->Name << " takes " << amount << " points of damage! Remaining hit points: " << this->Hit << std::endl;
        if (this->Hit <= 0)
            std::cout << "ClapTrap" << this->Name << " is died" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "beRepaired called for" << this->Name << std::endl;
    if (this->Energy > 0 && this->Hit > 0)
    {
        this->Energy--;
        this->Hit += amount;
        std::cout << "ClapTrap " << this->Name << " is repaired by " << amount << " points! Current hit points: " << this->Hit << std::endl;
    }
    else if (this->Hit <= 0)
        std::cout << "ClapTrap " << this->Name << " is dead and cannot be repaired." << std::endl;
    else
        std::cout << "ClapTrap " << this->Name << " has no energy to repair." << std::endl;
}

