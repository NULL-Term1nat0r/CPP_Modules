#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

class AForm;

class Intern
{
private:
	AForm	*_allocPresident(std::string target);
	AForm	*_allocRobot(std::string target);
	AForm	*_allocShrub(std::string target);
public:
	Intern();
	Intern(Intern const &intern);
	~Intern();
	Intern	&operator=(Intern const &intern);
	AForm	*makeForm(std::string form_name, std::string target);
};

#endif
