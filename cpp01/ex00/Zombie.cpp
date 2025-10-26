#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(str name) : name(name)
{
}

Zombie::~Zombie()
{
    std::cout << this->name << "  was destroyed!" << std::endl;
}