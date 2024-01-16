/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:55:12 by estruckm          #+#    #+#             */
/*   Updated: 2023/10/26 16:27:10 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{

	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap();


		void guardGate(void);
		void attack(const std::string &target);
		unsigned int getEnergyPoints();
	protected:
		unsigned int getScavEnergy();
		unsigned int _energyPoints;
};

#endif
