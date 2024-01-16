
#include "Header.h"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::string partition(50, '-');

	std::cout << partition << std::endl;
	std::cout << "sign Form test with bureaucrat grade valid\n";
	std::cout << partition << std::endl;
	try {
		Bureaucrat peter = Bureaucrat("peter", 90);
		Form Passierschein_A38 = Form();
		std::cout << ORANGE;
		peter.signForm(Passierschein_A38);
		std::cout << RESET;
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}

	std::cout << partition << std::endl;
	std::cout << "sign Form test with bureaucrat grade too low\n";
	std::cout << partition << std::endl;
	Bureaucrat thomas = Bureaucrat("thomas", 101);
	Form Passierschein_B38 = Form();
	std::cout << GOLD; thomas.signForm(Passierschein_B38); std::cout << RESET;

	std::cout << partition << std::endl;
	std::cout << "sign Form test with copy constructor\n";
	std::cout << partition << std::endl;
	Bureaucrat dieter = Bureaucrat("dieter", 150);
	dieter = thomas;
	std::cout << CORAL; dieter.signForm(Passierschein_B38); std::cout << RESET;

	return 0;
}
