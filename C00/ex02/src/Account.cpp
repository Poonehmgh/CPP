#include"../inc/Account.hpp"
#include<iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initialDeposit)
{
    Account::_displayTimestamp();
    this->_amount = initialDeposit;
    this->_accountIndex = Account::_nbAccounts;
    std::cout<<"index:"<<this->_accountIndex<<";amount:"<<initialDeposit<<";created\n";
    Account::_nbAccounts++;
    Account::_totalAmount = Account::_totalAmount + this->_amount;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
}
Account::~Account()
{
    Account::_displayTimestamp();
    Account::_nbAccounts--;
    std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";closed.\n";
}

void Account::_displayTimestamp()
{
    std::cout<<"[19920104_091532] ";
}

int     Account::getNbAccounts()
{
    return(Account::_nbAccounts);
}

int     Account::getNbDeposits()
{
    return(Account::_totalNbDeposits);
}

int     Account::getNbWithdrawals()
{
    return(Account::_totalNbWithdrawals);
}

int     Account::getTotalAmount()
{
    return (Account::_totalAmount);
}

void    Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";deposits:"<<this->_nbDeposits<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int tmp = this->_amount;
    
    Account::_displayTimestamp();
    if (this->_amount >= withdrawal)
        this->_amount = this->_amount - withdrawal;
    else
    {
        std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<tmp<<";withdrawal:refused\n";
        return(false);
    }
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount = Account::_totalAmount - withdrawal;
    std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<tmp<<";withdrawal:"<<withdrawal<<";amount:"<<this->_amount<<";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
    return(true);
}

void	Account::makeDeposit( int deposit )
{
    int tmp;

    Account::_displayTimestamp();
    tmp = this->_amount;
    this->_amount = this->_amount + deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_totalAmount = Account::_totalAmount + deposit;
    std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<tmp<<";deposits:"<<deposit<<";amount:"<<this->_amount<<";nb_deposits:"<<this->_nbDeposits<<std::endl;
    return ;
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout<<"accounts:"<<Account::getNbAccounts()<<";total:"<<Account::getTotalAmount()<<";deposits:"<<Account::getNbDeposits()<<";withdrawals:"<<Account::getNbWithdrawals()<<std::endl;
    return ;
}

