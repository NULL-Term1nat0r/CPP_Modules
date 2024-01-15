/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:18:17 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/06 15:18:17 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colors.hpp"
#include <iostream>
#include "../includes/mutantStack.hpp"
#include <list>

//https://en.cppreference.com/w/cpp/container

int main() {
	std::string partition(50, '-');

	std::cout << magenta << partition << std::endl;
	std::cout << "BASIC\n";
	std::cout << partition << resetColor << std::endl;
	{

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout <<  cyan << *it << " " << resetColor;
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}

	std::cout << magenta << partition << std::endl;
	std::cout << "BASIC LIST\n";
	std::cout << partition << resetColor << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout <<  cyan << *it << " " << resetColor;
			++it;
		}
		std::cout << std::endl;
		std::list<int> s(mstack);
	}

	std::cout << magenta << partition << std::endl;
	std::cout << "CONSTANT ITERATOR\n";
	std::cout << partition << resetColor << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout <<  cyan << *it << " " << resetColor;
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}

	std::cout << magenta << partition << std::endl;
	std::cout << "REVERSE ITERATOR\n";
	std::cout << partition << resetColor << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();
		++it;
		--it;
		while (it != ite) {
			std::cout <<  cyan << *it << " " << resetColor;
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}

	std::cout << magenta << partition << std::endl;
	std::cout << "CONST REVERSE ITERATOR\n";
	std::cout << partition << resetColor << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator ite = mstack.rend();
		++it;
		--it;
		while (it != ite)
		{
			std::cout <<  cyan << *it << " " << resetColor;
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}
}
//
//	__deque_iterator<int, const int *, const int &, const int *const *, long>'
//	reverse_iterator<__deque_iterator<int, const int *, const int &, const int *const *, long> >'
//
//
//
//}