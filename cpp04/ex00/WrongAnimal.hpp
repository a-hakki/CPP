#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

typedef std::string str;

class WrongAnimal
{
    private:
        str type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
        void makeSound() const;
};




#endif //WRONGANIMAL_HPP