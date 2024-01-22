/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:44:05 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/06 16:44:05 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/span.hpp"

Span::Span(unsigned int n) : _spanLimit(n) {}
Span::Span() : _spanLimit(0) {}
Span::Span(Span const &src) {
	*this = src;
}
Span &Span::operator=(Span const &rhs) {
	if (this != &rhs)
	{
		this->_spanLimit = rhs._spanLimit;
		this->_spanContainer = rhs._spanContainer;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (this->_spanContainer.size() >= this->_spanLimit)
		throw Span::FullException();
	this->_spanContainer.push_back(n);
}

int Span::shortestSpan() {
	if (_spanContainer.size() <= 1)
		throw Span::NoSpanException();
	int shortest = INT_MAX;
	std::vector<int> tmp_storage = _spanContainer;
	std::sort(tmp_storage.begin(), tmp_storage.end());
	for (std::vector<int>::const_iterator it = tmp_storage.begin(); it + 1 < tmp_storage.end(); it++) {
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
	}
	return shortest;
}

int Span::longestSpan(){
	if (_spanContainer.size() <= 1)
		throw Span::NoSpanException();
	int min_element = *std::min_element(_spanContainer.begin(), _spanContainer.end());
	int max_element = *std::max_element(_spanContainer.begin(), _spanContainer.end());
	return max_element - min_element;
}

void Span::fillContainer(int n, int min, int max){
	if (n > this->_spanLimit)
		throw Span::FullException();
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < n; i++)
		this->_spanContainer.push_back(rand() % (max - min) + min);
}

void Span::findNumbers(){
	if (this->_spanContainer.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int>::iterator it = this->_spanContainer.begin();
	std::vector<int>::iterator end = this->_spanContainer.end();
	_smallestNumber = *it;
	_biggestNumber = *it;
	while (it != end)
	{
		if (*it < _smallestNumber)
			_smallestNumber = *it;
		else if (*it > _biggestNumber)
			_biggestNumber = *it;
		it++;
	}
}

void Span::printContainer(){
	std::vector<int>::iterator it = this->_spanContainer.begin();
	std::vector<int>::iterator itr = this->_spanContainer.end();
	findNumbers();
	while (it != itr)
	{
		if (*it == this->_smallestNumber)
			std::cout << green << *it << reset << " ";
		else if (*it == this->_biggestNumber)
			std::cout << red << *it << reset << " ";
		else
			std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void Span::printNumbers() {
	std::cout << "smallest number: " << this->_smallestNumber << std::endl;
	std::cout << "biggest number: " << this->_biggestNumber << std::endl;
}

const char *Span::FullException::what() const throw() {
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "Span is empty or contains only one element";
}

