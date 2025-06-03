#include "WrongCat.hpp"


WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other._type)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << "Copy Assignement Called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Meowww" << std::endl;
}