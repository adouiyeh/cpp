#include <iostream>



int main()

{
	char c;
	int *i = (int*)&c;
	*i = 42;
	std::cout << *i << std::endl;
	return 0;
}
