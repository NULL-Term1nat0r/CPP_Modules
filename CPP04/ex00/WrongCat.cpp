/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:56:03 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/12 12:12:04 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(WrongCat const &wrong_cat) : WrongAnimal(wrong_cat)
{
	std::cout << "WrongCat copy constructor called\n";
	*this = wrong_cat;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat constructor with arg called\n";
}

WrongCat	&WrongCat::operator=(WrongCat const &wrong_cat)
{
	if (this == &wrong_cat)
		return *this;
	this->_wrong_type = wrong_cat.getWrongType();
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

void	WrongCat::makeWrongSound() const{
	std::cout << "Wrong meow, meowdw93r2....\n";
}
