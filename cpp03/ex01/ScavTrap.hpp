#ifndef ScavTrap_HPP
# define ScavTrap_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string Name);
        ScavTrap(ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();

        void attack(const std::string &target);
        void guardGate();
};
#endif // ScavTrap_HPP