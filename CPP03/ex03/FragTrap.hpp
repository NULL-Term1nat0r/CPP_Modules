/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:18:33 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/11 16:27:06 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{

	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap &src);
		~FragTrap();

		unsigned int getFragDamage();

		void highFivesGuys(void);
};

#endif
