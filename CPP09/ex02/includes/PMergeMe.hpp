/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:49:37 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/11 18:49:37 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cctype>
#include <ctype.h>

#include "Colors.hpp"
#include "Parsing.hpp"

class InvalidConversion : public std::exception
{
public:
	virtual const char *what() const throw();
};
//void	print_before(char **argv);

class PMergeList {
	public:
		PMergeList(char**argv);
		~PMergeList();
		void fillJacobNumbers();
		void createPairs(char **argv);
		void sortPairs();
		void printPairList();
		void printMainList();
		static bool custom_cmp(std::pair<int, int> a, std::pair<int, int> b);
		void recursiveMergeSort(std::list< std::pair<int, int> >::iterator start, std::list< std::pair<int, int> >::iterator end, size_t size);
		void binarySearchInsertion(std::list<int>::iterator end, int val);
		void insertIntoMainChain();
		void initMainChain();


		std::list<std::pair<int, int > > _pairList;
		std::list<int> _mainChain;
		bool _listIsOdd;
		int _additionalValue;
};

class PMergeDeque {
	public:
		PMergeDeque(char**argv);
		~PMergeDeque();
		void fillJacobNumbers();
		void createPairs(char **argv);
		void sortPairs();
		void printPairList();
		void printMainList();
		static bool custom_cmp(std::pair<int, int> a, std::pair<int, int> b);
		void recursiveMergeSort(std::deque< std::pair<int, int> >::iterator start, std::deque< std::pair<int, int> >::iterator end, size_t size);
		void binarySearchInsertion(std::deque<int>::iterator end, int val);
		void insertIntoMainChain();
		void initMainChain();

		std::deque<std::pair<int, int > > _pairList;
		std::deque<int> _mainChain;
		bool _listIsOdd;
		int _additionalValue;
};
		std::list<int> PMergeSortList(char **argv);
		std::deque<int> PMergeSortDeque(char **argv);



#endif