#include "Contact.hpp"
#include "main.hpp"

class PhoneBook
{
    private :
        int current_index;
        Contact contact[8];
    public :
        PhoneBook();
        ~PhoneBook();
        void add_contact();
        void search_contac();
};
