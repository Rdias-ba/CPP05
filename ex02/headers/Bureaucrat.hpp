/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:40:59 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 18:08:44 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:

			//Attributes
			const std::string	_name;
			size_t				_grade;

			//Setters
			void setGrade(int grade);

	public:

			//Constructors
			Bureaucrat();
			Bureaucrat(const Bureaucrat &src);
			Bureaucrat(const std::string name, int grade);
			Bureaucrat(int grade);
			Bureaucrat(const std::string name);

			//Destructors
			~Bureaucrat();

			//Overloaded Operators
			Bureaucrat &operator=(const Bureaucrat &src);

			//Getters
			const std::string getName(void) const;
			size_t getGrade(void) const;

			//Methods
			void incrementGrade(void);
			void decrementGrade(void);
			void signForm(AForm &form);
			void executeForm(AForm const &form);

			//Exceptions
			class GradeTooLowException : public std::exception
			{
				public:

						virtual const char *what() const throw();
			};

			class GradeTooHighException : public std::exception
			{
				public:

						virtual const char *what() const throw();
			};
};

//iostream Overload
std::ostream	&operator<<(std::ostream &out, Bureaucrat *src);
