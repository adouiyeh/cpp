#include "Dog.hpp"


Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other._type)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << "Copy Assignement Called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}


void Dog::makeSound(void) const
{
    std::cout << "Wooof" << std::endl;
}
