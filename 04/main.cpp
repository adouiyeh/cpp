#include <iostream>





class Animal
{
    protected:
        std::string _type;

    Animal();
    ~Animal();
    Animal(Animal& other);
    Animal(const std::string& type)

};


class Dog : Animal
{

};




