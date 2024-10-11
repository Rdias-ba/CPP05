/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:02 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/09 20:30:34 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

			//Attributes
			const std::string	_name;
			bool				_is_signed;
			const int			_sign_grade;
			const int			_exec_grade;

	public:

			//Constructors
			Form();
			Form(const Form &src);
			Form(const std::string name);
			Form(const int sign_grade, const int exec_grade);
			Form(const std::string name, const int sign_grade, const int exec_grade);

			//Destructors
			~Form();

			//Overloaded operators
			Form &operator=(const Form &src);

			//Methods
			void beSigned(Bureaucrat &signer);

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
};

std::ostream &operator<<(std::ostream &out, Form *src);


