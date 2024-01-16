/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:10:44 by estruckm             #+#    #+#             */
/*   Updated: 2023/09/13 11:10:44 by estruckm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

#include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		virtual ~Animal();
		Animal &operator=(const Animal &other);
		void setType(std::string type);
		std::string getType(void) const;
		virtual void makeSound() const;
		virtual const std::string getIdea(int index) const = 0;
		virtual void setIdea(std::string idea, int index) const = 0;
};

#endif
