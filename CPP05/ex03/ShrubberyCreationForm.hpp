
#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	// Class members

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	virtual void execute(Bureaucrat const &executor) const;
};

#endif

