#include "Zombie.hpp"


Zombie::Zombie() {
    this->_name = "(null)";
	std::cout << this->_name << ": Created" << std::endl;
}

Zombie::Zombie(std::string name): _name(name) {
	std::cout << this->_name << ": Created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << ": Destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}


