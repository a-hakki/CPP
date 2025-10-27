#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
typedef std::string str;

class Weapon
{
    private:
        str type;
    public:
        Weapon(str name);
        ~Weapon();
        const str   &getType() const;
        void        setType(str type);
};

#endif // WEAPON_HPP
