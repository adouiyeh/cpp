#include "ScavTrap.hpp"


int main()
{
    ScavTrap foo("Foo");
    ScavTrap bar("Bar");

    foo.attack("Bar");
    bar.takeDamage(20);
    bar.attack("Foo");
    foo.takeDamage(20);
    foo.beRepaired(1);
}