#include "Account.hpp"
#include <iostream>
#include <ctime>

// ================= STATIC =================

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// ================= TIME =================

void Account::_displayTimestamp()
{
    // 1. Get the current raw calendar time (Epoch time in seconds)
    std::time_t t = std::time(NULL);

    // 2. Convert raw seconds into local time structures (Year, Month, Day, etc.)
    std::tm* now = std::localtime(&t);

    std::cout << "["
              << (now->tm_year + 1900)
              // if less than 10, add a "0" then print the number
              << (now->tm_mon + 1 < 10 ? "0" : "") << (now->tm_mon + 1)
              << (now->tm_mday < 10 ? "0" : "") << now->tm_mday
              << "_"
              << (now->tm_hour < 10 ? "0" : "") << now->tm_hour
              << (now->tm_min < 10 ? "0" : "") << now->tm_min
              << (now->tm_sec < 10 ? "0" : "") << now->tm_sec
              << "] ";
}

// ================= GETTERS =================

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

// ================= DISPLAY GLOBAL =================

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

// ================= CONSTRUCTOR =================

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created"
              << std::endl;
}

// ================= DESTRUCTOR =================

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed"
              << std::endl;
}

// ================= DEPOSIT =================

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;

    _amount += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

// ================= WITHDRAW =================

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:" << withdrawal;

    if (_amount < withdrawal)
    {
        std::cout << ";refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;

    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;

    return true;
}

// ================= CHECK =================

int Account::checkAmount() const
{
    return _amount;
}

// ================= STATUS =================

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}