/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:18:12 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/06 15:18:12 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/span.hpp"
#include "../includes/colors.hpp"

int main (){
	Span sp2 = Span(10000);
	try {
		Span sp1 = Span(6);
		std::cout << magenta << "-------------------TEST-1-(valid parameters)-----------------" << reset << std::endl;
		sp1.addNumber(5);
		sp1.addNumber(3);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		sp1.printContainer();
		sp1.printNumbers();
		std::cout << cyan << "shortest Span: " << sp1.shortestSpan() << reset << std::endl;
		std::cout << cyan << "longest Span: " << sp1.longestSpan() << reset << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << magenta << "-------------------TEST-2-(default constructor)-----------------" << reset <<std::endl;
		Span sp1 = Span(0);
		sp1.printContainer();
		sp1.printNumbers();
		std::cout << cyan << "shortest Span: " << sp1.shortestSpan() << reset << std::endl;
		std::cout << cyan << "longest Span: " << sp1.longestSpan() << reset << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << magenta << "-------------------TEST-3-(same numbers)-----------------" << reset <<std::endl;
		Span sp1 = Span(4);
		sp1.addNumber(5);
		sp1.addNumber(5);
		sp1.addNumber(5);
		sp1.addNumber(5);
		sp1.printContainer();
		sp1.printNumbers();
		std::cout << cyan << "shortest Span: " << sp1.shortestSpan() << reset << std::endl;
		std::cout << cyan << "longest Span: " << sp1.longestSpan() << reset << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << magenta << "-------------------TEST-4------------------" << reset <<std::endl;
		Span sp1(10000);
		sp1.fillContainer(100, -10000, 200000);
		sp1.printContainer();
		sp1.printNumbers();
		std::cout << cyan << "shortest Span: " << sp1.shortestSpan() << reset << std::endl;
		std::cout << cyan << "longest Span: " << sp1.longestSpan() << reset << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}