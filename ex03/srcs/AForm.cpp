/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:31:27 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 18:15:41 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Constructors
AForm::AForm(void): _name("Paper"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const AForm &src): _name(src.getName() + "_copy"), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "AForm Copy Constructor called for" << src.getName()
			<< " to " << this->getName() << std::endl;
	*this = src;
}

AForm::AForm(const std::string name): _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "AForm Constructor called for " << this->getName()
			<< " with sign-grade of " << this->getSignGrade()
			<< " and execution-grade of " << this->getExecGrade() << std::endl;
}

AForm::AForm(const int sign_grade, const int exec_grade): _name("Paper"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm Constructor called for " << this->getName()
			<< " with sign-grade of " << sign_grade
			<< " and execution-grade of " << exec_grade << std::endl;
	if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw(AForm::GradeTooLowException());
	else if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm Constructor called for " << this->getName()
			<< " with sign-grade of " << sign_grade
			<< " and execution-grade of " << exec_grade << std::endl;
	if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw(AForm::GradeTooLowException());
	else if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw(AForm::GradeTooHighException());
}

//Destructors
AForm::~AForm()
{
	std::cout << "AForm Deconstructor for " << this->getName() << " called" << std::endl;
}

//Overloaded Operators

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this == &src)
	{
		return (*this);
	}

	return *this;
}

//Methods
void AForm::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
	{
		this->_is_signed = true;
		std::cout << this->getName() << " AForm was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " AForm is already signed" << std::endl;
}

//Getters
const std::string AForm::getName(void)const
{
	return (this->_name);
}

bool AForm::getIsSigned(void)const
{
	return (this->_is_signed);
}

int	AForm::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade(void)const
{
	return (this->_exec_grade);
}

// Exceptions
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("AForm needs to be signed before executing");
};

//ostream Overload
std::ostream &operator<<(std::ostream &out, AForm *src)
{
	out << "AForm " << src->getName()
		<< " : sign-grade : " << src->getSignGrade()
	    << " exec-grade : " << src->getExecGrade()
	    << " is signed : " << src->getIsSigned() << std::endl;
	return (out);
}
