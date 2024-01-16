#include <iostream>
#include "Zombie.hpp"

int main (){

	Zombie *max_doll;

	Zombie noah("noah");
	noah.announce();
	std::cout << std::endl;
	randomChump("Edvinas");
	std::cout << std::endl;
	max_doll = newZombie("Max Doll");
	max_doll->announce();
	std::cout << std::endl;
	delete max_doll;
	return 0;
}
