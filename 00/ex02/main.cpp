#include <iostream>
#include <vector>
#include "Account.hpp"



int main()
{
    std::vector<int> acc({123, 12, 4, 244, 99});

    int acc_size = sizeof(acc) - sizeof(int);

    

    int dep[] = {12, 33, 412, 441, 441};
    int dep_size(sizeof(dep) / sizeof(int));

    std::vector<Account::t> vec(dep, dep + dep_size);

    Account::displayAccountsInfos();
    std::vector<Account::t>::iterator vec_begin = vec.begin();
    std::vector<Account::t>::iterator vec_end = vec.end();

    typedef std::pair<std::vector<Account::t>::iterator, std::vector<int>::iterator> acc_int_t;

    for (acc_int_t it(vec_begin))

}