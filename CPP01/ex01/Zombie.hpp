#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:
		Zombie();
		~Zombie();
		void announce();
		void setName(std::string);

	private:
		std::string name;

};

Zombie* zombieHorde(int N, std::string name);

#endif
