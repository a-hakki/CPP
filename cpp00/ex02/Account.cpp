#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}
Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;

    // update global counters
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;

    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount = this->_amount;
    Account::_displayTimestamp();
    if (withdrawal > this->_amount)
    {
        std::cout << "index:" << this->_accountIndex
                  << ";p_amount:" << p_amount
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;

    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << p_amount
              << ";withdrawal:" << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;
    return true;
}
int Account::checkAmount(void) const
{
    return this->_amount;
}
void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}
void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(NULL);
    std::tm *tm = std::localtime(&t);
    if (tm)
    {
        std::cout << '['
                  << (tm->tm_year + 1900)
                  << std::setfill('0') << std::setw(2) << (tm->tm_mon + 1)
                  << std::setfill('0') << std::setw(2) << tm->tm_mday
                  << '_'
                  << std::setfill('0') << std::setw(2) << tm->tm_hour
                  << std::setfill('0') << std::setw(2) << tm->tm_min
                  << std::setfill('0') << std::setw(2) << tm->tm_sec
                  << "] ";
    }
    else
    {
        std::cout << "[00000000_000000] ";
    }
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts()
              << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals()
              << std::endl;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}
int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

