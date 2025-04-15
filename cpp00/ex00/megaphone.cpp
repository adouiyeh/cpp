#include <iostream>


void upperStr(std::string& str)
{
    for (int i = 0; i < str.size(); i++)
        str[i] = std::toupper(str[i]);
}


int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; i++)
        {
            std::string str = av[i];
            upperStr(str);
            std::cout << str;
        }
        std::cout << std::endl;
    }
    return (0);
}




