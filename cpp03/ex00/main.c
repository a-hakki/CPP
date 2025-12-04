#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct1("CT-One");
    ClapTrap ct2("CT-Two");

    ct1.attack("CT-Two");
    ct2.takeDamage(5);
    ct2.beRepaired(3);
    ct2.attack("CT-One");
    ct1.takeDamage(12);
    ct1.beRepaired(5);

    return 0;
}