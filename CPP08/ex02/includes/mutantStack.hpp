/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:47:36 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/07 19:05:40 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

private:

};

#include "mutantStack.tpp"

#endif