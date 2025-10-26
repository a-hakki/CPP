#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    std::cout << "A new zombie was created" << std::endl;
}

void Zombie::set_name(str name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->name << " was destroyed!" << std::endl;
}

