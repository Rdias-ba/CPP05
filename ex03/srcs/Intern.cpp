/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:19:47 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/11 16:49:45 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//Constructors

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
}

//Destructors
Intern::~Intern()
{
	std::cout << "Intern Deconstructor called" << std::endl;
}

//Overloaded Operators
Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

//Makeform associated fonctions
static AForm	*makePresidentPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

//Methods
AForm	*Intern::makeForm(const std::string form_name, const std::string target_name)
{
	AForm	*(*Forms[])(const std::string target) = {&makePresidentPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};

	std::string Forms_list[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == Forms_list[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return (Forms[i](target_name));
		}
	}
	std::cout << "\033[31mIntern could not create the form called " << form_name << "\033[0m" << std::endl;
	return (NULL);
}
