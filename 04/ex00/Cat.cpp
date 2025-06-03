#include "Cat.hpp"


Cat::Cat(): Animal("Cat")
{
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other._type)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << "Copy Assignement Called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meowww" << std::endl;
}