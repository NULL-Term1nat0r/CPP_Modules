/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:11:11 by estruckm             #+#    #+#             */
/*   Updated: 2023/09/13 11:11:11 by estruckm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"
#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define RED_TEXT(text) "\x1b[31m" << text << "\x1b[0m"
#define GREEN_TEXT(text) "\x1b[32m" << text << "\x1b[0m"
#define YELLOW_TEXT(text) "\x1b[33m" << text << "\x1b[0m"
#define BLUE_TEXT(text) "\x1b[34m" << text << "\x1b[0m"
#define MAGENTA_TEXT(text) "\x1b[35m" << text << "\x1b[0m"

int main(){

//	Animal *animal = new Cat();
//
//	animal->setIdea("Zwiebel", 0);
//	animal->setIdea("Zwiebel2", 0);
//
//
//	std::cout << "idea: " << animal->getIdea(0) << std::endl;
//	delete animal;

//	const Animal* j = new Dog();
//	const Animal* i = new Cat();
//
//	std::cout << "\n\n";
//	delete j;
//	delete i;

//	std::cout << "\n\n";
//
//	Animal* zoo[10];
//
//	for (int x = 0; x < 10; x++) {
//		if (x % 2) {
//			zoo[x] = new Dog();
//			zoo[x]->setIdea("Zwiebel", x);
//			std::cout << "Brain idea of dog: " << zoo[x]->getIdea(x) << std::endl;
//		}
//		else {
//			zoo[x] = new Cat();
//			zoo[x]->setIdea("Zwiebel", x);
//			std::cout << "Brain idea of cat: " << zoo[x]->getIdea(x) << std::endl;
//		}
//	}
//
//	std::cout << "\n\n";
//
////	for (int x = 0; x < 10; x++) {
////		std::cout << x << " " << zoo[x]->getType() << " ";
////		zoo[x]->makeSound();
////	}
//
//	std::cout << "\n\n";
//
//
//	for (int x = 0; x < 10; x++) {
//		delete zoo[x];
//	}
//
//
	Cat *dog1 = new Cat();
	dog1->setIdea("idea", 0);

	delete dog1;

//delete dog1;
//delete dog2;
}
