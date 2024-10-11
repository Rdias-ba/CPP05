/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:39:41 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 21:06:00 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
  std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
  std::cout << "\033[32mTesting try and catch with Lowest graded Bureaucrat :\033[0m" << std::endl;
  std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

  std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
  Bureaucrat *one = new Bureaucrat();

  std::cout << one;

  std::cout << "\n\033[34mTesting\033[0m" << std::endl;
  try
  {
    one->decrementGrade();
  }
  catch(Bureaucrat::GradeTooLowException &e)
  {
    std::cerr << "\033[31m" << "Decrementation of " << one->getName() << "'s grade failed : " << e.what() << "\033[0m" << std::endl;
  }

  try
  {
    one->incrementGrade();
  }
  catch(Bureaucrat::GradeTooHighException &e)
  {
    std::cerr << "\033[31m" << "Incrementation of " << one->getName() << "'s grade failed : " << e.what() << "\033[0m" << std::endl;
  }

  std::cout << one;

  try
  {
    one->decrementGrade();
  }
  catch(Bureaucrat::GradeTooLowException &e)
  {
    std::cerr << "\033[31m" << "Decrementation of " << one->getName() << "'s grade failed : " << e.what() << "\033[0m" << std::endl;
  }

  std::cout << one;

  std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
  delete one;

  std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
  std::cout << "\033[32mTesting try and catch with Highest graded Bureaucrat :\033[0m" << std::endl;
  std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

  std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
  one = new Bureaucrat(1);

  std::cout << one;

  std::cout << "\n\033[34mTesting\033[0m" << std::endl;
  try
  {
    one->incrementGrade();
  }
  catch(Bureaucrat::GradeTooHighException &e)
  {
    std::cerr << "\033[31m" << "Incrementation of " << one->getName() << "'s grade failed : " << e.what() << "\033[0m" << std::endl;
  }

  try
  {
    one->decrementGrade();
  }
  catch(Bureaucrat::GradeTooLowException &e)
  {
    std::cerr << "\033[31m" << "Decrementation of " << one->getName() << "'s grade failed : " << e.what() << "\033[0m" << std::endl;
  }

  std::cout << one;

  try
  {
    one->incrementGrade();
  }
  catch(Bureaucrat::GradeTooHighException &e)
  {
    std::cerr << "\033[31m" << "Incrementation of " << one->getName() << "'s grade failed : " << e.what() << "\033[0m" << std::endl;
  }

  std::cout << one;

  std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
  delete one;

  std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
  std::cout << "\033[32mTesting try and catch with 0 graded Bureaucrat :\033[0m" << std::endl;
  std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

  one = NULL;

  try
  {
    std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
    one = new Bureaucrat(0);
  }
  catch(Bureaucrat::GradeTooHighException &e)
  {
    std::cerr << "\033[31mConstruction of Bureaucrat failed : " << e.what() << "\033[0m" << std::endl;
    if (one != NULL)
    {
      std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
      delete one;
    }
  }

  std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
  std::cout << "\033[32mTesting try and catch with 150+ graded Bureaucrat :\033[0m" << std::endl;
  std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

  one = NULL;

  try
  {
    std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
    one = new Bureaucrat(151);
  }
  catch(Bureaucrat::GradeTooLowException &e)
  {
    std::cerr << "\033[31mConstruction of Bureaucrat failed : " << e.what() << "\033[0m" << std::endl;
    if (one != NULL)
    {
      std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
      delete one;
    }
  }

  std::cout << "\n\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;
  std::cout << "\033[32mTesting the rest of the class utils :\033[0m" << std::endl;
  std::cout << "\033[32m-----------------------------------------------------------------------------------\033[0m" << std::endl;

  std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
  one = new Bureaucrat("Jhon");

  std::cout << one;

  std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
  delete one;

  std::cout << "\n\033[34mConstructing\033[0m" << std::endl;
  one = new Bureaucrat("Jhon", 132);

  std::cout << one;

  one->decrementGrade();

  std::cout << one;

  std::cout << "\n\033[34mConstructing from existing one\033[0m" << std::endl;
  Bureaucrat *two = new Bureaucrat(*one);

  std::cout << "\n\033[34mTesting\033[0m" << std::endl;
  one->incrementGrade();

  std::cout << one;
  std::cout << two;

  std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
  delete two;

  std::cout << "\n\033[34mAssignation\033[0m" << std::endl;
  two = one;

  std::cout << one;
  std::cout << two;

  std::cout << "\n\033[33mDeconstructing\033[0m" << std::endl;
  delete two;
  return 0;
}
