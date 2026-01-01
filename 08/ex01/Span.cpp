#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (numbers.size() >= maxSize)
        throw std::overflow_error("Span is full");
    numbers.push_back(num);
}

int Span::shortestSpan() {
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    
    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());
    
    int shortest = sorted[1] - sorted[0];
    for (std::size_t i = 2; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int Span::longestSpan() {
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    
    int minVal = *std::min_element(numbers.begin(), numbers.end());
    int maxVal = *std::max_element(numbers.begin(), numbers.end());
    
    return maxVal - minVal;
}
