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

#include "../includes/BitcoinExchange.hpp"

int main (int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btcExchange = BitcoinExchange("data.csv", argv[1]);
		btcExchange.getAccountBalance();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}