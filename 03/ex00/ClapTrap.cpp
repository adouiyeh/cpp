#include "ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
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

    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints && _energyPoints)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (!_hitPoints)
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
    else
        std::cout << "ClapTrap " << _name << " has no energy!" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints)
    {
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
        _hitPoints--;
    }
    else 
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints && _energyPoints)
    {
        std::cout << "ClapTrap " << _name << " repaired " << amount << " hit points!" << std::endl;
        _hitPoints++;
        _energyPoints--;
    }
    else if (!_hitPoints)
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
    else
        std::cout << "ClapTrap " << _name << " has no energy!" << std::endl;

}
