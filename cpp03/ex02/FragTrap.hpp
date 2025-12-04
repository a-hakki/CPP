#ifndef FragTrap_HPP
# define FragTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string Name);
        FragTrap(FragTrap &other);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap();

        void highFivesGuys(void);
};
#endif // FragTrap_HPP