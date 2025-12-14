#include "Dog.hpp"

Dog::Dog()
{
    this->brain = new Brain();
    this->type = "Dog";
    //std::cout << "Dog default constructor called" << //std::endl;
}

Dog::Dog(const Dog &other)
: Animal(other)
{
    this->brain = new Brain(*other.brain);
    //std::cout << "Dog copy constructor called" << //std::endl;
    this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
    //std::cout << "Dog assignment operator called" << //std::endl;
    if (this != &other)
    {
        delete this->brain;
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    //std::cout << "Dog Destructor called" << //std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    //std::cout << "Woof 🐶" << //std::endl;
}
