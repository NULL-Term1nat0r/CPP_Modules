/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:31:31 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/08 12:42:29 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (){
	  ScavTrap Max("Max");

  std::cout << "\n\n";
  Max.attack("Noah");
  Max.takeDamage(10);
  Max.beRepaired(100);
  Max.guardGate();
  std::cout << "\n\n";

  ScavTrap Tami("Tami");
  std::cout << "\n\n";
  Tami = Max;
  Tami.guardGate();
  std::cout << "\n\n";
  return 0;
}
