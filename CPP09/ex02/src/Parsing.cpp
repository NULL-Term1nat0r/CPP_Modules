/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:12:10 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/09 13:12:10 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Parsing.hpp"

int Parsing::stoi(std::string string) {
	int result;
	std::istringstream iss(string);

	if (!(iss >> result) || (iss.fail() && !iss.eof())) {
		throw InvalidConversion();
	}

//	if (result < 0 || result > 1000) {
//		std::cout << "string to convert: " << string << std::endl;
//		throw InvalidValueRange();
//	}

	return result;
}


double Parsing::stod(const std::string& str) {
	double result;
	std::istringstream iss(str);
	if (!(iss >> result) || (iss.fail() && !iss.eof()))
		throw InvalidConversion();
	return result;
}

bool Parsing::isValidNumber(std::string number) {
	int length = number.length();
	if (length == 0)
		return false;
	if (length > 1 && (number[0] == '-' || number[0] == '+') && number[1] == '0')
		return false;
	if (length > 1 && number[0] == '0' && number[1] != '.' && number[1] != 'f')
		return false;
	if (length == 1 && (number[0] == '-' || number[0] == '+'))
		return false;
	int dotCounter = 0;
	for (std::size_t i = 0; i < length; ++i) {
		if (!isdigit(number[i])) {
			if (i == 0 && (number[i] == '-' || number[i] == '+'))
				continue;
			if (number[i] == '.' && dotCounter == 0)  {
				++dotCounter;
				continue;
			}
			if (i == length - 1 && number[i] == 'f')
				return true;
			else
				return false;
		}
	}
	return true;  // All characters are digits
}

const char *Parsing::InvalidConversion::what() const throw() {
	return "Invalid conversion";
}

const char *Parsing::InvalidValueRange::what() const throw() {
	return "Invalid Range, it must be number between 0 and 1000";
}
