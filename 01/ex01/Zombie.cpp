#include "Zombie.hpp"


Zombie::Zombie(): _name("<name>") {}
Zombie::Zombie(std::string name): _name(name) {}
Zombie::~Zombie()
{
    std::cout << _name << ": Destroyed\n";
}

void Zombie::setName(std::string name)
{
    _name = name;
}
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}


