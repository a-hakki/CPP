
#include "Weapon.hpp"

Weapon::Weapon(str name) : type(name)
{
}

Weapon::~Weapon()
{
}

const str &Weapon::getType() const
{
    return this->type;
}

void Weapon::setType(str type)
{
    this->type = type;
}
