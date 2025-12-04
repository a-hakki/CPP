#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Guardian");
    scav.attack("Intruder");
    scav.takeDamage(30);
    scav.guardGate();
    scav.takeDamage(70);
    scav.guardGate();
    return 0;
}