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

int main (int argc, char **argv){

	std::list<int> sortedList1 = PMergeSortList(argv);
	for(std::list<int>::iterator it = sortedList1.begin(); it != sortedList1.end(); it++)
		std::cout << yellow << " " << *it << " ";
	std::cout << resetColor << std::endl;
	std::deque<int> sortedList2 = PMergeSortDeque(argv);
	for(std::deque<int>::iterator it = sortedList2.begin(); it != sortedList2.end(); it++)
		std::cout << yellow << " " << *it << " ";
	std::cout << resetColor << std::endl;

	return 0;
}