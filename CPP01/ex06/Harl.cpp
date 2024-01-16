/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:20:09 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/05 20:01:04 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
	// std::cout << "Harl constructor called\n";
	Array[0] = "DEBUG";
	Array[1] = "INFO";
	Array[2] = "WARNING";
	Array[3] = "ERROR";
	levels[0].name = "DEBUG";
	levels[0].handler = &Harl::debug;
	levels[1].name = "INFO";
	levels[1].handler = &Harl::info;
	levels[2].name = "WARNING";
	levels[2].handler = &Harl::warning;
	levels[3].name = "ERROR";
	levels[3].handler = &Harl::error;
}

Harl::~Harl(){
	// std::cout << "Harl deconstructor called\n";
}

void Harl::complain(int choice){
	for (int i = choice; i < 4; i++) {
		(this->*levels[i].handler)();
		std::cout << "\n";
		}
}


void Harl::print(std::string choice){
	int i;
	for(i = 0; i < 4;i++){
		if (Array[i] == choice)
			break;
	}
	switch (i){
		case 0:
			complain(i);
			break;
		case 1:
			complain(i);
			break;
		case 2:
			complain(i);
			break;
		case 3:
			complain(i);
			break;
		case 4:
			std::cout << "I dont care, now get back to coding\n";
			break;
	}

}

void Harl::debug(void){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << red << DEBUG << reset << std::endl;
}
void Harl::info(void){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << green << INFO << reset <<std::endl;
}
void Harl::warning(void){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout <<blue << WARNING << reset << std::endl;
}
void Harl::error(void){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << cyan << ERROR<< reset << std::endl;
}
