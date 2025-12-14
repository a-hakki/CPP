#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {

    {
        std::cout << "========= test 1 : constructor/destructor =========" << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }
    {
        std::cout << "\n========= test 2 : array of animals =========" << std::endl;
        Animal  *animals[4];
        std::cout << "\n-- Creating Animals --" <<  std::endl;
        for (int i = 0; i < 4; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        std::cout << "\n-- Deleting Animals --" <<  std::endl;
        for (int i = 0; i < 4; i++)
            delete animals[i];
    }
    return 0;
}