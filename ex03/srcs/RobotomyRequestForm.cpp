/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:16:18 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/10/10 21:43:32 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Constructors
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called to copy " << src.getName()
				<< " to " << this->getName() << std::endl;
	*this = src;
}

//Destructors
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Deconstructor for " << this->getName() << " called" << std::endl;
}

//Operators Overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

//Methods

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw(AForm::FormNotSignedException());
	else if (rand() % 2 == 1)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}


// Getter
std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

// ostream Overload
std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *src)
{
	out << "Form " << src->getName()
		<< " : sign-grade : " << src->getSignGrade()
	    << " exec-grade : " << src->getExecGrade()
	    << " is signed : " << src->getIsSigned() << std::endl;
	return (out);
}
