#ifndef HARL_HPP
# define HARL_HPP  

# include <iostream>

# define DEBUG 0
# define INFO 1
# define WARNING 2
# define ERROR 3

class Harl
{
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );

    public:
        Harl();
        ~Harl();
        void complain( std::string level );
};




#endif // HARL_HPP