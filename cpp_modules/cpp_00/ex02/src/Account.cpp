#include "Account.hpp"
#include <iostream>
#include <iomanip>
// #include <string>
#include <ctime>

#define BLUE "\033[34m"
#define RESET "\033[0m"


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts() { return (_nbAccounts); }
int		Account::getTotalAmount() { return (_totalAmount); }
int		Account::getNbDeposits() { return (_totalNbDeposits); }
int		Account::getNbWithdrawals() { return (_totalNbWithdrawals); }

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET
			  << ";amount:" << BLUE << this->_amount << RESET
			  << ";created" << std::endl; 
}
Account::~Account()
{	
	_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET
			  << ";amount:" << BLUE << this->_amount << RESET
			  << ";closed" << std::endl; 
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET
			  << ";p_amount:" << BLUE << this->_amount << RESET
			  << ";deposit:" << BLUE << deposit << RESET; 
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << ";amount:" << BLUE << this->_amount << RESET
			  << ";nb_deposits:" << BLUE << this->_nbDeposits << RESET << std::endl; 
}
bool	Account::makeWithdrawal( int withdrawal )
{

	_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET
			  << ";p_amount:" << BLUE << this->_amount << RESET
			  << ";withdrawal:";
	if ((this->_amount - withdrawal) < 0)
		return (std::cout << "refused" << std::endl, false);
	std::cout << BLUE << withdrawal << RESET;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << ";amount:" << BLUE << this->_amount << RESET
			  << ";nb_withdrawals:" << BLUE << this->_nbWithdrawals << RESET << std::endl;
	return (true) ;
}
int		Account::checkAmount( void ) const { return (this->_amount); }

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET
			  << ";amount:" << BLUE << this->_amount << RESET
			  << ";deposits:" << BLUE << this->_nbDeposits << RESET
			  << ";withdrawals:" << BLUE << this->_nbWithdrawals << RESET << std::endl; 
}


void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << BLUE << Account::_nbAccounts << RESET
			  << ";total:" << BLUE << Account::_totalAmount << RESET
			  << ";deposits:" << BLUE << Account::_totalNbDeposits << RESET
			  << ";withdrawals:" << BLUE << Account::_totalNbWithdrawals << RESET << std::endl; 
}

// [YYYYMMDD_HHMMSS]
void	Account::_displayTimestamp()
{
	// get the current time
	std::time_t t_now = std::time(NULL);

	// convert it to local time sturcture
	// (*tm array, has tm_sec, tm_min etc..)
	std::tm* timeinfo = std::localtime(&t_now);

	char buffer[18]; // 17 chars ([%Y%m%d_%H%M%S]) + '\0'

	// string format time->build formatted time string from tm structure
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer << " ";
}

