#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found value at index: " << (it - vec.begin()) << std::endl;
        it = easyfind(vec, 50);
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
