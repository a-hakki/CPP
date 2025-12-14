#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {

    private:
        str ideas[100];

    public:
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();

};



#endif //BRAIN_HPP