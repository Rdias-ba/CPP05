/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:41:26 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 19:48:04 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm: public AForm
{
	private:

			//Attributes and unused but needed for canonical for constructor
			const std::string _target;
			ShrubberyCreationForm(void);

	public:

			//Constructors
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm &src);

			//Deconstructors
			~ShrubberyCreationForm();

			//Overloaded Operators
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

			//Public Methods
			void execute(Bureaucrat const &executor) const;

			//Getter
			std::string getTarget(void)const;
};

//ostream Overload
std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm *src);
