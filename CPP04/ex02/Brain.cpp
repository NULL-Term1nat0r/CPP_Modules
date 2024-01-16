/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:04:38 by estruckm             #+#    #+#             */
/*   Updated: 2023/09/13 11:04:38 by estruckm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"
#include "Brain.hpp"

// Implement class methods here

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i ++)
		_ideas[i] = other._ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other) {
		for (int i = 0; i < 100; i ++) {
			_ideas[i] = other._ideas[i];
		}
	}
	std::cout << "Brain copy assignment constructor called" << std::endl;
	return *this;
}

void Brain::setIdea(int index, std::string idea) {
	if (index > 99 || index < 0)
	{
		std::cout << "Wrong index has to be between 0 and 99!\n";
		return ;
	}
	this->_ideas[index] = idea;
}

const std::string Brain::getIdea(int index) const {
	if (index > 99 || index < 0)
	{
		std::cout << "Wrong index has to be between 0 and 99!\n";
		return "";
	}
	return this->_ideas[index];
}
