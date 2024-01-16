/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:04:54 by estruckm             #+#    #+#             */
/*   Updated: 2023/09/13 11:04:54 by estruckm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
	  Brain *brain_attribute;

  public:
	  Dog();
	  Dog(const Dog &other);
	  ~Dog();
	  Dog &operator=(const Dog &other);

	  Brain *getBrain() const;
	 const std::string getIdea(int index) const;
	void setIdea(std::string idea, int index) const;

	void		makeSound() const;
};

#endif
