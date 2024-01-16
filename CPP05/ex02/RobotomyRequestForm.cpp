#include "Header.h"
#include "RobotomyRequestForm.hpp"

// Implement class methods here

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", false, 72, 45, "default target")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", false, 72, 45, target)
{
	std::cout << "RobotomyRequestForm constructor with type called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	this->setTarget(other.getTarget());
	this->setSignCheck(other.getSignCheck());
	std::cout << "RobotomyRequestForm copy assignment constructor called" << std::endl;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (!executionCheck(executor))
		return ;
	std::cout << "some drilling noises...brrrrrr brrrr brr brr br br w84092jr9hf9h!!!\n";
	srand(time(0));
	int randomValue = rand() % 2;
	if (randomValue == 0)
	{
		std::cout << "The " << getTarget() << " has been robotomized successfully.\n";
		return ;
	}
	else
		std::cout << "The robotomy of " << getTarget() << " failed.\n";
}
