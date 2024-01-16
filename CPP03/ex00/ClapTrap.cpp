/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:44:39 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/08 11:12:44 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _damagePoints(0){
	printColour("constructor called", blue);
	printColour(" for ", blue);
	printColour(_name, blue);
	std::cout << "\n";
}

ClapTrap::~ClapTrap(){
	printColour("deconstructor called\n", red);

}

ClapTrap::ClapTrap(const ClapTrap &other){
	printColour("copy constructor called", cyan);
	printColour(" for ", cyan);
	printColour(other._name, cyan);
	std::cout << "\n";

	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other){
	printColour("copy asignment constructor called", yellow);
	printColour(" for ", yellow);
	printColour(other._name, yellow);
	std::cout << "\n";
	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setDamagePoints(other.getDamagePoints());
	setName(other.getName());
	return *this;
}

unsigned int ClapTrap::getHitPoints() const{
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const{
	return _energyPoints;
}

unsigned int ClapTrap::getDamagePoints() const{
	return _damagePoints;
}

std::string ClapTrap::getName() const{
	return _name;
}
//----------

void ClapTrap::setHitPoints(const unsigned int value){
	_hitPoints = value;
}

void ClapTrap::setEnergyPoints(const unsigned int value){
	_energyPoints = value;
}

void ClapTrap::setDamagePoints(const unsigned int value){
	_damagePoints = value;
}

void ClapTrap::setName(const std::string value){
	_name = value;
}


void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

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
	std::cout << "Clap Trap " << _name << " tookt " << amount << " points of damage\n";
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

void ClapTrap::getDataFromPlayer(const ClapTrap claptrap){
	std::cout << "PlayerData:\n";
	std::cout << "name: " << claptrap.getName() << std::endl;
	std::cout << "hitPoints: " << claptrap.getHitPoints() << std::endl;
	std::cout << "damagePoints: " << claptrap.getDamagePoints() << std::endl;
	std::cout << "energyPoints: " << claptrap.getEnergyPoints() << std::endl;
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
