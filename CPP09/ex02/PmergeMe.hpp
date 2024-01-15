/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:35:16 by mamesser          #+#    #+#             */
/*   Updated: 2023/12/21 12:10:59 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <deque>
# include <string>
# include <iostream>
# include <utility>
# include <algorithm>
# include <climits>
# include <ctime>

class CustomException : public std::runtime_error
{
	public:
		explicit CustomException(std::string msg): runtime_error(msg) {}
};

void	print_before(char **argv);

void	create_pairs(std::list< std::pair<int, int> > *listy, char **argv, int *additional_value);
void	sort_pairs(std::list< std::pair<int, int> > *listy);
void	mergeSort(std::list< std::pair<int, int> >::iterator start, std::list< std::pair<int, int> >::iterator end, size_t size);
void	init_main_chain(std::list<int> *main_chain, std::list< std::pair<int, int> > listy);
void	binary_search_insertion(std::list<int> *main_chain, std::list<int>::iterator end, int val);
void	binary_search_insertion_alt(std::list<int> *main_chain, std::list<int>::iterator start, std::list<int>::iterator end, int val, size_t size);
void	insert_into_main_chain(std::list< std::pair<int, int> > listy, std::list<int> *main_chain, int additional_value);
void	print_after(std::list<int> main_chain);

void	create_pairs2(std::deque< std::pair<int, int> > *dequey, char **argv, int *additional_value);
void	sort_pairs2(std::deque< std::pair<int, int> > *dequey);
void	mergeSort2(std::deque< std::pair<int, int> >::iterator start, std::deque< std::pair<int, int> >::iterator end, size_t size);
void	init_main_chain2(std::deque<int> *main_chain, std::deque< std::pair<int, int> > dequey);
void	binary_search_insertion2(std::deque<int> *main_chain, std::deque<int>::iterator end, int val);
void	insert_into_main_chain2(std::deque< std::pair<int, int> > dequey, std::deque<int> *main_chain, int additional_value);
void	print_after2(std::deque<int> main_chain);

#endif
