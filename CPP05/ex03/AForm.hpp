
#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signCheck;
	const int _signGrade;
	const int _executeGrade;
	std::string _target;
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
	class AFormAlreadySigned: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class AFormNotSigned : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};
	//canonical standard functions
	AForm();
	AForm(std::string name, bool signCheck, int signGrade, int executeGrade, std::string target);
	AForm(const AForm &other);
	virtual ~AForm();
	AForm &operator=(const AForm &other);
	//other member functions
	std::string getName() const;
	bool getSignCheck() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	std::string getTarget() const;

	void setTarget(std::string target);
	void setSignCheck(bool signCheck);


	void beSigned(Bureaucrat const &mustermann);
	bool executionCheck(Bureaucrat const &executor) const;
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream & operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
