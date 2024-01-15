/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:22:48 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/08 13:22:48 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include "../includes/Utils.hpp"

int main (int argc, char **argv){

	if (argc != 2) {
		std::cout << "Usage: 3 3 4 + + " << std::endl;
		return 1;
	}
	std::stack<double> operands;
	parseInput(argv, operands);
	if (operands.size() > 1) {
		std::cout << red << "Error: operator number is too less to do a another operation and finish the calculation" << resetColor << std::endl;
		return 0;
	}
	std::cout << cyan << "result: " << resetColor << boldBackgroundCyan << operands.top() << resetColor << std::endl;
	return 0;
}