/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:57:15 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/18 14:35:16 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

int main()
{
	// std::string partition(50, '-');

	// std::cout << partition << std::endl;
	// std::cout << "ANIMAL\n";
	// std::cout << partition << std::endl;
	// {
	// 	Animal animal = new Animal();
	// 	animal->makeSound();
	// 	delete animal;
	// }

	// std::cout << partition << std::endl;
	// std::cout << "DOG\n";
	// std::cout << partition << std::endl;
	// {
	// 	Animal* dog = new Dog();
	// 	dog->setType("Labrador");
	// 	std::cout << dog->getType() << std::endl;
	// 	dog->makeSound();
	// 	delete dog;
	// }

	// std::cout << partition << std::endl;
	// std::cout << "CAT\n";
	// std::cout << partition << std::endl;
	// {
	// 	Animal* cat = new Cat();
	// 	cat->setType("red cat");
	// 	std::cout << cat->getType() << std::endl;
	// 	cat->makeSound();
	// 	delete cat;
	// }

	// std::cout << partition << std::endl;
	// std::cout << "WRONGANIMAL\n";
	// std::cout << partition << std::endl;
	// {
	// 	const WrongAnimal* wrong_animal = new WrongAnimal();
	// 	wrong_animal->makeWrongSound();
	// 	delete wrong_animal;
	// }

	// std::cout << partition << std::endl;
	// std::cout << "WRONGCAT\n";
	// std::cout << partition << std::endl;
	// {
	// 	WrongAnimal* wrong_cat = new WrongCat();
	// 	WrongCat cat;
	// 	wrong_cat->setWrongType("wrong cat");
	// 	std::cout << wrong_cat->getWrongType() << std::endl;
	// 	wrong_cat->makeWrongSound();
	// 	cat.makeWrongSound();
	// 	delete wrong_cat;
	// }
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}
