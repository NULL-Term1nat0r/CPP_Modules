/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:20:48 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/08 13:37:36 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

	// public:
	// 	FragTrap(const std::string &name);
	// 	~FragTrap();

	// 	void highFives(void);
	// 	void attack(const std::string &target);

FragTrap::FragTrap(const std::string &name) : ClapTrap(name){
	printColour("FragTrap constructor called", blue);
	printColour(" for ", blue);
	printColour(getName(), blue);
	setEnergyPoints(100);
	setHitPoints(100);
	setDamagePoints(30);
	std::cout << "\n";
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


