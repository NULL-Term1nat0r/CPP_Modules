/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:06:09 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/12 12:03:40 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("default animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor with type called\n";
}

Animal::Animal(Animal const &animal)
{
	*this = animal;
	std::cout << "Animal copy constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal	&Animal::operator=(Animal const &animal)
{
	if (this == &animal)
		return *this;
	this->_type = animal.getType();
	std::cout << "Animal copy asignment constructor called\n";
	return (*this);
}

void	Animal::setType(std::string type)
{
	this->_type = type;
}

std::string	Animal::getType(void) const{
	return this->_type;
}

void	Animal::makeSound() const{
	std::cout << "Screams in animal ...\n";
}
