/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:29:27 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/08 11:26:41 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (){

	ClapTrap Guillaume("Guillaume");
	ClapTrap Bethan("Bethan");
	ClapTrap Alberto(Bethan);

	Guillaume.getDataFromPlayer(Guillaume);
	Bethan.getDataFromPlayer(Bethan);
	Alberto.getDataFromPlayer(Alberto);

	std::cout << "\n";
	Guillaume.attack("Bethan");
	Guillaume.beRepaired(10);
	Guillaume.attack("Bethan");
	Guillaume.attack("Bethan");
	Bethan.takeDamage(0);
	std::cout << "\n";
	Bethan.beRepaired(10);
	Bethan.attack("Alberto");
	Alberto.takeDamage(11);
	std::cout << "\n";
	Alberto.attack("Guillaume");
	std::cout << "\n";
	Guillaume = Bethan;
	Guillaume.attack("Bethan");
	Bethan.beRepaired(100);
	std::cout << "\n";

	Guillaume.getDataFromPlayer(Guillaume);
	Bethan.getDataFromPlayer(Bethan);
	Alberto.getDataFromPlayer(Alberto);
	
	return 0;
}
