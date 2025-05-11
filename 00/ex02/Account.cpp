#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstring>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created\n";
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
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
    std::tm *now = std::localtime(&t);
    std::cout << "[" << std::put_time(now, "%Y%m%d_%H%M%S") << "] ";
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    int p_amount = _amount;
    _amount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << _nbDeposits
              << ";amount:" << _amount
              << ";withdrawals" << _nbWithdrawals
              << std::endl;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    bool refused = false;
    int p_amount = _amount;
    _amount > withdrawal ? _amount -= withdrawal : refused = true;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << p_amount
              << ";withdrawal:";
    if (!refused)
    {
        _nbWithdrawals++;
        std::cout << withdrawal
                  << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals;
        Account::_totalNbWithdrawals++;
        Account::_totalAmount -= withdrawal;
    }
    else
        std::cout << "refused";
    std::cout << std::endl;
    return refused;
}