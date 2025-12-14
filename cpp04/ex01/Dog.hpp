#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal {
    private:
        Brain *brain;
    protected:
        str type;
    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();
        void makeSound() const;
};

#endif //DOG_HPP