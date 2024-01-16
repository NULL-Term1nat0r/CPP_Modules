/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:49:24 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/04 14:19:50 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <sstream>

class PhoneBook {

	public:
		PhoneBook();
		~PhoneBook();
		void addContact(int index);
		void searchContacts();
		std::string getInput(std::string message);
		int checkNonDigit(std::string input);



	private:
		Contact contacts[8];
		void printPhoneBook();
		void printContact(int index);
		void printWord(std::string word, std::string colour);
		void printTableHeader();

};

#endif
