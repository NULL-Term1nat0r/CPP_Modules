/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:34:54 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/05 11:43:50 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Headers.h"

template <typename T>
class Array {
public:
	Array();
	explicit Array(unsigned int n);
	Array(Array const &src);
	Array &operator=(Array const &rhs);
	unsigned int size() const;
	void print() const;
	T &operator[](unsigned int i);
	~Array();

	class OutOfRangeException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
private:
	T *_array;
	unsigned int _size;
};

#include "Array.tpp"
#endif
