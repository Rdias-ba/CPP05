/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:54:14 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 19:47:55 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
	private:

			//Attributes and unused but needed for canonical for constructor
			const std::string _target;
			RobotomyRequestForm(void);

	public:

			//Constructors
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(const RobotomyRequestForm &src);

			//Deconstructors
			~RobotomyRequestForm();

			//Overloaded Operators
			RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

			//Public Methods
			void execute(Bureaucrat const &executor) const;

			//Getter
			std::string getTarget(void)const;
};

//ostream Overload
std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *src);
