/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:20:48 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/11 17:01:46 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	printColour("FragTrap default constructor called", blue);
	printColour(" for ", blue);
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	this->_damagePoints = 30;
	std::cout << "fragtrap damage: " << FragTrap::_damagePoints << std::endl;
	std::cout << "\n";
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name){
	printColour("FragTrap constructor called", blue);
	printColour(" for ", blue);
	this->_name = name;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	this->_damagePoints = 30;
	std::cout << "\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy){
	*this = copy;
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap&src){
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_damagePoints = src._damagePoints;
	std::cout << "FragTrap copy asignment onstructor called\n";
	return *this;
}


FragTrap::~FragTrap(){
	printColour("Frag Trap deconstructor called", red);
	printColour(" for ", red);
	printColour(getName(), red);
	std::cout << "\n";
}

void FragTrap::highFivesGuys(){
	if (getEnergyPoints() <= 0){
		std::cout << "FragTrap " << getName() << " doest not have enough energyPoints to perform any high five\n";
		return;
	}
	if (getHitPoints() <= 0){
		std::cout << "FragTrap " << getName() << " doest not have enough hitPoints to perform any high five\n";
		return;
	}
	else{
		std::cout << "FragTrap " << getName() << " requets a high five\n";
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

unsigned int FragTrap::getFragDamage(){
	return this->_damagePoints;
}


