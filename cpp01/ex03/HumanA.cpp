
#include "HumanA.hpp"


HumanA::HumanA(str n, Weapon &w) :
    weapon(w), name(n)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
    std::cout   << this->name
                << " attacks with their "
                << this->weapon.getType()
                << std::endl;
}
