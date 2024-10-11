/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:31:43 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 21:53:38 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Constructors
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << src.getName()
				<< " to " << this->getName() << std::endl;
	*this = src;
}

//Destructors
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Deconstructor for " << this->getName() << " called" << std::endl;
}

//Operators Overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

//Methods

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw(AForm::FormNotSignedException());
	else
	{
		std::ofstream outfile(this->getTarget().append("_shrubbery").c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();
	}

}


// Getter
std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

// ostream Overload
std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm *src)
{
	out << "Form " << src->getName()
		<< " : sign-grade : " << src->getSignGrade()
	    << " exec-grade : " << src->getExecGrade()
	    << " is signed : " << src->getIsSigned() << std::endl;
	return (out);
}
