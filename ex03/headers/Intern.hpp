/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:09:47 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/11 16:18:29 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class	AForm;
class	PresidentialPardonForm;
class	ShrubberyCreationForm;
class	RobotomyRequestForm;

class	Intern
{
	private:


	public:

			//Constructors
			Intern();
			Intern(const Intern &src);

			//Destructors
			~Intern();

			//Overloaded Operators
			Intern &operator=(const Intern &src);

			//Methods
			AForm *makeForm(const std::string form, const std::string target);
};
