#include "Zombie.hpp"



int main()
{
    Zombie *zombie_ptr = newZombie("Foo");
    zombie_ptr->announce();
    randomChump("Bar");
    delete zombie_ptr;
}