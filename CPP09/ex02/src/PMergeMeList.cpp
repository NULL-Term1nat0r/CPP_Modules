/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:49:25 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/11 18:49:25 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PMergeMe.hpp"

PMergeList::PMergeList(char **argv){
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

PMergeList::~PMergeList(){}

const char* InvalidConversion::what() const throw() {
	return "Invalid Value Conversion\n";
}

std::list<int> PMergeSortList(char **argv){
	PMergeList newPMergeList(argv);
	return newPMergeList._mainChain;
}

void PMergeList::createPairs(char **argv){
	int i;
	for (i = 1; argv[i]; i++) {
		if (argv[i + 1]) {
			try {
				if (Parsing::isValidNumber(argv[i]) && Parsing::isValidNumber(argv[i + 1]))
					throw InvalidConversion();
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

void PMergeList::sortPairs(){
	for (std::list<std::pair<int, int> >::iterator it = _pairList.begin(); it != _pairList.end(); it++) {
		if (it->first > it->second){
			std::swap(it->first, it->second);
		}
	}
}

void PMergeList::printPairList(){
	std::cout << boldBackgroundCyan << "List: " << resetColor << std::endl;
	for (std::list<std::pair<int, int> >::iterator it = _pairList.begin(); it != _pairList.end(); it++) {
		std::cout << cyan << it->first << " " << it->second << resetColor << " ";
	}
	std::cout <<  resetColor << std::endl;
}

void PMergeList::printMainList(){
	std::cout << boldBackgroundMagenta << "List: " << resetColor << std::endl;
	for (std::list<int>::iterator it = _mainChain.begin(); it != _mainChain.end(); it++) {
		std::cout << magenta << *it << " ";
	}
	std::cout <<  resetColor << std::endl;
}

bool	PMergeList::custom_cmp(std::pair<int, int> a, std::pair<int, int> b)
{
	return (a.second < b.second);
}

void	PMergeList::recursiveMergeSort(std::list< std::pair<int, int> >::iterator start, std::list< std::pair<int, int> >::iterator end, size_t size)
{
	if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size <= 1)
		return ;

	size_t firstHalf = size / 2;
	size_t secondHalf = size - firstHalf;
	std::list< std::pair<int, int> >::iterator center = start;
	std::advance(center, firstHalf);

	recursiveMergeSort(start, center, firstHalf);
	recursiveMergeSort(center, end, secondHalf);
	std::inplace_merge(start, center, end, PMergeList::custom_cmp);
}

void	PMergeList::initMainChain(){
	for (std::list< std::pair<int, int> >::iterator it=_pairList.begin(); it != _pairList.end(); ++it)
	_mainChain.push_back(it->second);
	if (!_pairList.empty())
		_mainChain.push_front(_pairList.begin()->first);
}

void	PMergeList::binarySearchInsertion(std::list<int>::iterator end, int val)
{
	std::list<int>::iterator place_to_insert = std::lower_bound(_mainChain.begin(), end, val);
	_mainChain.insert(place_to_insert, val);
}

void	PMergeList::insertIntoMainChain()
{
	int jacobsthalNumbers[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
	std::list<int>::iterator chain_delim_it;
	std::list< std::pair<int, int> >::iterator pair_it;
	std::list< std::pair<int, int> >::iterator last_jacob_it = _pairList.begin();
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



