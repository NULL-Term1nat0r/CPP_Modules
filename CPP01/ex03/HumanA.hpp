#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string, Weapon &weapon);
		~HumanA();
		void attack();
	private:
		std::string _name;
		Weapon &_weapon;
};

#endif
