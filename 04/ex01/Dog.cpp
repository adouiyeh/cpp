#include "Dog.hpp"


Dog::Dog(): Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(), _brain(new Brain(*other._brain))
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Copy Assignement Called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog Destructor Called" << std::endl;
}


void Dog::makeSound(void) const
{
    std::cout << "Wooof" << std::endl;
}
