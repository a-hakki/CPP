#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    private:
        Weapon  *weapon;
        str     name;
    public:
        HumanB(str name);
        ~HumanB();
        void    attack(void);
        void    setWeapon(Weapon &weapon);
};




#endif // HUMANB_HPP