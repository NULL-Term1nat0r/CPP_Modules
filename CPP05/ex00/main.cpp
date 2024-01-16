
#include "Header.h"
#include "Bureaucrat.hpp"

int main()
{

	std::string partition(50, '-');


	std::cout << partition << std::endl;
	std::cout << "Increment Test\n";
	std::cout << partition << std::endl;
	try {
		Bureaucrat Peter = Bureaucrat("Peter", 148);
		std::cout << Peter;
		Peter.increment();
		std::cout << Peter;
	}
	catch(std::exception &a){
		std::cerr << a.what();
	}
	std::cout << partition << std::endl;
	std::cout << "Decrement Test\n";
	std::cout << partition << std::endl;
	try {
		Bureaucrat Peter = Bureaucrat("Peter", 148);
		std::cout << Peter;
		Peter.decrement();
		std::cout << Peter;
	}
	catch(std::exception &a){
		std::cerr << a.what();
	}
	std::cout << partition << std::endl;
	std::cout << "Decrement too high Test\n";
	std::cout << partition << std::endl;
	try {
		Bureaucrat Peter = Bureaucrat("Peter", 150);
		std::cout << Peter;
		Peter.decrement();
		std::cout << Peter;
	}
	catch(std::exception &a){
		std::cerr << a.what();
	}
	std::cout << partition << std::endl;
	std::cout << "increment too low Test\n";
	std::cout << partition << std::endl;
	try {
		Bureaucrat Peter = Bureaucrat("Peter", 1);
		std::cout << Peter;
		Peter.increment();
		std::cout << Peter;
	}
	catch(std::exception &a){
		std::cerr << a.what();
	}
	return 0;
}
