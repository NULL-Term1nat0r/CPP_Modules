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

#include "../includes/PMergeMe.hpp"
#include <ctime>

int main (int argc, char **argv){
	if (argc )
	try {
		clock_t start_time = clock();
		std::list<int> sortedList1 = PMergeSortList(argv);
		clock_t end_time = clock();
		double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << cyan << "Elapsed time: " << elapsed_time << " seconds.\n";
		for(std::list<int>::iterator it = sortedList1.begin(); it != sortedList1.end(); it++)
			std::cout << yellow << " " << *it << " ";
		std::cout << resetColor << std::endl;
	}
	catch (std::exception &e) {
		std::cout << red << e.what() << resetColor << std::endl;
	}
	std::cout << red << "----------------------------------------" << resetColor << std::endl;
	try {
		clock_t start_time = clock();
		std::deque<int> sortedList2 = PMergeSortDeque(argv);
		clock_t end_time = clock();
		double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << cyan << "Elapsed time: " << elapsed_time << " seconds.\n";
		for(std::deque<int>::iterator it = sortedList2.begin(); it != sortedList2.end(); it++)
			std::cout << yellow << " " << *it << " ";
		std::cout << resetColor << std::endl;
	}
	catch (std::exception &e) {
		std::cout << red << e.what() << resetColor << std::endl;
	}

	return 0;
}