#include "FragTrap.hpp"




FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
    std::cout << "FragTrap Argument Constructor Called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called" << std::endl;
}