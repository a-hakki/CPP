
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap("CL4P-TP");
	ScavTrap scav("SC4V-TP");
	FragTrap frag("FR4G-TP");

	clap.attack("a random target");
	scav.attack("CL4P-TP");
	frag.attack("CL4P-TP");

	clap.takeDamage(5);
	scav.takeDamage(5);
	frag.takeDamage(5);
	clap.beRepaired(3);

	scav.guardGate();
	frag.highFivesGuys();

	ClapTrap copy = clap;
	copy.attack("copied target");

	return 0;
}