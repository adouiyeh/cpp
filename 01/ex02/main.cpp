#include <string>
#include <iostream>



int main()
{
    std::string stringVAR("HI THIS IS BRAIN");
    std::string* stringPTR = &stringVAR;
    std::string& stringREF = stringVAR;
    std::cout << &stringVAR << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << stringVAR << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringVAR << std::endl;
}
