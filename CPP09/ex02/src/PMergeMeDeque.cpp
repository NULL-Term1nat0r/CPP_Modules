/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:04:02 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/14 19:04:02 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PMergeMe.hpp"

PMergeDeque::PMergeDeque(char **argv){
	createPairs(argv);
//	std::cout << blue << "after create pairList: " << resetColor << std::endl;
//	printPairList();
	sortPairs();
//	std::cout << blue << "after sort pairList: " << resetColor << std::endl;
//	printPairList();
	recursiveMergeSort(_pairList.begin(), _pairList.end(), 0);
	std::cout << blue << "after recursiveMergeSort: " << resetColor << std::endl;
	printPairList();
	initMainChain();
	std::cout << blue << "after init mainList: " << resetColor << std::endl;
	printMainList();
	std::cout << blue << "--------------------: " << resetColor << std::endl;
	insertIntoMainChain();
	std::cout << blue << "after insert Ino Main Chain: " << resetColor << std::endl;
	printMainList();
}

PMergeDeque::~PMergeDeque(){}

std::deque<int> PMergeSortDeque(char **argv){
	PMergeDeque newPMergeDeque(argv);
	return newPMergeDeque._mainChain;
}

void PMergeDeque::createPairs(char **argv){
	int i;
	for (i = 1; argv[i]; i++) {
		if (argv[i + 1]) {
			try {
				if (Parsing::isValidNumber(argv[i]) && Parsing::isValidNumber(argv[i + 1]))
					_pairList.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
				i++;
			}
			catch (std::exception &e) {
				std::cout << red  << e.what() << resetColor << std::endl;
			}
		}
		else {
			_listIsOdd = true;
			_additionalValue = atoi(argv[i]);
			std::cout << yellow << "Additional value: " << _additionalValue << resetColor << std::endl;
		}
	}
}

void PMergeDeque::sortPairs(){
	for (std::deque<std::pair<int, int> >::iterator it = _pairList.begin(); it != _pairList.end(); it++) {
		if (it->first > it->second){
			std::swap(it->first, it->second);
		}
	}
}

void PMergeDeque::printPairList(){
	for (std::deque<std::pair<int, int> >::iterator it = _pairList.begin(); it != _pairList.end(); it++)
		std::cout << yellow << " " << it->first << " " << it->second << " ";
	std::cout << resetColor << std::endl;
}

void PMergeDeque::printMainList(){
	for (std::deque<int>::iterator it = _mainChain.begin(); it != _mainChain.end(); it++)
		std::cout << yellow << " " << *it << " ";
	std::cout << resetColor << std::endl;
}

bool PMergeDeque::custom_cmp(std::pair<int, int> a, std::pair<int, int> b){
	return a.first < b.first;
}



void PMergeDeque::recursiveMergeSort(std::deque< std::pair<int, int> >::iterator start, std::deque< std::pair<int, int> >::iterator end, size_t size){
	if (size == 0)
		size = _pairList.size();
	if (size == 1)
		return;
	size_t mid = size / 2;
	std::deque< std::pair<int, int> >::iterator midIt = start;
	std::advance(midIt, mid);
	recursiveMergeSort(start, midIt, mid);
	recursiveMergeSort(midIt, end, size - mid);
	std::inplace_merge(start, midIt, end, custom_cmp);
}

void PMergeDeque::initMainChain(){
	for (std::deque<std::pair<int, int> >::iterator it = _pairList.begin(); it != _pairList.end(); it++){
		_mainChain.push_back(it->second);
	}
	_mainChain.push_front(_pairList.begin()->first);
}

void PMergeDeque::binarySearchInsertion(std::deque<int>::iterator end, int val){
	std::deque<int>::iterator it = std::lower_bound(_mainChain.begin(), end, val);
	_mainChain.insert(it, val);
}

void PMergeDeque::insertIntoMainChain(){
	int jacobsthalNumbers[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
	std::deque<int>::iterator chain_delim_it;
	std::deque< std::pair<int, int> >::iterator pair_it;
	std::deque< std::pair<int, int> >::iterator last_jacob_it = _pairList.begin();
	int k = 1;
	while (jacobsthalNumbers[k] <= _pairList.size())
	{
		pair_it = _pairList.begin();
		std::advance(pair_it, jacobsthalNumbers[k] - 1);
		last_jacob_it = pair_it;

		int j = 0;
		while (jacobsthalNumbers[k] - j > jacobsthalNumbers[k - 1])
		{
			chain_delim_it = std::find(_mainChain.begin(), _mainChain.end(), pair_it->second); // is first auch möglich ?
			std::cout << green << "value to be insert: " << pair_it->first << resetColor << std::endl;
			binarySearchInsertion(chain_delim_it, pair_it->first);
			printMainList();
			pair_it--;
			j++;
		}
		k++;
	}
	if (jacobsthalNumbers[k] != _pairList.size()) {
		pair_it = _pairList.end();
		if (pair_it != _pairList.begin()) // vorher checken
			pair_it--;
		while (pair_it != last_jacob_it) {
			chain_delim_it = std::find(_mainChain.begin(), _mainChain.end(), pair_it->second);
			std::cout << green << "value to be insert: " << pair_it->first << resetColor << std::endl;
			binarySearchInsertion(chain_delim_it, pair_it->first);
			printMainList();
			pair_it--;
		}
	}
	if (_listIsOdd)
		binarySearchInsertion(_mainChain.end(), _additionalValue);
}


