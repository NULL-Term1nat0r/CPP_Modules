/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:32:18 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/04 12:01:21 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include<cstdlib>

int main ()
{
	PhoneBook	book;
	int index = 0;
	std::string command;

	while (true)
	{
		std::cout << "Please enter a command:";
		std::getline (std::cin, command);
		// command = book.getInput("Please enter a command:");
		if (std::cin.eof())
			exit(69);
		if (command == "EXIT")
			break;
		if (command == "ADD")
		{
			book.addContact(index);
			index++;
		}
		if (command == "SEARCH")
			book.searchContacts();
	}
	return 0;
}


// fix buchstabe bei search eingabe
// stoi ist für c11 und nicht für c98
