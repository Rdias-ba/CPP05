/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:33:43 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/09 18:13:23 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructors
Bureaucrat::Bureaucrat(void): _name("Guy"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called for \"" << this->getName() <<
		"\" with the grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy")
{
	std::cout << "Bureaucrat copy constructor called for \"" << src.getName() <<
		"\" to \"" << this->getName() << "\"" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor called for \"" << this->getName() <<
		"\" with the grade " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat constructor called for \"" << this->getName() <<
		"\" with the grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("Guy")
{
	std::cout << "Bureaucrat constructor called for \"" << this->getName() <<
		"\" with the grade " << grade << std::endl;
	this->setGrade(grade);
}

//Destructors
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat deconstructor for \"" << this->getName() << "\" called" << std::endl;
}

//Overloaded Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this == &src)
	{
		return (*this);
	}

	this->_grade = src.getGrade();
	return *this;
}

//Methods
void	Bureaucrat::incrementGrade(void)
{
	std::cout << "Trying to increment grade of \"" << this->getName() << "\"" << std::endl;
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Trying to decrement grade of \"" << this->getName() << "\"" << std::endl;
	this->setGrade(this->_grade + 1);
}

//Getters
const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

size_t Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

//Setters
void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

//Exceptions
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too Low");
}

//iostream overload
std::ostream &operator<<(std::ostream &out, Bureaucrat *src)
{
	out << "Bureaucrat \"" << src->getName() << "\" is graded " << src->getGrade() << std::endl;
	return (out);
}
