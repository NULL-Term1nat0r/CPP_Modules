/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkroger <jkroger@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:41:04 by jkroger           #+#    #+#             */
/*   Updated: 2023/06/14 12:07:51 by jkroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "default constructor called" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter const &converter)
{
	std::cout << "copy constructor called" << std::endl;
	*this = converter;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "deconstructor called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &converter)
{
	if (this == &converter)
		return *this;
	std::cout << "copy assigment constructor called" << std::endl;
	return *this;
}

bool ScalarConverter::isPrintableChar(const std::string& str) {
	if (str.length() == 1) {
		char ch = str[0];
		return (isprint(ch) && ch != '0');
	}
	return false;
}

bool ScalarConverter::isNumber(const std::string& str) {
	int length = str.length();
	if (length == 0)
		return false;
	if (length > 1 && (str[0] == '-' || str[0] == '+') && str[1] == '0')
		return false;
	if (length > 1 && str[0] == '0' && str[1] != '.' && str[1] != 'f')
		return false;
	if (length == 1 && (str[0] == '-' || str[0] == '+'))
		return false;
	int dotCounter = 0;
	for (std::size_t i = 0; i < length; ++i) {
		if (!isdigit(str[i])) {
			if (i == 0 && (str[i] == '-' || str[i] == '+'))
				continue;
			if (str[i] == '.' && dotCounter == 0)  {
				++dotCounter;
				continue;
			}
			if (i == length - 1 && str[i] == 'f')
				return true;
			else
				return false;
		}
	}
	return true;  // All characters are digits
}

bool ScalarConverter::isValidInput(const std::string& str) {
	if (isPrintableChar(str) || isNumber(str))
		return true;
	if (checkIfNumericLimits(str))
		return true;
	return false;
}

bool ScalarConverter::isChar(const std::string& str) {
	return isPrintableChar(str) && (str[0] < '0' || str[0] > '9');
}

bool ScalarConverter::isInt(const std::string& str) {
	std::istringstream iss(str);
	int result;
	iss >> result;
	if (iss.fail() || !iss.eof()) {
		return false;
	}
	return true;
}

double ScalarConverter::stringToDouble(const std::string& str) {
	char* endptr;
	double result = strtod(str.c_str(), &endptr);
	return result;
}

float ScalarConverter::stringToFloat(const std::string& str) {
	char *endptr;
	if (str[str.length() - 1] == 'f') {
		std::string withoutF = str.substr(0, str.length() - 1);
		float result = strtof(withoutF.c_str(), &endptr);
		return result;
	}
	std::istringstream iss(str);
	float result;
	iss >> result;
	return result;
}


int ScalarConverter::stringToInt(const std::string& str) {
	char* endptr;
	int result = strtol(str.c_str(), &endptr, 10);
	return result;
}

bool ScalarConverter::checkIfNumericLimits(const std::string convert) {
	if (convert == "nan" || convert == "nanf" || convert == "-inf" || convert == "inf" || convert == "-inff" || convert == "inff")
		return true;
	return false;
}

void ScalarConverter::printChar(const std::string convert) {
	if (isChar(convert))
		std::cout << "char: '" << convert << "'" << std::endl;
	else if (stringToFloat(convert) > 32 && stringToFloat(convert) <= 127)
			std::cout << "char: '" << static_cast<char>(stringToFloat(convert)) << "'" << std::endl;
	else if (stringToInt(convert) >= 0 && stringToFloat(convert) <= 32)
			std::cout << "char: Non displayable" << std::endl;
	else
			std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::printInt(const std::string convert) {
	if (convert == "nan" || convert == "nanf" || convert == "-inf" || convert == "inf" || convert == "-inff" || convert == "inff")
		std::cout << "int: impossible" << std::endl;
	else if (isChar(convert))
		std::cout << "int: " << static_cast<int>(convert[0]) << std::endl;
	else if (isInt(convert))
		std::cout << "int: " << convert << std::endl;
	else if (stringToFloat(convert) >= MIN_INT && stringToFloat(convert) <= MAX_INT)
		std::cout << "int: " << static_cast<int>(stringToFloat(convert)) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::printFloat(const std::string convert) {
	if (convert == "nan" || convert == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (convert == "-inf" || convert == "-inff")
		std::cout << "float: -inff" << std::endl;
	else if (convert == "inf" || convert == "inff")
		std::cout << "float: inff" << std::endl;
	else if (isChar(convert))
		std::cout << "float: " << static_cast<float>(convert[0]) << ".0f" << std::endl;
	else if (isInt(convert))
		std::cout << "float: " << static_cast<float>(stringToInt(convert)) << ".0f" << std::endl;
	else
		std::cout << "float: " << stringToFloat(convert) << "f" << std::endl;
}

void ScalarConverter::printDouble(const std::string convert) {
	if (convert == "nan" || convert == "nanf")
		std::cout << "double: nan" << std::endl;
	else if (convert == "-inf" || convert == "-inff")
		std::cout << "double: -inf" << std::endl;
	else if (convert == "inf" || convert == "inff")
		std::cout << "double: inf" << std::endl;
	else if (isChar(convert))
		std::cout << "double: " << static_cast<double>(convert[0]) << ".0" << std::endl;
	else if (isInt(convert))
		std::cout << "double: " << static_cast<double>(stringToInt(convert)) << ".0" << std::endl;
	else {
		if (stringToFloat(convert) != MY_HUGE_VALF && stringToFloat(convert) != -MY_HUGE_VALF)
			std::cout << "double: " << static_cast<double>(stringToFloat(convert)) << std::endl;
		else
			std::cout << "double: " << stringToDouble(convert) << std::endl;
	}
}

void ScalarConverter::convertTypes(const std::string convert) {
	if (isValidInput(convert) == false) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	printChar(convert);
	printInt(convert);
	printFloat(convert);
	printDouble(convert);
}








