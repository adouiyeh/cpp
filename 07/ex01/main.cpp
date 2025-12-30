#include "iter.hpp"


void incrementInt(int& x) {
	++x;
}

void printInt(const int& x) {
	std::cout << x << std::endl;
}

void toUpper(std::string& s) {
	for (std::size_t i = 0; i < s.size(); ++i)
		s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
}

int main() {
	int iarr[] = {1, 2, 3, 4, 5};
	const std::size_t len_i = sizeof(iarr) / sizeof(iarr[0]);

	std::cout << "Original ints:\n";
	iter<int>(iarr, len_i, printConstRef<int>); 
	iter(iarr, len_i, incrementInt);
	std::cout << "After increment:\n";
	iter(iarr, len_i, printInt);

	std::string sarr[] = {"hello", "world", "Iter"};
	const std::size_t len_s = sizeof(sarr) / sizeof(sarr[0]);

	std::cout << "\nOriginal strings:\n";
	iter(sarr, len_s, printConstRef<std::string>);
	iter(sarr, len_s, toUpper);
	std::cout << "After toUpper:\n";

	const char* carr[] = {"a", "bb", "ccc"};
	const std::size_t len_c = sizeof(carr) / sizeof(carr[0]);

	std::cout << "\nC-strings:\n";
	iter<const char*>(carr, len_c, printConstRef<const char*>);

	return 0;
}


