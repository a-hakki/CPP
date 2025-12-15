#include "Character.hpp"
#include <iostream>

Character::Character()
    : name("default"), floorCount(0)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = 0;
    for (int i = 0; i < 1000; i++)
        this->floor[i] = 0;
}

Character::Character(const std::string &name)
    : name(name), floorCount(0)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = 0;
    for (int i = 0; i < 1000; i++)
        this->floor[i] = 0;
}

Character::Character(const Character& other)
    : name(other.name), floorCount(0)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = 0;
    for (int i = 0; i < 1000; i++)
        this->floor[i] = 0;
    copyInventory(other);
} 

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        clearInventory();
        copyInventory(other);
    }
    return *this;
}

Character::~Character()
{
    clearInventory();
    for (int i = 0; i < floorCount; i++)
        delete floor[i];
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx] && floorCount < 1000)
    {
        floor[floorCount++] = inventory[idx];
        inventory[idx] = 0;
        return;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx])
        inventory[idx]->use(target);
}

void Character::clearInventory()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        inventory[i] = 0;
    }
}

void Character::copyInventory(const Character& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}
