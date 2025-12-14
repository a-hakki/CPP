#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

typedef std::string str;

class Animal {
    protected:
        str type;
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();
        virtual void makeSound() const = 0;
};

#endif //ANIMAL_HPP