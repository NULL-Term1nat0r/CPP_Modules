/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:22:03 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/08 23:22:03 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Date.hpp"
#include <iostream>

Date::Date(std::string date) {
	_currentDay = _getCurrentDay();
	_currentMonth = _getCurrentMonth();
	_currentYear = _getCurrentYear();
	if (!isValidDate(date)){
		std::cout << "exception string in date: " << date << std::endl;
		throw InvalidDateException();
	}
	_day = Parsing::stoi(_getDay(date));
	_month = Parsing::stoi(_getMonth(date));
	_year = Parsing::stoi(_getYear(date));
}

Date &Date::operator=(Date const &rhs) {
	if (this != &rhs) {
		_day = rhs._day;
		_month = rhs._month;
		_year = rhs._year;
	}
	return *this;
}

Date::~Date() {}

bool Date::isValidDate(const std::string& date) {
	if (date.length() != 10)
		return false;
	std::istringstream ss(date);
	char dash1, dash2;
	int year, month, day;

	if (!(ss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	if (ss.fail())
		return false;
	if (dash1 != '-' || dash2 != '-')
		return false;
	if (year < 0 || year > _currentYear)
		return false;
	if (month < 1 || month > 12 || (year == _currentYear && month > _currentMonth))
		return false;
	if (!_isValidDayInMonth(year, month, day) ||
		(year == _currentYear && month == _currentMonth && day > _currentDay)) {
		return false;
	}
	if (!_isDateBeforeDataBaseRange(year, month, day))
		return false;
	return true;
}

bool Date::_isDateBeforeDataBaseRange(int year, int month, int day) {
	if (year < 2009)
		return false;
	if (year == 2009 && month == 1 && day < 2)
		return false;
	return true;
}
bool Date::_isValidDayInMonth(int year, int month, int day) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ){
		if (day <= 31)
			return true;
		else
			return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11){
		if (day <= 30)
			return true;
		else
			return false;
	}
	else if (month == 2){
		if (_isLeapYear(year) && day <= 29)
			return true;
		if (day <= 28)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Date::_isLeapYear(int year){
	if (year % 4 == 0) {
		if (year % 100 == 0 && year % 400 != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}

std::string Date::_getYear(std::string date){
	int end = date.find('-');
	return date.substr(0, end);
}

std::string Date::_getMonth(std::string date){
	int start = date.find('-');
	int end = date.find_last_of('-');
	return date.substr(start + 1, end - start - 1);
}

std::string Date::_getDay(std::string date){
	int start = date.find_last_of('-');
	int end = date.length();
	return date.substr(start + 1, end);
}

int Date::_getCurrentDay() {
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);
	return now->tm_mday;
}

int Date::_getCurrentMonth() {
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);
	return now->tm_mon + 1;
}

int Date::_getCurrentYear() {
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);
	return now->tm_year + 1900;
}

bool Date::operator<(const Date &rhs) const {
	return _year < rhs._year ||
		   (_year == rhs._year && _month < rhs._month) ||
		   (_year == rhs._year && _month == rhs._month && _day < rhs._day);
}

bool Date::operator>(const Date &rhs) const {
	return _year > rhs._year ||
		   (_year == rhs._year && _month > rhs._month) ||
		   (_year == rhs._year && _month == rhs._month && _day > rhs._day);
}

bool Date::operator<=(const Date &rhs) const {
	return _year < rhs._year ||
		   (_year == rhs._year && _month < rhs._month) ||
		   (_year == rhs._year && _month == rhs._month && _day <= rhs._day);
}

bool Date::operator>=(const Date &rhs) const {
	return _year > rhs._year ||
		   (_year == rhs._year && _month > rhs._month) ||
		   (_year == rhs._year && _month == rhs._month && _day >= rhs._day);
}

bool Date::operator==(const Date &rhs) const {
	return _year == rhs._year && _month == rhs._month && _day == rhs._day;
}

const char *Date::InvalidDateException::what() const throw() {
	return "Invalid date";
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << date._year << '-' << date._month << '-' << date._day;
	return os;
}