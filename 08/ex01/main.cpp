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
    Span span4(5);

    span4.addRange(v1.begin(), v1.end());
    
    std::cout << "Span4 shortest span: " << span4.shortestSpan() << std::endl;
    std::cout << "Span4 longest span: " << span4.longestSpan() << std::endl;

    try {
        span4.addRange(v1.begin(), v1.end());
    } catch (const std::overflow_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Span span5(3);
    // std::vector<int> v2 = {1, 2, 3, 4};
    // try {
    //     span5.addRange(v2.begin(), v2.end());
    // } catch (const std::overflow_error& e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    return 0;
}