#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
private:
    unsigned int maxSize;
    std::vector<int> numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
};
