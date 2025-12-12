/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:46:23 by nseon             #+#    #+#             */
/*   Updated: 2025/12/12 20:00:37 by nseon            ###   ########.fr       */
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

