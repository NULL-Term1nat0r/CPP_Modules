/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:28:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/11 19:28:43 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	_wrong_type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &wrong_animal);
		WrongAnimal(std::string type);
		WrongAnimal	&operator=(WrongAnimal const &wrong_animal);
		virtual ~WrongAnimal();
		void	makeWrongSound() const;
		std::string		getWrongType(void) const;
		void			setWrongType(std::string wrong_type);
};

#endif
