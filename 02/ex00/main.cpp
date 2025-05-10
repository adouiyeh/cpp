
#include <iostream>

class Test
{
    public:
        int *val;
        Test() {std::cout << "Test" << std::endl;};
        Test(int *val) {
            this->val = val;
            std::cout << "Testing" << std::endl;
        };
        Test(const Test &test) { this->val = test.val; };
        ~Test() {delete val; std::cout << "Destruct" << std::endl;};
};

int main()
{
    // Direct Initialization
    // Copy Initialization

    Test test(new int(19));
    std::cout << *(test.val) << std::endl;
    return (1);
}