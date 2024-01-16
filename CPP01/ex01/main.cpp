#include <iostream>
#include "Zombie.hpp"

int main (){

	Zombie* horde = zombieHorde(10, "deine mudda");
	for(int i = 0; i < 10; i++){
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
