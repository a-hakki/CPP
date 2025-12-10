
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "=== Test 1: Create DiamondTrap ===" << std::endl;
	DiamondTrap diamond("DT4P");

	std::cout << "\n=== Test 2: whoAmI() ===" << std::endl;
	diamond.whoAmI();

	std::cout << "\n=== Test 3: Attack (from ScavTrap) ===" << std::endl;
	diamond.attack("CL4P-TP");
	diamond.attack("CL4P-TP");

	std::cout << "\n=== Test 4: Guard Gate (from ScavTrap) ===" << std::endl;
	diamond.guardGate();

	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}