#include "Animal.hpp"


Animal::Animal(): _type("Animal")
{
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type)
{
    std::cout << "Animal Paramater Constructor Called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    _type = other._type;
    std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << "Animal Copy Assignement Called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
}