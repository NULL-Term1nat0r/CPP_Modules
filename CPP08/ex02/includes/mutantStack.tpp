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

#include "mutantStack.hpp"

// Inside mutantStack.tpp

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &mutant)
{
	*this = mutant;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &mutant)
{
	return *this;
}

//------------------iterator function templates------------------

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return this->c.rend();
}
