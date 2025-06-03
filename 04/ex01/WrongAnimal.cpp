#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
    std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
    std::cout << "WrongAnimal Paramater Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    _type = other._type;
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << "WrongAnimal Copy Assignement Called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal does not make any sound!" << std::endl;
}