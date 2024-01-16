
#include "Header.h"
#include "PresidentialPardonForm.hpp"

// Implement class methods here

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", false, 25, 5, "default target")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", false, 25, 5, target)
{
	std::cout << "PresidentialPardonForm constructor with type called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	this->setTarget(other.getTarget());
	this->setSignCheck(other.getSignCheck());
	std::cout << "PresidentialPardonForm copy assignment constructor called" << std::endl;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (!executionCheck(executor))
		return ;
	std::cout << "Informs that " << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
