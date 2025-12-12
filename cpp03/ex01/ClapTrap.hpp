#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

typedef std::string str;


class ClapTrap 
{

    protected:
        str Name;
        int Hit;
        int Energy;
        int Attack;

    public:

        ClapTrap();
        ClapTrap(str Name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        virtual ~ClapTrap();

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
