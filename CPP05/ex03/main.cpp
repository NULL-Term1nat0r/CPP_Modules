
#include "Header.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::string partition(50, '-');

	std::cout << CORAL << partition << std::endl;
	std::cout << "Presidential Form Test with intern and valid grade of signing and executing:\n";
	std::cout << partition << RESET << std::endl;
	Intern intern1;
	AForm *form1;
	form1 = intern1.makeForm("PresidentialPardonForm", "Arthur Dent");
	Bureaucrat bureaucrat1("Dieter", 1);
	try{
		bureaucrat1.signForm(*form1);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try{
		bureaucrat1.executeForm(*form1);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try{
		form1->execute(bureaucrat1);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	std::cout << CORAL << partition << std::endl;
	std::cout << "Shrubbery Creation Form Test with intern and valid grade of signing and executing:\n";
	std::cout << partition << RESET << std::endl;
	Intern intern2;
	AForm *form2;
	form2 = intern2.makeForm("ShrubberyCreationForm", "Arthur Dent");
	try{
		bureaucrat1.signForm(*form2);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try{
		bureaucrat1.executeForm(*form2);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try{
		form2->execute(bureaucrat1);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	std::cout << CORAL << partition << std::endl;
	std::cout << "Wrong Form name Test\n";
	std::cout << partition << RESET << std::endl;
	Intern intern3;
	AForm *form3;
	form3 = intern3.makeForm("wERRwerRere" , "Arthur Dent");
	if (form3 != NULL)
	{
		try{
			bureaucrat1.signForm(*form3);
		}
		catch (std::exception &e){
			std::cout << e.what();
		}
		try{
			bureaucrat1.executeForm(*form3);
		}
		catch (std::exception &e){
			std::cout << e.what();
		}
		try{
			form3->execute(bureaucrat1);
		}
		catch (std::exception &e){
			std::cout << e.what();
		}
	}
	else
		std::cout << "Form is NULL-Pointer\n";

	return 0;
}
