/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:20:24 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/04 02:03:37 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <sstream>
#include <string>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

std::string	Account::dV(int value) const
{
	std::string CYAN = "\033[36m";
	std::string RESET = "\033[0m";
	std::string valueToString = std::to_string(value);

	std::string combined = CYAN + valueToString + RESET;
	return (combined);
}
Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit) {
	_displayTimestamp();
	std::cout << "index:" << dV(_accountIndex) << ";amount:" << dV(initial_deposit) << ";created\n";
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << dV(_accountIndex) << ";amount" << dV(_amount) << ";closed\n";
	_nbAccounts--;
	_totalAmount -= _amount;
}

int Account::getNbAccounts( void ) { return _nbAccounts; }

int Account::getTotalAmount( void ) { return _totalAmount; }

int Account::getNbDeposits( void ) { return _totalNbDeposits; }

int Account::getNbWithdrawals (void ) { return _totalNbWithdrawals; }

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << dV(_accountIndex) << ";p_amount:" << dV(_amount) << ";deposit:" << dV(deposit) << ";amount:" << dV(_amount + deposit) << ";nb_deposits:" << dV(_nbDeposits + 1) << "\n";
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout <<  "index:" << dV(_accountIndex) << ";p_amount:" << dV(_amount) << ";withdrawal:refused\n";
		return false;
	}
	std::cout << "index:" << dV(_accountIndex) << ";p_amount:" << dV(_amount) << ";withdrawal:" << dV(withdrawal) << ";amount:" << dV(_amount - withdrawal) << ";nb_withdrawals:" << dV(_nbWithdrawals + 1)<< "\n";
	_nbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

int		Account::checkAmount ( void ) const { return _amount; }

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << dV(_accountIndex) << ";amount:" << dV(_amount) << ";deposits:" << dV(_nbDeposits) << ";withdrawals:" << dV(_nbWithdrawals) << "\n";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::string CYAN = "\033[36m";
	std::string RESET = "\033[0m";
	std::string valueToString = std::to_string(getNbAccounts());
	std::string combined1 = CYAN + valueToString + RESET;
	 valueToString = std::to_string(getTotalAmount());
	std::string combined2 = CYAN + valueToString + RESET;
	valueToString = std::to_string(getNbDeposits());
	std::string combined3 = CYAN + valueToString + RESET;
	valueToString = std::to_string(getNbWithdrawals());
	std::string combined4 = CYAN + valueToString + RESET;

	std::cout << "accounts" << combined1 << ";total:" << combined2 << ";deposits:" << combined3 << ";withdrawals:" << combined4 << "\n";
}

void	Account::_displayTimestamp( void ) {
	std::time_t current_time = std::time(0);
	std::tm* time_info = std::localtime(&current_time);

	std::cout << "[" << time_info->tm_year + 1900 << time_info->tm_mon <<  time_info->tm_mday << '_' << time_info->tm_hour << time_info->tm_min << time_info->tm_sec << "] ";
}
