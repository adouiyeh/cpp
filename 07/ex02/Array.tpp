#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(NULL), size(0) {}

template <typename T>
Array<T>::Array(std::size_t n) : arr(new T[n]), size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : arr(new T[other.size]), size(other.size) {
    for (std::size_t i = 0; i < size; ++i)
        arr[i] = other.arr[i];
}

template <typename T>
const Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] arr;
        arr = new T[other.size];
        size = other.size;
        for (std::size_t i = 0; i < size; ++i)
            arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
T& Array<T>::operator[](std::size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of bounds");
    return arr[index];
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const {
    if (index >= size)
        throw std::out_of_range("Index out of bounds");
    return arr[index];
}

template <typename T>
std::size_t Array<T>::getSize() const {
    return size;
}
