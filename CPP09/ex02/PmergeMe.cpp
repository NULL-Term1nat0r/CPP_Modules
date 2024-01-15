/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:35:13 by mamesser          #+#    #+#             */
/*   Updated: 2023/12/21 14:14:24 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

////////////////////////// shared functions ///////////////////////////////////

bool	custom_cmp(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.second < b.second)
		return (1);
	return (0);
}

void	print_before(char **argv)
{
	int i = 1;
	int error = 0;
	
	std::cout << "Before: ";
	while (argv[i])
	{
		std::string input = argv[i];
		std::cout << input << " ";
		if (input.size() > 11 || std::atol(input.c_str()) > INT_MAX || std::atol(input.c_str()) < 0)
			error = 1;
		for (size_t j = 0; j < input.size(); j++)
		{
			if (!isdigit(input[j]))
				error = 1;
		}
		i++;
	}
	std::cout << "\n";
	if (error == 1)
		throw CustomException("Error: input is invalid");
}


////////////////////////// Deque functions /////////////////////////////////////

void	create_pairs2(std::deque< std::pair<int, int> > *dequey, char **argv, int *additional_value)
{
	int i = 1;
	
	while (argv[i])
	{
		if (argv[i] && argv[i + 1])
		{
			std::pair<int, int> pair_temp(std::atoi(argv[i]), std::atoi(argv[i + 1]));
			dequey->push_back(pair_temp);
			i += 2;
		}
		else
		{
			*additional_value = std::atoi(argv[i]);
			i++;
		}
	}
}

void	sort_pairs2(std::deque< std::pair<int, int> > *dequey)
{
	for (std::deque< std::pair<int, int> >::iterator it = dequey->begin(); it != dequey->end(); ++it)
	{
		if (it->first > it->second)
		{
			int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

void	mergeSort2(std::deque< std::pair<int, int> >::iterator start, std::deque< std::pair<int, int> >::iterator end, size_t size)
{
	if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size <= 1)
		return ;
		
	size_t firstHalf = size / 2;
	size_t secondHalf = size - firstHalf;
	std::deque< std::pair<int, int> >::iterator center = start + firstHalf;

	mergeSort2(start, center, firstHalf);
	mergeSort2(center, end, secondHalf);
	std::inplace_merge(start, center, end, &custom_cmp);
}

void	init_main_chain2(std::deque<int> *main_chain, std::deque< std::pair<int, int> > dequey)
{
	for (std::deque< std::pair<int, int> >::iterator it = dequey.begin(); it != dequey.end(); ++it)
		main_chain->push_back(it->second);
	if (!dequey.empty())
		main_chain->push_front(dequey.begin()->first);
}

void	binary_search_insertion2(std::deque<int> *main_chain, std::deque<int>::iterator end, int val)
{
	std::deque<int>::iterator place_to_insert = std::lower_bound(main_chain->begin(), end, val);
	main_chain->insert(place_to_insert, val);
}

void	insert_into_main_chain2(std::deque< std::pair<int, int> > dequey, std::deque<int> *main_chain, int additional_value)
{
	size_t Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
	int k = 1;

	std::deque<int>::iterator chain_delim_it;
	std::deque< std::pair<int, int> >::iterator pair_it;
	std::deque< std::pair<int, int> >::iterator last_jacob_it = dequey.begin();

	while (Jacobsthal[k] <= dequey.size())
	{
		pair_it = dequey.begin() + (Jacobsthal[k] - 1);
		last_jacob_it = pair_it;

		int j = 0;
		while (Jacobsthal[k] - j > Jacobsthal[k - 1])
		{
			chain_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
			chain_delim_it--;
			binary_search_insertion2(main_chain, chain_delim_it, pair_it->first);
			pair_it--;
			j++;
		}
		k++;
	}
	
	if (Jacobsthal[k] != dequey.size())
	{
		pair_it = dequey.end();
		if (pair_it != dequey.begin())
			pair_it--;
		while (pair_it != last_jacob_it)
		{
			chain_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
			chain_delim_it--;
			binary_search_insertion2(main_chain, chain_delim_it, pair_it->first);
			pair_it--;
		}
	}

	if (additional_value != -1)
	{
		binary_search_insertion2(main_chain, main_chain->end(), additional_value);
	}
}

void	print_after2(std::deque<int> main_chain)
{
	std::cout << "After: ";
	for (std::deque<int>::iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
}



////////////////////////// List functions //////////////////////////////////////

void	create_pairs(std::list< std::pair<int, int> > *listy, char **argv, int *additional_value)
{
	int i = 1;
	
	while (argv[i])
	{
		if (argv[i] && argv[i + 1])
		{
			std::pair<int, int> pair_temp(std::atoi(argv[i]), std::atoi(argv[i + 1]));
			listy->push_back(pair_temp);
			i += 2;
		}
		else
		{
			*additional_value = std::atoi(argv[i]);
			i++;
		}
	}
}

void	sort_pairs(std::list< std::pair<int, int> > *listy)
{
	for (std::list< std::pair<int, int> >::iterator it = listy->begin(); it != listy->end(); ++it)
	{
		if (it->first > it->second)
		{
			int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

void	mergeSort(std::list< std::pair<int, int> >::iterator start, std::list< std::pair<int, int> >::iterator end, size_t size)
{
	if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size <= 1)
		return ;
		
	size_t firstHalf = size / 2;
	size_t secondHalf = size - firstHalf;
	std::list< std::pair<int, int> >::iterator center = start;
	std::advance(center, firstHalf);
	
	mergeSort(start, center, firstHalf);
	mergeSort(center, end, secondHalf);
	std::inplace_merge(start, center, end, &custom_cmp);
}

void	init_main_chain(std::list<int> *main_chain, std::list< std::pair<int, int> > listy)
{
	for (std::list< std::pair<int, int> >::iterator it=listy.begin(); it != listy.end(); ++it)
		main_chain->push_back(it->second);
	if (!listy.empty())
		main_chain->push_front(listy.begin()->first);
}

void	binary_search_insertion(std::list<int> *main_chain, std::list<int>::iterator end, int val)
{
	std::list<int>::iterator place_to_insert = std::lower_bound(main_chain->begin(), end, val);
	main_chain->insert(place_to_insert, val);
}

void	insert_into_main_chain(std::list< std::pair<int, int> > listy, std::list<int> *main_chain, int additional_value)
{
	size_t Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
	int k = 1;

	std::list<int>::iterator chain_delim_it;
	std::list< std::pair<int, int> >::iterator pair_it;
	std::list< std::pair<int, int> >::iterator last_jacob_it = listy.begin();
	
	while (Jacobsthal[k] <= listy.size())
	{
		pair_it = listy.begin();
		std::advance(pair_it, Jacobsthal[k] - 1);
		last_jacob_it = pair_it;

		int j = 0;
		while (Jacobsthal[k] - j > Jacobsthal[k - 1])
		{
			chain_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
			chain_delim_it--;
			// binary_search_insertion_alt(main_chain, main_chain->begin(), chain_delim_it, pair_it->first, 0);
			binary_search_insertion(main_chain, chain_delim_it, pair_it->first);
			pair_it--;
			j++;
		}
		k++;
	}
	
	if (Jacobsthal[k] != listy.size())
	{
		pair_it = listy.end();
		if (pair_it != listy.begin())
			pair_it--;
		while (pair_it != last_jacob_it)
		{
			chain_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
			chain_delim_it--;
			// binary_search_insertion_alt(main_chain, main_chain->begin(), chain_delim_it, pair_it->first, 0);
			binary_search_insertion(main_chain, chain_delim_it, pair_it->first);
			pair_it--;
		}
	}

	if (additional_value != -1)
	{
		// binary_search_insertion_alt(main_chain, main_chain->begin(), main_chain->end(), additional_value, 0);
		binary_search_insertion(main_chain, main_chain->end(), additional_value);
	}
}

void	print_after(std::list<int> main_chain)
{
	std::cout << "After: ";
	for (std::list<int>::iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
}
