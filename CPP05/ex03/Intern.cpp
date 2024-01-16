//
// Created by Eike Maximilian Struckmeier on 9/24/23.
//
#include "Intern.hpp"
#include "Header.h"

Intern::Intern()
{
	std::cout << "Intern constructor called\n";
}

Intern::Intern(Intern const &intern)
{
	std::cout << "Intern copy constructor called\n";
	*this = intern;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}

Intern &Intern::operator=(Intern const & /* intern */) {
	return *this;
}
AForm	*Intern::_allocPresident(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::_allocRobot(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::_allocShrub(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	std::string	forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm* (Intern::*func[]) (std::string) = {&Intern::_allocPresident, &Intern::_allocRobot, &Intern::_allocShrub};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return (this->*func[i])(target);
		}
	}
	std::cout << "Intern was not aible to create the form\n";
	return NULL;
}
