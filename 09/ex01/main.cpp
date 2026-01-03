#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <RPN expression>" << std::endl;
        return 1;
    }

    std::string rpn = av[1];
    try
    {
        std::stack<int> nums;
        handle_rpn(rpn, nums);
        if (nums.size() != 1)
            throw std::runtime_error("Error: invalid RPN expression.");
        std::cout << nums.top() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}