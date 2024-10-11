/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:02 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 18:35:51 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

			//Attributes
			const std::string	_name;
			bool				_is_signed;
			const int			_sign_grade;
			const int			_exec_grade;

	public:

			//Constructors
			AForm();
			AForm(const AForm &src);
			AForm(const std::string name);
			AForm(const int sign_grade, const int exec_grade);
			AForm(const std::string name, const int sign_grade, const int exec_grade);

			//Destructors
			virtual ~AForm();

			//Overloaded operators
			AForm &operator=(const AForm &src);

			//Methods
			void beSigned(Bureaucrat &signer);
			virtual void execute(Bureaucrat const &executor) const = 0;

			//Getters
			const std::string getName(void) const;
			bool getIsSigned(void) const;
			int getSignGrade(void) const;
			int getExecGrade(void) const;

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

			class FormNotSignedException : public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};

std::ostream &operator<<(std::ostream &out, AForm *src);


