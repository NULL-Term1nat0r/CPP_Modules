/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:18:22 by mdoll             #+#    #+#             */
/*   Updated: 2023/09/07 19:20:04 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed() : _numberVal(0){
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed &other) : _numberVal(other._numberVal) {
}

Fixed::Fixed(const int number) : _numberVal(number << _fractBits) {
}

Fixed::Fixed(const float number) : _numberVal(static_cast<int>(number * (1 << _fractBits))) {
}

Fixed &Fixed::operator=(const Fixed &other){
	setRawBits(other.getRawBits());
	return *this;
}


std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
}

std::istream &operator>>(std::istream &in, Fixed &fixed) {
	std::cout << "provide inoput to create a new fix point class:\n";
	float inputValue;
	in >> inputValue;
	fixed = Fixed(inputValue);
	return in;
}

// -----------------> new functions <-----------------

bool Fixed::operator>(const Fixed &other) const {
	return this->_numberVal > other._numberVal;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->_numberVal < other._numberVal;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->_numberVal <= other._numberVal;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->_numberVal >= other._numberVal;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->_numberVal == other._numberVal;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->_numberVal != other._numberVal;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed newClass((this->toFloat() + other.toFloat()));
	return newClass;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed newClass((this->toFloat() - other.toFloat()));
	return newClass;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed newClass((this->toFloat() * other.toFloat()));
	return newClass;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed newClass((this->toFloat() / other.toFloat()));
	return newClass;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed Fixed::operator++() {
	this->_numberVal++;
	return *this;
}

Fixed Fixed::operator--() {
	this->_numberVal--;
	return *this;
}

int Fixed::getRawBits(void) const {
	return _numberVal;
}

void Fixed::setRawBits(int const raw) {
	_numberVal = raw;
}

int Fixed::toInt() const {
	return _numberVal >> _fractBits;
}

float Fixed::toFloat() const {
	return roundf(static_cast<float>(_numberVal)) / (1 << _fractBits);
}


Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return a;
	return b;
}
