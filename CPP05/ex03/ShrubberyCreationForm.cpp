#include "Header.h"
#include "ShrubberyCreationForm.hpp"

// Implement class methods here

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Form", false, 145, 137, "default target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Form", false, 145, 137, target)
{
	std::cout << "ShrubberyCreationForm constructor with type called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	this->setTarget(other.getTarget());
	this->setSignCheck(other.getSignCheck());
	std::cout << "ShrubberyCreationForm copy assignment constructor called" << std::endl;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!executionCheck(executor))
		return ;
	std::ofstream	out_file(getTarget() + "_shrubbery");
	if (out_file.is_open())
	{
		out_file << "         .                         .     .                                      " << std::endl;
		out_file << "     .         .                                                                " << std::endl;
		out_file << "                     .         .  .         .  .            .                   " << std::endl;
		out_file << "                                 * .**,.../*,,,..,                              " << std::endl;
		out_file << ".                            ,*./**.**(((/%*//(((*,,             .           .  " << std::endl;
		out_file << "                               #/**#/(((*/&#%%%%(*/*                            " << std::endl;
		out_file << "                     .    ,*,,,,*#,*%(&(#*((&(#(#(,..          .                " << std::endl;
		out_file << "                          ,/(,//#(//(#//###*/(.///*                             " << std::endl;
		out_file << "                        .,*(#*///#(,/&&/#,/##((,(*(*#.                          " << std::endl;
		out_file << "                         . ./( /##*,*.%%#(%,.#%#(#*/(. ,*                       " << std::endl;
		out_file << "               .         ,.*/%#%%%#(*(,#/((&%(*/,/#(#(.(.                   .   " << std::endl;
		out_file << "                         , .*///*/./#%**%##*/*##,/***./.                        " << std::endl;
		out_file << "                        .*(***#*(%/*(#/*/(/,,/#(%*((                            " << std::endl;
		out_file << "                         .#/%/*#/((##%(/%//%#/#,/((#/**                         " << std::endl;
		out_file << "                       *#//((/#%/#%##. ,%*#..*/*((,./..                         " << std::endl;
		out_file << "               .       *//%(###%##(**(#//*,/*.(*,*/#/(/                         " << std::endl;
		out_file << "                      ,#//(.,..,/**/(,&%#/#///*///(,((.                         " << std::endl;
		out_file << "                      .    #//%(##%//.(/#(/%#(/#///#/*.                         " << std::endl;
		out_file << "                             /.(#//(*(((#,(*.,./  ,.                            " << std::endl;
		out_file << "                                 *,((**./.,.                                    " << std::endl;
		out_file << "                                    ..  (,                                      " << std::endl;
		out_file << "                                        *                                       " << std::endl;
		out_file << "                                        *                                       " << std::endl;
		out_file << "                                        ,                                       " << std::endl;
		out_file << "     .         .                        ,.                                      " << std::endl;
		out_file << "                                        ,.                                      " << std::endl;
		out_file << "                                        .,                                      " << std::endl;
		out_file << "                                        ,.                                      " << std::endl;
		out_file << "                                        ,,                                      " << std::endl;
		out_file << "     .         .                        ,,                                      " << std::endl;
		out_file.close();
	}
	else
		std::cerr << "Could not open the file\n";
}
