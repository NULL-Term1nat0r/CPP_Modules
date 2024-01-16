#include "Header.h"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
	std::cout << "constructor guy " << _name <<" with weapon " << _weapon.getType() << " called" << std::endl;
}

HumanA::~HumanA(){
	std::cout << "destructor guy " << _name << " called" << std::endl;
}

void HumanA::attack(){
	std::cout << _name <<" attacks with their " << _weapon.getType() << std::endl;
}

