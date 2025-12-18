/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:46:23 by nseon             #+#    #+#             */
/*   Updated: 2025/12/18 11:02:41 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, 145, 137)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &m) : AForm(m)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &m)
{
	if (this != &m)
		AForm::operator=(m);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getIs_signed())
		throw UnsignedForm();
	if (executor.getGrade() <= 45)
	{
		std::cout << "* DRILLING NOISES *" << std::endl;
		if (std::rand() % 2)
			std::cout << getName() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "robotomy failed" << std::endl;
	}
	else
		throw GradeTooLowException();
}

