/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:04:56 by estruckm             #+#    #+#             */
/*   Updated: 2023/09/13 11:04:56 by estruckm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
  private:
	Brain *brain_attribute;
	  // Class members

  public:
	  Cat();
	  Cat(std::string type);
	  Cat(const Cat &other);
	  ~Cat();
	  Cat &operator=(const Cat &other);

	  Brain *getBrain() const;

	  const std::string getIdea(int index) const;
	  void setIdea(std::string idea, int index) const;


	void		makeSound() const;


};

#endif
