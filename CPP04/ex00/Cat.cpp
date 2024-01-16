/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:54:57 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/18 14:25:46 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called\n";
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
	std::cout << "Cat copy constructor called\n";
	*this = cat;
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout << "Cat copy constructor with arg called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat	&Cat::operator=(Cat const &cat)
{
	if (this == &cat)
		return *this;
	this->_type = cat.getType();
	return *this;
}

void	Cat::makeSound() const{
	std::cout << "Meow, Meow ...\n";
}
