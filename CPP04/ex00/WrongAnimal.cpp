/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:55:44 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/12 12:11:31 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

WrongAnimal::WrongAnimal() : _wrong_type("default wrong animal")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrong_animal)
{
	std::cout << "WrongAnimal copy constructor called\n";
	*this = wrong_animal;
}

WrongAnimal::WrongAnimal(std::string type) : _wrong_type(type)
{
	std::cout << "WrongAnimal constructor with arg called\n";
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &wrong_animal)
{
	if (this == &wrong_animal)
		return *this;
	this->_wrong_type = wrong_animal.getWrongType();
	return *this;
}

std::string		WrongAnimal::getWrongType(void) const{
	return this->_wrong_type;
}

void	WrongAnimal::setWrongType(std::string wrong_type)
{
	this->_wrong_type = wrong_type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

void	WrongAnimal::makeWrongSound() const{
	std::cout << "Screams in wrong animal wuhaaaaaa!\n";
}
