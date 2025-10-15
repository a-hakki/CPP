
#ifndef CONTACT_H
# define CONTACT_H
# include "main.hpp"

class Contact
{
    private :
        str first;
        str last;
        str nick;
        str phone;
        str secret;
    public :
        Contact();
        ~Contact();
    
        str  get_first();
        str  get_last();
        str  get_nick();
        str  get_phone();
        str  get_secret();

        void    set_first(str first);
        void    set_last(str last);
        void    set_nick(str nick);
        void    set_phone(str phone);
        void    set_secret(str secret);
};

#endif