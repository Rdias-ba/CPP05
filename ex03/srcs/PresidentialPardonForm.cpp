/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:58:38 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 19:13:44 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//Constructors
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm Copy Constructor called to copy " << src.getName()
				<< " to " << this->getName() << std::endl;
	*this = src;
}

//Destructors
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Deconstructor for " << this->getName() << " called" << std::endl;
}

//Operators Overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

//Methods

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw(AForm::FormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


// Getter
std::string	PresidentialPardonForm::getTarget(void)const
{
	return (this->_target);
}

// ostream Overload
std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *src)
{
	out << "Form " << src->getName()
		<< " : sign-grade : " << src->getSignGrade()
	    << " exec-grade : " << src->getExecGrade()
	    << " is signed : " << src->getIsSigned() << std::endl;
	return (out);
}
