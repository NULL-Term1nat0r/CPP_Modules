
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
  private:
	const std::string _name;
	int 		_grade;
	  // Class members

  public:
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

	Bureaucrat(std::string name, int grade);
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string getName() const;
	int getGrade() const;
	void decrement();
	void increment();
	void signForm(AForm &form);
	void executeForm(AForm const & form);
};

std::ostream & operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
