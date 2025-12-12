/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:46:23 by nseon             #+#    #+#             */
/*   Updated: 2025/12/12 19:59:33 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

