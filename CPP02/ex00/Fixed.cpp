/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:08:03 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/06 10:43:27 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractBits = 8;

Fixed::Fixed() : _numberVal(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy){
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(copy.getRawBits());
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member called" << std::endl;
	return _numberVal;
}

void Fixed::setRawBits(const int raw){
	std::cout << "setRawBits member function called" << std::endl;
	_numberVal = raw;
}
