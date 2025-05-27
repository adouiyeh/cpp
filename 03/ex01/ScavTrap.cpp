#include "ScavTrap.hpp"



ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Argument Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints && energyPoints)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else if (!hitPoints)
        std::cout << "ScavTrap " << name << " is dead!" << std::endl;
    else
        std::cout << "ScavTrap " << name << " has no energy!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is in Gate keeper mode" << std::endl;
}