
#include "HumanB.hpp"


HumanB::HumanB(str n) :
    weapon(0), name(n)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
    if (weapon)
    {
        std::cout   << this->name
                    << " attacks with their "
                    << this->weapon->getType()
                    << std::endl;
    }
    else
        std::cout << name << " has no weapon to attack!" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
