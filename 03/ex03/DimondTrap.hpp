#ifndef DIMONDTRAP_HPP
#define DIMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DimondTrap : public FragTrap, public ScavTrap
{
    private:
        
    public:
        DimondTrap(const std::string &name);
        ~DimondTrap();
};

#endif