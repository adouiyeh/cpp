#include "Base.hpp"

int main() {
	srand(time(NULL));
    Base* p1 = generate();
    Base* p2 = generate();
    Base* p3 = generate();

    identify(p1);
    identify(*p1);
    identify(p2);
    identify(*p2);
    identify(p3);
    identify(*p3);
    delete p1;
    delete p2;
    delete p3;
	return 0;
}