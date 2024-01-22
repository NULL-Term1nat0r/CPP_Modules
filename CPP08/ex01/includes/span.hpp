/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:39:40 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/06 16:39:40 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include "colors.hpp"
#include <vector>
#include <limits>
#include <algorithm>

class Span {
	private:
		unsigned int _spanLimit;
		std::vector<int> _spanContainer;
		int _smallestNumber;
		int _biggestNumber;
	public:
		Span(unsigned int n);
		Span();
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		~Span();
		void fillContainer(int n, int min, int max);
		void printContainer();
		void printNumbers();
		int findSmallestNumber();
		void findNumbers();
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		class FullException: public std::exception {
		public:
			virtual const char *what() const throw();
		};
		class NoSpanException: public std::exception {
		public:
			virtual const char *what() const throw();
		};

};

#endif