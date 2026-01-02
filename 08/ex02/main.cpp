#include <iostream>
#include "MutantStack.hpp"

int main()
{

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;


    MutantStack<int> copy(mstack);
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "Top: " << copy.top() << std::endl;
    copy.pop();
    copy.pop();
    copy.pop();
    std::cout << "Top: " << copy.top() << std::endl;
    std::cout << "Size after pop: " << copy.size() << std::endl;
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}