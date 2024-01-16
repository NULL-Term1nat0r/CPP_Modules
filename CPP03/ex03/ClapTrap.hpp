#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define green "\033[32m"
#define blue "\033[34m"
#define cyan "\033[36m"
#define yellow "\033[33m"
#define red "\033[31m"
#define reset "\033[0m"


# define RED "\033[1;31m"
# define PUR "\033[1;35m"
# define YEL "\033[1;33m"
# define GRE "\033[1;32m"
# define BLU "\033[1;34m"
# define RES "\033[0m"



class ClapTrap{

	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _damagePoints;

	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(ClapTrap const &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getDamagePoints() const;
		std::string getName() const;

		void setHitPoints(unsigned int value);
		void setEnergyPoints(unsigned int value);
		void setDamagePoints(unsigned int value);
		void setName(std::string value);



		void getDataFromPlayer();

};

std::ostream &operator<<(std::ostream &out, ClapTrap const &fixed);
void printColour(std::string output, std::string colour);

#endif
