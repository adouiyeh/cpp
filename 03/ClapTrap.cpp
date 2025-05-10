#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
    std::string _name;
    int _hitPoint;
    int _energyPoint;
    int _attackPoint;
    int _attackDamage;

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();
    ClapTrap &operator=(const ClapTrap &other);
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap(const std::string& name): _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "ClapTrap Argument Constructor Called\n";
    _name = name;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor Called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy Constructor Called\n";

    _name = other._name;
    _hitPoint = other._hitPoint;
    _energyPoint = other._energyPoint;
    _attackPoint = other._attackPoint;
    _attackDamage = other._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Assignment Operator Called\n";
    if (this != &other)
    {
        _name = other._name;
        _hitPoint = other._hitPoint;
        _energyPoint = other._energyPoint;
        _attackPoint = other._attackPoint;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoint && _energyPoint)
    {
        std::cout << "ClapTrap" << _name << "attacks" << target << "causing" << _attackDamage << "points of damage!\n";
        _hitPoint--;
        _energyPoint--;
    }

}

#endif