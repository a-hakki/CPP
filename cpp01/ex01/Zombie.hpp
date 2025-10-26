
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

typedef std::string str;

class Zombie
{
    private:
        str     name;
    public:
        Zombie();
        ~Zombie();
        void    set_name(str name);
        void    announce( void );
};

Zombie* zombieHorde( int N, std::string name );

# endif
