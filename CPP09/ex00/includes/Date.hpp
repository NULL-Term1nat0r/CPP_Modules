/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:21:52 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/08 23:21:52 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include <ctime>
#include <sstream>
#include "Colors.hpp"

#include "Parsing.hpp"

class Date {
public:
	Date(std::string date);
	Date &operator=(Date const &rhs);
	~Date();
	bool isValidDate(const std::string &date);

	std::string _getYear(std::string date);
	std::string _getMonth(std::string month);
	std::string _getDay(std::string day);

	int _getCurrentYear();
	int _getCurrentMonth();
	int _getCurrentDay();

	bool _isValidDayInMonth(int year, int month, int day);
	bool _isDateBeforeDataBaseRange(int year, int month, int day);
	bool _isLeapYear(int year);

	bool operator<(Date const &rhs) const;
	bool operator>(Date const &rhs) const;
	bool operator<=(Date const &rhs) const;
	bool operator>=(Date const &rhs) const;
	bool operator==(Date const &rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const Date& date);

	int _currentDay;
	int _currentMonth;
	int _currentYear;
	int _day;
	int _month;
	int _year;

	class InvalidDateException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};