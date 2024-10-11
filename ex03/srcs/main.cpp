/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:41 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/11 17:11:17 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
  		std::cout << "\033[32mTesting Intern form creation with multiple forms  :\033[0m" << std::endl;
  		std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

		std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Intern *z = new Intern();
		AForm *b = z->makeForm("SomeRandomForm", "Jhon");
		b = z->makeForm("PresidentialPardonForm", "Jhon");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << std::endl;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << b;

		std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
		delete b;

		std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
		b = z->makeForm("ShrubberyCreationForm", "Jhon");

		std::cout << "\n\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << std::endl;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << b;

		std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
		delete b;

		std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
		b = z->makeForm("RobotomyRequestForm", "Jhon");

		std::cout << "\n\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << std::endl;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << b;

		std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete z;
	}

	{
		std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
  		std::cout << "\033[32mTesting try and catch with mixed graded Bureaucrat signing Forms :\033[0m" << std::endl;
  		std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

		std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		AForm *c = new PresidentialPardonForm("Lucas");
		//AForm *d = new AForm(*c);
		//AForm *d = new AForm("Rent Contract", 140, 100); // you are not able to construct an abstract class here

		std::cout << a;
		std::cout << b;
		std::cout << c;

		std::cout << "\n\033[34mTesting\033[0m" << std::endl;
		// Try to execute before signing
		try
		{
			c->execute(*b);
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cerr << "\033[31m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		// Assistant signs the Form
		try
		{
			a->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the Form
		try
		{
			c->beSigned(*b);
			// b->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// try signing the from again
		b->signForm(*c);
		// execute the Form from assistant
		try
		{
			a->executeForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		// execute Form from CEO
		try
		{
			c->execute(*b);
			// b.executeForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
	}

	{
		std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
  		std::cout << "\033[32mTesting try and catch with High graded Bureaucrat executing PresidentialPardonForm :\033[0m" << std::endl;
  		std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

		std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b->beSigned(*a);
		a->signForm(*c);
		b->execute(*a);
		a->executeForm(*c);
		// c->execute(*a);
		std::cout << std::endl;

		std::cout << "\033[33mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;

	}

	{
		std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
  		std::cout << "\033[32mTesting try and catch with High graded Bureaucrat executing Forms :\033[0m" << std::endl;
  		std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

		std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b->beSigned(*a);
		a->signForm(*c);
		for (int i= 0; i < 10; i++)
			b->execute(*a);
		c->execute(*a);
		std::cout << std::endl;

		std::cout << "\033[33mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
	}
  return 0;
}
