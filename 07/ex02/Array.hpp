#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
    private:
        T* arr;
        std::size_t size;

    public:
        Array();
        Array(std::size_t n);
        Array(const Array& other);
        const Array& operator=(const Array& other);
        ~Array();

        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;
        std::size_t getSize() const;
};

#include "Array.tpp"

