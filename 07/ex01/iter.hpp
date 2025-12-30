#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>

template<typename T, typename F>
void iter(T* array, const std::size_t length, F func) {
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

template<typename U>
void printConstRef(U const& x) {
	std::cout << x << std::endl;
}

