#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP
# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        str Name;
    public:
        DiamondTrap(std::string Name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();

        void whoAmI();
};
#endif // DiamondTrap_HPP