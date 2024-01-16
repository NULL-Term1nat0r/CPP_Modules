#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Zombie " << name << " constructor called\n";
}
Zombie::~Zombie(){
	std::cout << "Zombie " << name << " destructor called\n";
}

void Zombie::announce(){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string new_name){
	name = new_name;
}
