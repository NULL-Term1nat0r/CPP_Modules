/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:05:55 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/09 13:05:55 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
#define PARSING_HPP

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

class Parsing {
	public:
		static int stoi(std::string);
		static double stod(const std::string& str);
		static bool isValidNumber(std::string s);
		class InvalidConversion : std::exception {
			public:
				virtual const char *what() const throw();
		};
		class InvalidValueRange : std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif