
#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	// Class members

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	virtual void execute(Bureaucrat const &executor) const;
};

#endif
