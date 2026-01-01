#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    std::cout << "=== Span Class Tests ===" << std::endl;

    // Test 1: Basic test with small numbers
    std::cout << "\n1. Basic test with small numbers:" << std::endl;
    Span span1(5);
    span1.addNumber(6);
    span1.addNumber(3);
    span1.addNumber(17);
    span1.addNumber(9);
    span1.addNumber(11);
    
    std::cout << "Shortest span: " << span1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span1.longestSpan() << std::endl;

    // Test 2: Adding to full Span
    std::cout << "\n2. Testing overflow exception:" << std::endl;
    try {
        span1.addNumber(42);
    } catch (const std::overflow_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 3: Empty Span
    std::cout << "\n3. Testing empty Span exception:" << std::endl;
    Span span2(10);
    try {
        span2.shortestSpan();
    } catch (const std::logic_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 4: Single element
    std::cout << "\n4. Testing single element exception:" << std::endl;
    Span span3(10);
    span3.addNumber(5);
    try {
        span3.longestSpan();
    } catch (const std::logic_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 5: Large dataset (10,000 numbers)
    std::cout << "\n5. Testing with 10,000 numbers:" << std::endl;
    Span span4(10000);
    srand(time(NULL));
    
    for (int i = 0; i < 10000; ++i) {
        span4.addNumber(rand() % 100000);
    }
    
    std::cout << "Shortest span: " << span4.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span4.longestSpan() << std::endl;

    // Test 6: Even larger dataset (50,000 numbers)
    std::cout << "\n6. Testing with 50,000 numbers:" << std::endl;
    Span span5(50000);
    
    for (int i = 0; i < 50000; ++i) {
        span5.addNumber(rand() % 1000000);
    }
    
    std::cout << "Shortest span: " << span5.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span5.longestSpan() << std::endl;

    // Test 7: Sequential numbers
    std::cout << "\n7. Testing with sequential numbers:" << std::endl;
    Span span6(100);
    for (int i = 0; i < 100; ++i) {
        span6.addNumber(i);
    }
    
    std::cout << "Shortest span: " << span6.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span6.longestSpan() << std::endl;

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}