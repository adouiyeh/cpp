#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string.h>
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:
        std::string _name;
        Weapon* _weapon;
    public:
        HumanB(const std::string& name);
        void setWeapon(Weapon& weapon);
        void attack() const;
};

#endif