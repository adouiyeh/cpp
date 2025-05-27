#include "ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string& name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Argument Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy Constructor Called" << std::endl;

    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints && energyPoints)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else if (!hitPoints)
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
    else
        std::cout << "ClapTrap " << name << " has no energy!" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints)
    {
        std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
        hitPoints--;
    }
    else 
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints && energyPoints)
    {
        std::cout << "ClapTrap " << name << " repaired " << amount << " hit points!" << std::endl;
        hitPoints++;
        energyPoints--;
    }
    else if (!hitPoints)
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
    else
        std::cout << "ClapTrap " << name << " has no energy!" << std::endl;

}
