/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:53:38 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/11 16:19:29 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{

	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap &operator=(const DiamondTrap &src);
		~DiamondTrap();

		// using ScavTrap::attack;

		void whoAmI(void);

		void getDataFromPlayer2();
};

#endif


// class DerivedClass : public BaseClass1, public BaseClass2 {
// public:
//     DerivedClass(int v1, int v2) : BaseClass1(v1), BaseClass2(v2) {}

//     void printVars() {
//         std::cout << "DerivedClass var1: " << var1 << std::endl;
//         std::cout << "DerivedClass var2: " << var2 << std::endl;
//     }
// };

// int main() {
//     // Create an object of the derived class
//     DerivedClass derived(42, 24);

//     // Access variables and functions from the base classes
//     derived.printVar1();
//     derived.printVar2();

//     // Access variables from the derived class
//     derived.printVars();

//     return 0;
// }
