/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:04:54 by estruckm             #+#    #+#             */
/*   Updated: 2023/09/13 11:04:54 by estruckm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"
#include "Dog.hpp"

// Implement class methods here

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->brain_attribute = new Brain();
	setType("Dog");
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain_attribute;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	if(this->brain_attribute != NULL)
		delete this->brain_attribute;
	this->_type = other.getType();
	this->brain_attribute = new Brain(*other.brain_attribute);
	std::cout << "Dog copy assignment constructor called" << std::endl;
	return *this;
}


void Dog::makeSound() const {
	std::cout << "dog makes wau wau...\n";
}

	Brain *Dog::getBrain() const{
	return brain_attribute;
}

const std::string Dog::getIdea(int index) const{
	return (getBrain()->getIdea(index));
}

void Dog::setIdea(std::string idea, int index) const{
	this->getBrain()->setIdea(index, idea);
}