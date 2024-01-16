#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed() : _numberValue(0){
	std::cout << "defualt constructor called\n";
}

Fixed::~Fixed(){
	std::cout << "default deconstructor called\n";
}

Fixed::Fixed(const Fixed &other){
	std::cout << "copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "copy assignment constructor called\n";
	setRawBits(other.getRawBits());
	return *this;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_numberValue = value << _fractBits;
}

Fixed::Fixed(const float value){
	std::cout << "float contructor called\n";
	_numberValue = static_cast<int>(value * (1 << _fractBits));
}


int Fixed::getRawBits() const{
	return _numberValue;
}

void Fixed::setRawBits(const int raw){
	_numberValue = raw;
}

int Fixed::toInt() const{
	return _numberValue >> _fractBits;
}

float Fixed::toFloat() const {
	return roundf(static_cast<float>(_numberValue)) / (1 << _fractBits);
}

std::ostream &operator<<(std::ostream &output, Fixed const &fixed) {
	output << fixed.toFloat();
	return output;
}
