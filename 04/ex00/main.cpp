#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *animal = new Animal();
    const WrongAnimal *wanimal = new WrongAnimal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    const WrongAnimal *wcat = new WrongCat();

    std::cout << animal->getType() << " " << std::endl;
    std::cout << wanimal->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << wcat->getType() << " " << std::endl;
    
    animal->makeSound();
    wanimal->makeSound();
    dog->makeSound();
    cat->makeSound();
    wcat->makeSound();

    delete animal;
    delete wanimal;
    delete dog;
    delete cat;
    delete wcat;
    return 0;
}
