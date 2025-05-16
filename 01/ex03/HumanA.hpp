#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string.h>
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    private:
        std::string _name;
        Weapon& _weapon;
    public:
        HumanA(const std::string& name, Weapon& weapon);
        void attack() const;
};

#endif