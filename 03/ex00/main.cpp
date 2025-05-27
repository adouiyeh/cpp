#include "ClapTrap.hpp"






int main()
{
    ClapTrap foo("Foo");
    ClapTrap bar("Bar");

    foo.attack("Bar");
    bar.takeDamage(0);
    bar.attack("Foo");
    foo.takeDamage(0);
    foo.beRepaired(0);
}