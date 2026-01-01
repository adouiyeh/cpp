#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    std::cout << "=== easyfind Template Tests ===" << std::endl;

    // Test 1: Vector
    std::cout << "\n1. Testing with std::vector:" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found value 30 at position: " << (it - vec.begin()) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 2: Value not found in vector
    std::cout << "\n2. Searching for non-existent value in vector:" << std::endl;
    try {
        easyfind(vec, 100);
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 3: List
    std::cout << "\n3. Testing with std::list:" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    
    try {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found value 15 in list" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Deque
    std::cout << "\n4. Testing with std::deque:" << std::endl;
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);
    
    try {
        std::deque<int>::iterator it = easyfind(deq, 3);
        std::cout << "Found value 3 at position: " << (it - deq.begin()) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: First occurrence
    std::cout << "\n5. Testing first occurrence with duplicates:" << std::endl;
    std::vector<int> vecDup;
    vecDup.push_back(7);
    vecDup.push_back(7);
    vecDup.push_back(7);
    
    try {
        std::vector<int>::iterator it = easyfind(vecDup, 7);
        std::cout << "Found first occurrence of 7 at position: " << (it - vecDup.begin()) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}
