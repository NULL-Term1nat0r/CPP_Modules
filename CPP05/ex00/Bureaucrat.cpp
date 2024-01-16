
#include "Header.h"
#include "Bureaucrat.hpp"

// Implement class methods here



//class MyClass {
//public:
//	MyClass(int value) {
//		if (value < 1 || value > 150) {
//			throw std::out_of_range("Value is out of range (1 to 150)");
//		}
//		// Initialize your class members here
//		this->value = value;
//	}
Bureaucrat::Bureaucrat() : _name("Bernd der Bürokrat"), _grade(100)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooLowException();
	if (grade > 150)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	this->_grade = other.getGrade();
	std::cout << "Bureaucrat copy assignment constructor called" << std::endl;
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::decrement()
{
	if (this->_grade  == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}
void Bureaucrat::increment()
{
	if (this->_grade  == 1)
		throw GradeTooLowException();
	else
		this->_grade--;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high and can only be between 1 and 150!";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low and can only be between 1 and 150!";
}

std::ostream & operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Bureaucrat name is: " << bureaucrat.getName() << ", Grade is: " << bureaucrat.getGrade() << std::endl;
	return out;

}
