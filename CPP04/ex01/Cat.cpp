/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:04:56 by estruckm             #+#    #+#             */
/*   Updated: 2023/09/13 11:04:56 by estruckm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"
#include "Cat.hpp"

// Implement class methods here

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain_attribute = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat constructor with type called" << std::endl;
	this->brain_attribute = new Brain();
}

Cat::Cat(const Cat &other)
{
	*this = other;
	delete this->brain_attribute;
	this->brain_attribute = other.brain_attribute;
	this->_type = other.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->brain_attribute;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	if(this->brain_attribute != NULL)
		delete this->brain_attribute;
	this->_type = other.getType();
	this->brain_attribute = new Brain(*other.brain_attribute);
	std::cout << "Cat copy assignment constructor called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "cat makes meeeooooow...\n";
}

Brain *Cat::getBrain() const{
	return brain_attribute;
}

const std::string Cat::getIdea(int index) const{
//	std::cout << getBrain()->getIdea(index) << std::endl;
	return (getBrain()->getIdea(index));
}

void Cat::setIdea(std::string idea, int index) const{
	this->getBrain()->setIdea(index, idea);
}