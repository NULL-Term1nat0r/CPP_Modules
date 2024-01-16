
#include "Header.h"
#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signCheck(FALSE), _signGrade(100), _executeGrade(120), _target("default form"){
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, bool signCheck, int signGrade, int executeGrade, std::string target)  : _name(name), _signCheck(signCheck), _signGrade(signGrade), _executeGrade(executeGrade), _target(target){
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooLowException();
	else if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooHighException();
	std::cout << "AForm constructor with type called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other.getName()), _signCheck(other.getSignCheck()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade()), _target(other.getTarget()){
	*this = other;
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(){
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other){
	if (this == &other)
		return *this;
	this->_signCheck 	= other._signCheck;
	std::cout << "AForm copy assignment constructor called" << std::endl;
	return *this;
}

const char	*AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high\n";
}

const char	*AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low\n";
}

const char	*AForm::AFormAlreadySigned::what() const throw(){
	return "AForm is already signed, now back to coffee break!\n";
}
const char	*AForm::AFormNotSigned::what() const throw(){
	return "Form is not signed!";
}

std::string AForm::getName() const
{
	return this->_name;
}
bool AForm::getSignCheck() const
{
	return this->_signCheck;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}
std::string AForm::getTarget() const{
	return this->_target;
}

void AForm::setTarget(std::string _target){
	this->_target = _target;
}
void AForm::setSignCheck(bool signCheck){
	this->_signCheck = signCheck;
}

void AForm::beSigned(Bureaucrat const &mustermann)
{

	if (_signCheck == TRUE)
		throw AFormAlreadySigned();
	else if (mustermann.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	else{
		this->_signCheck = TRUE;
		std::cout << mustermann.getName() << " signed " << this->_name << std::endl;
	}
}

bool AForm::executionCheck(Bureaucrat const &executor) const{
	if (this->_signCheck == FALSE)
		throw AFormNotSigned();
	else if (executor.getGrade() > this->_executeGrade)
	{
		std::cout << this->getName() << " couldn't execute " << this->getName() << std::endl;
		throw GradeTooLowException();
	}
	else
		return TRUE;
}

std::ostream & operator<<(std::ostream &out, AForm const &AForm)
{
	out << "AForm name is: " << AForm.getName() << ", required Grade to sign: " << AForm.getSignGrade() << "required Grade to execute: " << AForm.getExecuteGrade() << "sign status: " << AForm.getSignCheck() << std::endl;
	return out;
}
