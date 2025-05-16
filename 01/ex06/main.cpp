#include "Harl.hpp"
#include <iostream>



int getLevel(const std::string& level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level)
            return i;
    }
    return -1;
}


int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl harl;
        switch (getLevel(av[1]))
        {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        }
    }
    return 0;
}