/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:41 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 20:31:09 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
	std::cout << "\033[32mTesting try and catch with Lowest graded Bureaucrat and lowest grade needed Form :\033[0m" << std::endl;
	std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

	{

		std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *one = new Bureaucrat();
		Form       *two = new Form();

		std::cout << one;
		std::cout << two;

		std::cout << "\n\033[34mTesting\033[0m" << std::endl;
		try
		{
			two->beSigned(*one);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
		std::cerr << "\033[31m" << one->getName() << " was not able to sign " << two->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << two << std::endl;

		std::cout << "\033[33mDeconstructing\033[0m" << std::endl;
		delete one;
		delete two;
	}

	std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
	std::cout << "\033[32mTesting try and catch with mixed graded Bureaucrat tring to sign a Form :\033[0m" << std::endl;
	std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

	{
		std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *one = new Bureaucrat("Assistant", 145);
		Bureaucrat *two = new Bureaucrat("CEO", 1);
		Form       *three = new Form("Rent Contract", 140, 100);

		std::cout << one;
		std::cout << two;
		std::cout << three;

		std::cout << "\n\033[34mTesting\033[0m" << std::endl;
	// Assistant signs the Form
		try
		{
			one->signForm(*three);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << one->getName() << " was not able to sign " << two->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the Form
		std::cout << three;
		try
		{
			three->beSigned(*two);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << one->getName() << " was not able to sign " << two->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
	std::cout << three;

	// try signing the from again
		two->signForm(*three);
		std::cout << std::endl;

		std::cout << "\033[33mDeconstructing\033[0m" << std::endl;
		delete one;
		delete two;
		delete three;
	}

	std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
	std::cout << "\033[32mTesting try and catch with variety of Forms :\033[0m" << std::endl;
	std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

	{
		std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
		Form *one = NULL;

		// sign-grade too high
		try
		{
			one = new Form(160, 145);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << "Construction failed: " << e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too high
		try
		{
			one = new Form(145, 160);
		}
		catch (Form::GradeTooLowException &e)
		{
		delete one;
			std::cerr << "\033[31m" << "Construction failed: " << e.what() << "\033[0m" << std::endl;
		}

		// sign-grade too low
		try
		{
			one = new Form(-15, 145);
		}
		catch (Form::GradeTooHighException &e)
		{
      delete one;
			std::cerr << "\033[31m" << "Construction failed: " << e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too low
		try
		{
			one = new Form(145, -15);
		}
		catch (Form::GradeTooHighException &e)
		{
      delete one;
			std::cerr << "\033[31m" << "Construction failed: " << e.what() << "\033[0m" << std::endl;
		}

		// Deconstruction to prevent unused variable, in this case will never be called
		if (one != NULL)
		{
			std::cout << "\033[33mDeconstructing\033[0m" << std::endl;
			delete one;
		}
  }
  return 0;
}
