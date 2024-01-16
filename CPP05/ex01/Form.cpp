
#include "Header.h"
#include "Form.hpp"

// Implement class methods here

Form::Form() : _name("Form"), _signCheck(FALSE), _signGrade(100), _executeGrade(120)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, bool signCheck, int signGrade, int executeGrade)  : _name(name), _signCheck(signCheck), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooLowException();
	else if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooHighException();
	std::cout << "Form constructor with type called" << std::endl;
}

Form::Form(const Form &other) : _name(other.getName()), _signCheck(other.getSignCheck()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	*this = other;
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	this->_signCheck 	= other._signCheck;
	std::cout << "Form copy assignment constructor called" << std::endl;
	return *this;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high\n";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low\n";
}

const char	*Form::FormAlreadySigned::what() const throw()
{
	return "Form is already signed, now back to coffee break!\n";
}

std::string Form::getName() const
{
	return this->_name;
}
bool Form::getSignCheck() const
{
	return this->_signCheck;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

void Form::beSigned(Bureaucrat const &mustermann)
{

	if (_signCheck == TRUE)
		throw FormAlreadySigned();
	else if (mustermann.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	else
		std::cout << mustermann.getName() << " signed " << this->_name << std::endl;
}

std::ostream & operator<<(std::ostream &out, Form const &form)
{
	out << "Form name is: " << form.getName() << ", required Grade to sign: " << form.getSignGrade() << "required Grade to execute: " << form.getExecuteGrade() << "sign status: " << form.getSignCheck() << std::endl;
	return out;
}
