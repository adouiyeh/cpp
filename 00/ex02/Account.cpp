#include "Account.hpp"
#include "ctime"
#include "iostream"
#include "iomanip"


Account::Account(int initial_deposit): _accountIndex(Account::_nbAccounts), _amount(initial_deposit),  _nbDeposits(0), _nbWithdrawals(0)
{
    _displayTimestamp();
    
    Account::_nbAccounts++;
}


int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}
int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

void Account::_displayTimestamp()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << std::put_time(now, "%Y%m%d_%H%M%S") << "] ";
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    Account::getNbAccounts();
    Account::getTotalAmount();
}