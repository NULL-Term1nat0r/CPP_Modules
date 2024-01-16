/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:50 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/08 13:14:11 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
	printColour("constructor called", blue);
	printColour(" for ", blue);
	printColour(getName(), blue);
	setEnergyPoints(50);
	setHitPoints(100);
	setDamagePoints(20);
	std::cout << "\n";
}
ScavTrap::~ScavTrap(){
	printColour("deconstructor called", red);
	printColour(" for ", red);
	printColour(getName(), red);
	std::cout << "\n";
}

void ScavTrap::guardGate(void){
	if (getEnergyPoints() <= 0){
		std::cout << "ScavTrap " << getName() << " doest not have enough energyPoints to perform anny attacks\n";
		return;
	}
	if (getHitPoints() <= 0){
		std::cout << "ScavTrap " << getName() << " doest not have enough hitPoints to perform anny attacks\n";
		return;
	}
	else{
		std::cout << "ScavTrap " << getName() << " is now in gate guarding mode\n";
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void ScavTrap::attack(const std::string &target){
	if (getEnergyPoints() <= 0){
		std::cout << "ScavTrap " << getName() << " doest not have enough energyPoints to perform anny attacks\n";
		return;
	}
	if (getHitPoints() <= 0){
		std::cout << "ScavTrap " << getName() << " doest not have enough hitPoints to perform anny attacks\n";
		return;
	}
	else{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getDamagePoints() << " points of damage\n";
		setEnergyPoints(getEnergyPoints() - 1);
	}
}
