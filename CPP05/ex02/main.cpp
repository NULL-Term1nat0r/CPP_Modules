
#include "Header.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::string partition(50, '-');

	std::cout << CORAL << partition << std::endl;
	std::cout << "Presidential Form Test with valid grade of signing and executing:\n";
	std::cout << partition << RESET << std::endl;
	PresidentialPardonForm form1("Arthur Dent");
	Bureaucrat bureaucrat1("Dieter", 1);
	try{
		bureaucrat1.signForm(form1);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try{
		form1.execute(bureaucrat1);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}

	std::cout << CORAL << partition << std::endl;
	std::cout << "Presidential Form Test with valid grade of signing but not executing:\n";
	std::cout << partition << RESET << std::endl;
	PresidentialPardonForm form2("Gunther");
	Bureaucrat bureaucrat2("Hans", 25);
	try {
		bureaucrat2.signForm(form2);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try{
		form2.execute(bureaucrat2);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}

	std::cout << CORAL << partition << std::endl;
	std::cout << "Shrubbery Creation Form Test with valid grade of signing and executing:\n";
	std::cout << partition << RESET << std::endl;
	ShrubberyCreationForm form3("targetfile");
	Bureaucrat bureaucrat3("Junker", 1);
	try{
		bureaucrat3.signForm(form3);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try {
		form3.execute(bureaucrat3);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}

	return 0;
}
