/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:36:01 by mamesser          #+#    #+#             */
/*   Updated: 2023/12/21 14:07:15 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
Main diffs between chosen containers:

Relevant for FJ:
- Deque: manages its elements with a dynamic array, provides random access
- List: manages its elements as a doubly linked list and does not provide random access

- Deque: provides fast insertions and deletions at both the end and the beginning. Inserting and deleting elements in the middle is relatively slow 
because all elements up to either of both ends may be moved to make room or to fill a gap.
- List: inserting and removing elements is fast at each position, including both ends

Neglible for FJ:
- Deque: Any insertion or deletion of elements other than at the beginning or end invalidates all pointers, references, and iterators that refer to elements of the deque
- List: Inserting and deleting elements does not invalidate pointers, references, and iterators to other elements.

*/


int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cerr << "Not enough arguments provided\n", 1);
	
	// first approach: std::list
	{
		clock_t start = clock();
		std::list< std::pair<int, int> > listy;
		std::list<int> main_chain;
		int additional_value = -1;
		
		try
		{
			print_before(argv);
			create_pairs(&listy, argv, &additional_value);
			sort_pairs(&listy);
			mergeSort(listy.begin(), listy.end(), 0);
			init_main_chain(&main_chain, listy);
			insert_into_main_chain(listy, &main_chain, additional_value);
			print_after(main_chain);
			
			clock_t end = clock();
			std::cout << "Time to process a range of " << main_chain.size() << " elements with std::list: " << static_cast<double>(end - start) / 1000 << " millisec" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	// second approach: std::deque
	{
		clock_t start = clock();
		std::deque< std::pair<int, int> > dequey;
		std::deque<int> main_chain;
		int additional_value = -1;

		try
		{
			print_before(argv);
			create_pairs2(&dequey, argv, &additional_value);
			sort_pairs2(&dequey);
			mergeSort2(dequey.begin(), dequey.end(), 0);
			init_main_chain2(&main_chain, dequey);
			insert_into_main_chain2(dequey, &main_chain, additional_value);
			print_after2(main_chain);
			
			clock_t end = clock();
			std::cout << "Time to process a range of " << main_chain.size() << " elements with std::deque: " << static_cast<double>(end - start) / 1000 << " millisec" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}


/*
	   1       2       3       4       5       6       7        8       9        10       11
	|5, 21| |3, 23| |7, 25| |1, 26| |9, 30| |2, 31| |10, 32| |8, 36| |38, 40| |11, 41| |17, 42|

	main chain: 5, 21, 23, 25, 26, 30, 31, 32, 36, 40, 41, 42
	
	Why insert 17 before 2 next? (worst case number of comparisons in binary search: log2(elements))
	
	Jacobsthal-order range for 17: 1, 3, 5, 7, 9, 21, 23, 25, 26, 30, 31, 32, 36, 40, 41  ==> 15 elements==> (3 comparisons)
	ascending otherwise: 1, 2, 3, 5, 7, 8, 9, 10, 11, 21, 23, 25, 26, 30, 31, 32, 36, 38, 40, 41 ==> 20 elements (4 comparisons)
	
	Jacobsthal-order range for 2: 1, 3, 5, 7, 8, 9, 10, 11, 17, 21, 23, 25, 26, 30 ==> 14 elements --> (3 comparisons)
	ascending otherwise: 1, 3, 5, 7, 9, 21, 23, 25, 26, 30 ==> 10 elements --> (3 comparisons)

	-->  here using Jacobsthal numbers leads to one less comparison in the worst case
	Elemnts = 2^K requires same amount of comparisons as Elements = 2^(K+1) - 1 (worst case)
	e.g. 8 and 15 require same amount of comparisons --> 3 comparisons
*/
