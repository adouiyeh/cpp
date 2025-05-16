#include "Zombie.hpp"

int main()
{

    Zombie *zombie_ptr = newZombie("Foo");
    zombie_ptr->announce();
    randomChump("Bar");
    delete zombie_ptr;

    Zombie *horde = zombieHorde(10, "Horde");
    if (horde)
        for (int i = 0; i < 10; i++)
            horde[i].announce();
    delete[] horde;
}