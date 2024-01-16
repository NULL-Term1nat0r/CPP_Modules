/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:33:27 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/04 14:21:39 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include "Colors.h"
#include <cstdlib>

PhoneBook::PhoneBook()
{
	//std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	//std::cout << "PhoneBook deconstructor called" << std::endl;
}
void PhoneBook::addContact(int index)
{
	if (index > 0)
		index = index % 8;

	contacts[index].setId(index);
	contacts[index].setFirstName(getInput("Type in the first name:"));
	contacts[index].setLastName(getInput("Type in the last name:"));
	contacts[index].setNickName(getInput("Type in the nick name:"));
	while (true)
	{
		contacts[index].setPhoneNumber(getInput("Type in the phone number:"));
		if (contacts[index].checkPhoneNumber() == 0)
			break;
		std::cout << "Only numbers are allowed for the phone number!" << std::endl;
	}
	contacts[index].setDarkestSecret(getInput("Type in the darkest Secret:"));
}

void PhoneBook::printContact(int index)
{
	printWord(contacts[index].getId(), CYAN);
	std::cout << "|";
	printWord(contacts[index].getFirstName(), GREEN);
	std::cout << "|";
	printWord(contacts[index].getLastName(), BLUE);
	std::cout << "|";
	printWord(contacts[index].getNickName(), YELLOW);
	std::cout << "|";
	printWord(contacts[index].getPhoneNumber(), RED);
	std::cout << std::endl;
}

void PhoneBook::printWord(std::string word, std::string colour)
{
	 if (word.length() > 9) {
        std::cout << colour << std::right << std::setw(9) << word.substr(0, 9) + "." << RESET;
    } else {
        std::cout << colour << std::right << std::setw(10) << word << RESET;
    }
}

void PhoneBook::printTableHeader()
{
	printWord("Index", CYAN);
	std::cout << "|";
	printWord("First Name", GREEN);
	std::cout << "|";
	printWord("Last Name", BLUE);
	std::cout << "|";
	printWord("Nick Name", YELLOW);
	std::cout << "|";
	printWord("Number", RED);
	std::cout << std::endl;
}

void PhoneBook::printPhoneBook()
{
	std::cout << std::endl;
	printTableHeader();
	for(int i = 0; i < 8; i++)
	{
		if (contacts[i].getFirstName().empty())
			break;
		else
		{
			printContact(i);
		}
	}
	std::cout << std::endl;
}

void PhoneBook::searchContacts()
{
	std::string keyword;
	printPhoneBook();

	if (contacts[0].getFirstName().empty())
	{
		std::cout << "\033[31m" << "you haven't add any contacts to your phonebook yet" << "\033[0m" << std::endl;
		return;
	}

	while (true)
	{
		keyword = getInput("enter the index of the contact for further information:");

		if (checkNonDigit(keyword))
			std::cout << "\033[31m" << "provid valid number characters" << "\033[0m" << std::endl;
		else
		{
			if (std::atoi(keyword.c_str()) > 7 || std::atoi(keyword.c_str()) < 0)
			std::cout << "\033[31m" << "number must be between 0 and 7" << "\033[0m" << std::endl;
			else
			{
				if (contacts[std::atoi(keyword.c_str())].getFirstName().length() > 0)
					break;
				else
					std::cout << "\033[31m" << "there is no contact with index number "<< keyword << "\033[0m" << std::endl;
			}
		}
	}
	printTableHeader();
	printContact(std::atoi(keyword.c_str()));
	std::cout << std::endl;
}


std::string PhoneBook::getInput(std::string message)
{
	std::string input;

	while (true)
	{
		std::cout << message << std::endl;
		std::getline (std::cin, input);
		if (std::cin.eof())
			exit(69);
		if (input.empty())
			std::cout << "\033[31m" << "this field can't be empty" << "\033[0m" << std::endl;
		else
			break;
	}
	return (input);
}

int PhoneBook::checkNonDigit(std::string input)
{

	for (size_t i = 0; i < input.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
		{
			return 1;
		}
	}
	return 0;
}
