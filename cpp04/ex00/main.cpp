#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    {
        std::cout << "====== Constructors called ======" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "\n====== Making sounds ======" << std::endl;
        meta->makeSound();
        j->makeSound();
        i->makeSound();

        std::cout << "\n====== Destructors called ======" << std::endl;
        delete meta;
        delete j;
        delete i;
    }
    {
        std::cout << "\n====== Wrong Animal Test ======" << std::endl;
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        meta->makeSound();
        i->makeSound();
        delete meta;
        delete i;
    }
    return 0;
}