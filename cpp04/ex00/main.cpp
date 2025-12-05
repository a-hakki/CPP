#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    Animal a;
    a.makeSound();

    Dog d;
    d.makeSound();

    Cat c;
    c.makeSound();

    return 0;
}