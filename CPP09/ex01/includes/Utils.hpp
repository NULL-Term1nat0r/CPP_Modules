/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:34:08 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/10 15:34:08 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>

class InvalidInputForOperation : public std::exception {
public:
	virtual const char *what() const throw() {
		return "\033[31mInvalid input for operation\033[0m";
	}
};

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '!') {
		std::cout << magenta << "isOperator: " << c  << resetColor <<  std::endl;
		return true;
	}
	return false;
}

bool isOperand(char c) {
	return isdigit(c) || c == 'e';
}

double factorial(double n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

void calculateOperation(std::stack<double> &operands, char operation) {
	double a = operands.top();
	operands.pop();
	double b = operands.top();
	operands.pop();
	if (operation == '+') {
		std::cout << cyan << "calculating: " << resetColor << boldCyan <<  a << " + " << b << " = " <<  (a + b) << resetColor << std::endl;
		operands.push(a + b);
	}
	else if (operation == '-'){
		std::cout << cyan << "calculating: " << resetColor << boldCyan <<  b << " - " << a << " = " <<  (b - a) << resetColor << std::endl;
		operands.push(b - a);
	}
	else if (operation == '*'){
		std::cout << cyan << "calculating: " << resetColor << boldCyan <<  a << " * " << b << " = " <<  (a * b) << resetColor << std::endl;
		operands.push(a * b);
	}
	else if (operation == '/'){
		if (b == 0)
			throw InvalidInputForOperation();
		std::cout << cyan << "calculating: " << resetColor << boldCyan <<  a << " / " << b << " = " <<  (a / b) << resetColor << std::endl;
		operands.push(a / b);
	}
	else if (operation == '^'){
		std::cout << cyan << "calculating: " << resetColor << boldCyan <<  a << " ^ " << b << " = " <<  (pow(a, b)) << resetColor << std::endl;
		operands.push(pow(a, b));
	}
	else if (operation == '!'){
		std::cout << cyan << "calculating: " << resetColor << boldCyan <<  a << " ! " << b << " = " <<  (a * factorial(b)) << resetColor << std::endl;
		operands.push(a * factorial(b));
	}
	else
		throw InvalidInputForOperation();
}

void parseInput(char **argv, std::stack<double> &operands){
	try {
		for (int i = 0; argv[1][i] != '\0'; i++) {
			char c = argv[1][i];
			if (c == ' ')
				continue;
			else if (isOperand(c) && !isOperand(argv[1][i + 1])) {
				if (c == 'e') {
					std::cout << yellow <<  "pushing: " << M_E << " Euker's number into stack " << resetColor << std::endl;
					operands.push(M_E);
				}
				else {
					std::cout << yellow <<  "pushing: " << c - '0' << " into stack " << resetColor << std::endl; // "3" - "0" = 3
					operands.push(c - '0');
				}
			} else if (isOperator(c) && operands.size() >= 2) {
				calculateOperation(operands, c);
			} else {
				std::cout << red << "Error: invalid character in this constellation: " << c << resetColor << std::endl;
				throw InvalidInputForOperation();
			}
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

#endif