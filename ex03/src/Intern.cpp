/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:06:06 by nseon             #+#    #+#             */
/*   Updated: 2025/12/19 10:59:32 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const &m)
{
	(void)m;
}

Intern &Intern::operator=(Intern const &m)
{
	(void)m;
	return (*this);
}

Intern::~Intern()
{}

static AForm *shrubbery(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *robotomy(std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *presidential(std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *(* const ptrs[3])(std::string &target) = {&shrubbery, &robotomy, &presidential};
	const std::string strs[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (name == strs[i])
			return (ptrs[i](target));
	}
	std::cout << name << " is not a recognized form" << std::endl;
	return (NULL);
}
