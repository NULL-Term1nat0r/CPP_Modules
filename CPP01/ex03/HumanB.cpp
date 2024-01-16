#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
	std::cout << "constructor guy " << _name << " called\n";
}

HumanB::~HumanB(){
	std::cout << "destructor guy " << _name << " called" << std::endl;
}

void HumanB::attack(){
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon new_weapon){
	_weapon = &new_weapon;
}



