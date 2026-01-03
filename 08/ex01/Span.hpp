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

        template<typename It>
        void addRange(It begin, It end)
        {
            if (numbers.size() + std::distance(begin, end) > maxSize)
                throw std::overflow_error("Span is full");
            numbers.insert(numbers.end(), begin, end);
        }
};
