/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:49:29 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/04 11:41:45 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <sstream>

class Contact {

	public:
		Contact();
		~Contact();
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& LastName);
		void setNickName(const std::string& NickName);
		void setPhoneNumber(const std::string& PhoneNumber);
		void setDarkestSecret(const std::string& darkestSecret);
		void setId(int& id);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		std::string getId() const;
		int checkPhoneNumber() const ;



	private:
	int _id;
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
};


#endif
