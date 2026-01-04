#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
// #include <chrono>

class PmergeMe {
    private:
        std::vector<unsigned int>    _vec;
        std::deque<unsigned int>     _deq;
    public:
        PmergeMe(int ac, char **av);
        PmergeMe(PmergeMe const &src);
        PmergeMe &operator=(PmergeMe const &rhs);
        void printContainer(void);
        void sort(void);
        ~PmergeMe(void);
};


template <typename T>
T jacobsthalOrder(size_t n)
{
    T order;
    if (n == 0)
        return order;

    // Generate Jacobsthal numbers
    T jac;
    jac.push_back(1);
    jac.push_back(3);

    while (jac.back() < n)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

    size_t prev = 0;

    for (size_t i = 0; i < jac.size(); ++i)
    {
        size_t curr = jac[i];
        if (curr > n)
            curr = n;

        for (size_t j = curr; j > prev; --j)
            order.push_back(j - 1);

        prev = curr;
    }

    return order;
}

template <typename T>
void binaryInsert(T& sorted, int value)
{
    typename T::iterator pos =
        std::lower_bound(sorted.begin(), sorted.end(), value);

    sorted.insert(pos, value);
}


template <typename T>   
void fordJohnsonSort(T& v)
{

    if (v.size() <= 1)
        return;
    T lead;
    T pend;

    for (size_t i = 0; i < v.size(); i += 2)
    {
        if (i + 1 == v.size())
            pend.push_back(v[i]);
        else if (v[i] >= v[i + 1])
        {
            lead.push_back(v[i]);
            pend.push_back(v[i + 1]);
        }
        else
        {
            lead.push_back(v[i + 1]);
            pend.push_back(v[i]);
        }
    }

    fordJohnsonSort(lead);

    T order = jacobsthalOrder<T>(pend.size());
    for (size_t i = 0; i < order.size(); ++i)
        binaryInsert(lead, pend[order[i]]);
    v = lead;
}

// void printLead(std::vector<int>& lead)
// {
//     for (size_t i = 0; i < lead.size(); ++i)
//         std::cout << "[" << lead[i] << "]";
//     std::cout << std::endl;
    
// }
