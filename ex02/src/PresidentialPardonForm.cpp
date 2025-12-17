/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:46:23 by nseon             #+#    #+#             */
/*   Updated: 2025/12/17 17:12:21 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(target, 145, 137)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &m) : AForm(m)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &m)
{
	if (this != &m)
		AForm::operator=(m);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getIs_signed())
		throw UnsignedForm();
	if (executor.getGrade() <= 5)
		std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw GradeTooLowException();
}


