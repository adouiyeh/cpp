#include <iostream>

class Test {
    public:
        int _test;
        double _score;
        char _grade;
        bool _passed;
        std::string _name;
    
        // Constructor with initializer list for all members
        Test(int test, double score, char grade, bool passed, const std::string& name)
            : _test(test), _score(score), _grade(grade), _passed(passed), _name(name) {}
    };

int main()
{
    std::cout << "This is a test" << std::endl;
}