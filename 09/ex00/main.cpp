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
            
            // std::map<std::string, float>::iterator it = ex._rates.begin();
            // for(; it != ex._rates.end(); ++it)
            //     std::cout << "Date: " << it->first << " Rate: " << it->second << std::endl;
        } catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return (0);


    // std::array<int, 3> arr = {1, 2, 3};


    // for (std::array<int, 3>::iterator it = arr.begin(); it != arr.end(); ++it)
    // {
    //     std::cout << *it << std::endl;
    // }


    // std::vector<std::string 10> test;


}