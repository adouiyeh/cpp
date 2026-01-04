// #include <iostream>
// #include <vector>

#include "PmergeMe.hpp"




// std::vector<size_t> jacobsthalOrder(size_t n)
// {
//     std::vector<size_t> order;
//     if (n == 0)
//         return order;

//     // Generate Jacobsthal numbers
//     std::vector<size_t> jac;
//     jac.push_back(1);
//     jac.push_back(3);

//     while (jac.back() < n)
//         jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

//     size_t prev = 0;

//     for (size_t i = 0; i < jac.size(); ++i)
//     {
//         size_t curr = jac[i];
//         if (curr > n)
//             curr = n;

//         for (size_t j = curr; j > prev; --j)
//             order.push_back(j - 1);

//         prev = curr;
//     }

//     return order;
// }


// void binaryInsert(std::vector<int>& sorted, int value)
// {
//     std::vector<int>::iterator pos =
//         std::lower_bound(sorted.begin(), sorted.end(), value);

//     sorted.insert(pos, value);
// }



// void printLead(std::vector<int>& lead)
// {
//     for (size_t i = 0; i < lead.size(); ++i)
//         std::cout << "[" << lead[i] << "]";
//     std::cout << std::endl;
    
// }

// void fordJohnsonSort(std::vector<int>& v)
// {

//     if (v.size() <= 1)
//         return;
//     std::vector<int> lead;
//     std::vector<int> pend;

//     for (size_t i = 0; i < v.size(); i += 2)
//     {
//         if (i + 1 == v.size())
//             pend.push_back(v[i]);
//         else if (v[i] >= v[i + 1])
//         {
//             lead.push_back(v[i]);
//             pend.push_back(v[i + 1]);
//         }
//         else
//         {
//             lead.push_back(v[i + 1]);
//             pend.push_back(v[i]);
//         }
//     }

//     fordJohnsonSort(lead);

//     std::vector<size_t> order = jacobsthalOrder(pend.size());
//     for (size_t idx : order)
//         binaryInsert(lead, pend[idx]);
//     v = lead;
// }

int main(int ac, char **av)
{
    // std::vector<int> v1{9, 23, 1, -2, 34, 14, 29, 6, 5};
    
    // fordJohnsonSort(v1);
    
    // std::vector<int>::iterator it = v1.begin();
    // for (; it != v1.end(); ++it)
    //     std::cout << "lead: " << *it << std::endl;
    
    // for (; pit != pend.end(); ++pit)
    //     std::cout << "pend: " << *pit << std::endl;

    try {
        PmergeMe pm(ac, av);
        pm.sort();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    

    return 0;

}


