/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:31:31 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/08 13:39:14 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {

  FragTrap frag("Jeremy Fragrance");
  std::cout << "\n\n";

  frag.highFivesGuys();
  frag.attack("chicken");
  frag.takeDamage(10);
  frag.beRepaired(10);
  std::cout << "\n\n";

  // Test ScavTrap
  ScavTrap scav("monsieur");
  std::cout << "\n\n";

  scav.guardGate();
  scav.attack("kartoschka");
  scav.takeDamage(10);
  scav.beRepaired(10);

  std::cout << "\n\n";
  return 0;
}
