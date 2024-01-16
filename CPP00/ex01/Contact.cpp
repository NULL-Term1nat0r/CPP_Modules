/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:37:01 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/04 11:41:42 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
Contact::Contact() :_id(0)
{
	//std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	//std::cout << "Contact deconstructor called" << std::endl;
}

void Contact::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void Contact::setNickName(const std::string& nickName)
{
	_nickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	_darkestSecret = darkestSecret;
}

void Contact::setId(int& id)
{
	_id = id;
}

///////////

std::string Contact::getFirstName() const
{
	return(_firstName);
}

std::string Contact::getLastName() const
{
	return(_lastName);
}

std::string Contact::getNickName() const
{
	return(_nickName);
}

std::string Contact::getPhoneNumber() const
{
	return(_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return(_darkestSecret);
}

std::string Contact::getId() const
{
	std::stringstream ss;
	ss << _id;
	std::string str = ss.str();
	return(str);
}

int Contact::checkPhoneNumber() const
{
	for (size_t i = 0; i < _phoneNumber.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(_phoneNumber[i])))
		{
			return 1;
		}
	}
	return 0;
}

