#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {


    Span span1(5);
    span1.addNumber(6);
    span1.addNumber(3);
    span1.addNumber(17);
    span1.addNumber(9);
    span1.addNumber(11);
    
    std::cout << "Shortest span: " << span1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span1.longestSpan() << std::endl;

    try {
        span1.addNumber(42);
    } catch (const std::overflow_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Span span2(10);
    try {
        span2.shortestSpan();
    } catch (const std::logic_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Span span3(2);
    span3.addNumber(5);
    try {
        span3.longestSpan();
    } catch (const std::logic_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::vector<int> v1 = {6, 3, 17, 9, 11};
    Span span3(5);

    span3.addRange(v1.begin(), v1.end());

    span3.longestSpan();


    return 0;
}