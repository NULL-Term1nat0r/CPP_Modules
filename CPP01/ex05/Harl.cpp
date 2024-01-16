/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:17:36 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/05 19:15:27 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
	std::cout << "Harl constructor called\n";
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
	std::cout << "Harl deconstructor called\n";
}

void Harl::complain(std::string level){
	for (int i = 0; i < 4; i++) {
		if (levels[i].name == level) {
			(this->*levels[i].handler)();
			break;
		}
	}
}

void Harl::debug(void){
	std::cout << red << DEBUG << reset << std::endl;
}
void Harl::info(void){
	std::cout << green << INFO << reset <<std::endl;
}
void Harl::warning(void){
	std::cout <<blue << WARNING << reset << std::endl;
}
void Harl::error(void){
	std::cout << cyan << ERROR<< reset << std::endl;
}
