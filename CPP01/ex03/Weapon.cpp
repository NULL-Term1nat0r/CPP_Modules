#include "Weapon.hpp"

Weapon::Weapon(std::string name) : type(name) {
  std::cout << "weapon " << type<< " constructor called\n";
}
Weapon::~Weapon(){
	std::cout << "weapon " << type << " destructor called" << std::endl;
}
const std::string &Weapon::getType(){
	return(type);
}
void Weapon::setType(std::string new_type){
	type = new_type;
}
