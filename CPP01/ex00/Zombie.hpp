#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:
		Zombie(std::string);
		~Zombie();
		void announce();

	private:
		std::string name;

};

Zombie *newZombie(std::string);
void randomChump(std::string);

#endif
