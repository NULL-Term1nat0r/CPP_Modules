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

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = T();
}

template <typename T>
Array<T>::Array(Array const &src) {
	_array = NULL;
	*this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs){
	if (this != &rhs)
	{
		delete [] this->_array;
		this->_array = new T[rhs._size];
		this->_size = rhs._size;
		for (unsigned int i = 0; i < rhs._size; i++)
			this->_array[i] = rhs._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	if (this->_array)
		delete [] this->_array;
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw Array::OutOfRangeException();
	return this->_array[index];
}

template <typename T>
void Array<T>::print() const {
	if (this->_array)
	{
		for (unsigned int i = 0; i < this->_size; i++)
			std::cout << magenta << this->_array[i] << reset << " ";
		std::cout << std::endl;
	}
	else
		std::cout << magenta << "Array is empty" << reset << std::endl;
}

template <typename T>
const char* Array<T>::OutOfRangeException::what() const throw() {
	return "Index out of range";
}
