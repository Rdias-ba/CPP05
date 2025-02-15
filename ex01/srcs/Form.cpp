/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:31:27 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/09 20:31:13 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructors
Form::Form(void): _name("Paper"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "Form Copy Constructor called for" << src.getName()
			<< " to " << this->getName() << std::endl;
	*this = src;
}

Form::Form(const std::string name): _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form Constructor called for " << this->getName()
			<< " with sign-grade of " << this->getSignGrade()
			<< " and execution-grade of " << this->getExecGrade() << std::endl;
}

Form::Form(const int sign_grade, const int exec_grade): _name("Paper"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName()
			<< " with sign-grade of " << sign_grade
			<< " and execution-grade of " << exec_grade << std::endl;
	if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw(Form::GradeTooLowException());
	else if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName()
			<< " with sign-grade of " << sign_grade
			<< " and execution-grade of " << exec_grade << std::endl;
	if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw(Form::GradeTooLowException());
	else if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw(Form::GradeTooHighException());
}

//Destructors
Form::~Form()
{
	std::cout << "Form Deconstructor for " << this->getName() << " called" << std::endl;
}

//Overloaded Operators

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
	{
		return (*this);
	}

	return *this;
}

//Methods
void Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
	{
		this->_is_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

//Getters
const std::string	Form::getName(void)const
{
	return (this->_name);
}

bool	Form::getIsSigned(void)const
{
	return (this->_is_signed);
}

int	Form::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade(void)const
{
	return (this->_exec_grade);
}

// Exceptions
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

//ostream Overload
std::ostream &operator<<(std::ostream &out, Form *src)
{
	out << "Form " << src->getName()
		<< " : sign-grade : " << src->getSignGrade()
	    << " exec-grade : " << src->getExecGrade()
	    << " is signed : " << src->getIsSigned() << std::endl;
	return (out);
}
