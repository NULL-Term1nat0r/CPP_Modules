
#ifndef Form_HPP
#define Form_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signCheck;
	const int _signGrade;
	const int _executeGrade;
	// Class members

public:
	//exception classes
	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormAlreadySigned: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	//canonical standard functions
	Form();
	Form(std::string name, bool signCheck, int signGrade, int executeGrade);
	Form(const Form &other);
	~Form();
	Form &operator=(const Form &other);
	//other member functions
	std::string getName() const;
	bool getSignCheck() const;
	int getSignGrade() const;
	int getExecuteGrade() const;


	void beSigned(Bureaucrat const &mustermann);

};

std::ostream & operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
