#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Error: could not open file." << std::endl;
    else 
    {
        try 
        {
            BitcoinExchange ex;
            ex.handleInput(av[1]);
        } catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return (0);
}