/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:01:04 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/18 14:23:34 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	private:

	protected:
		std::string	_type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &animal);
		virtual ~Animal();
		Animal	&operator=(Animal const &animal);
		
		void		setType(std::string type);
		std::string	getType(void) const;
		virtual void	makeSound() const;
};

#endif
