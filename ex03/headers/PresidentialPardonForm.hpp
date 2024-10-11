/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:56:46 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 19:48:01 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm
{
	private:

			//Attributes and unused but needed for canonical for constructor
			const std::string _target;
			PresidentialPardonForm(void);

	public:

			//Constructors
			PresidentialPardonForm(std::string target);
			PresidentialPardonForm(const PresidentialPardonForm &src);

			//Deconstructors
			~PresidentialPardonForm();

			//Overloaded Operators
			PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

			//Public Methods
			void execute(Bureaucrat const &executor) const;

			//Getter
			std::string getTarget(void)const;
};

//ostream Overload
std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *src);
