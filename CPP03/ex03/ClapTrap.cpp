/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:44:39 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/11 18:44:28 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Julie"), _hitPoints(10), _energyPoints(10), _damagePoints(5){
	printColour("default constructor from parent  called", blue);
	printColour(" for ", blue);
	printColour(_name, blue);
	std::cout << "\n";
}
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _damagePoints(5){
	printColour("constructor from parent  called", blue);
	printColour(" for ", blue);
	printColour(_name, blue);
	std::cout << "\n";
}

ClapTrap::~ClapTrap(){
	printColour("deconstructor from parent called\n", red);
}

ClapTrap::ClapTrap(const ClapTrap &other){

	*this = other;
	printColour("copy constructor from parent called", cyan);
	printColour(" for ", cyan);
	printColour(other._name, cyan);
	std::cout << "\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other){

	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setDamagePoints(other.getDamagePoints());
	setName(other.getName());
	printColour("copy asignment constructor from parent called", yellow);
	printColour(" for ", yellow);
	printColour(other._name, yellow);
	std::cout << "\n";
	return *this;
}

unsigned int ClapTrap::getHitPoints() const{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getDamagePoints() const{
	return (this->_damagePoints);
}

std::string ClapTrap::getName() const{
	return (this->_name);
}
//----------

void ClapTrap::setHitPoints(unsigned int value){
	this->_hitPoints = value;
}

void ClapTrap::setEnergyPoints(unsigned int value){
	this->_energyPoints = value;
}

void ClapTrap::setDamagePoints(unsigned int value){
	this->_damagePoints = value;
}

void ClapTrap::setName(std::string value){
	this->_name = value;
}

void ClapTrap::attack(const std::string &target){
	if (_energyPoints <= 0){
		 std::cout << "ClapTrap " << _name << " does not have enough energy points to perform attacks\n";
		 return;
	}else if (_hitPoints <= 0){
		std::cout << "ClapTrap " << _name << " does not have enough hit points to perform attacks\n";
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damagePoints << " points of damage!\n";
	_energyPoints--;
}


void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints <= 0){
		std::cout << "Clap Trap " << _name << " is dead in case you didn't notice\n";
		return;
	}
	std::cout << "Clap Trap " << _name << " took " << amount << " points of damage\n";
	if (_hitPoints < amount){
		_hitPoints = 0;
	}else
		_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_hitPoints <= 0){
		std::cout << "Clap Trap " << _name << " is dead in case you didn't notice\n";
		return;
	}if (_energyPoints <= 0){
		std::cout << "Clap Trap " << _name << " has zero energy points left and can't repair\n";
		return;
	}else{
		std::cout << "Clap Trap " << _name << "is repaired and recieved " << amount << " hitPoints\n";
		_hitPoints += amount;
		_energyPoints--;
	}
}

void ClapTrap::getDataFromPlayer(){
	std::cout << "PlayerData:\n";
	std::cout << "name: " << getName() << std::endl;
	std::cout << "hitPoints: " << getHitPoints() << std::endl;
	std::cout << "damagePoints: " << getDamagePoints() << std::endl;
	std::cout << "energyPoints: " << getEnergyPoints() << std::endl;
}

std::ostream &operator<<(std::ostream &output, ClapTrap const &fixed) {
	output << fixed.getHitPoints();
	output << fixed.getDamagePoints();
	output << fixed.getEnergyPoints();
	output << fixed.getName();
	return output;
}

void printColour(std::string output, std::string colour){
	std::cout << colour << output << reset;
}
