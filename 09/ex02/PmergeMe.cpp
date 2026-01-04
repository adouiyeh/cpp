#include  "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        int num = static_cast<int>(std::atoi(av[i]));
        _vec.push_back(num);
        _deq.push_back(num);
    }    
}

PmergeMe::PmergeMe(PmergeMe const &src) {
    _vec = src._vec;
    _deq = src._deq;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe(void) {
}


void PmergeMe::sort(void) {

    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    std::cout << "After: ";
    fordJohnsonSort(_vec);
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    // fordJohnsonSort(_deq);
}


void PmergeMe::printContainer(void) {
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
}