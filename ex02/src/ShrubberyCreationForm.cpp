/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:46:23 by nseon             #+#    #+#             */
/*   Updated: 2025/12/17 17:15:10 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &m) : AForm(m)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &m)
{
	if (this != &m)
		AForm::operator=(m);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIs_signed())
		throw UnsignedForm();
	if (executor.getGrade() <= 137)
	{
		std::string	*ptr = const_cast<std::string*>(&getName());
		std::ofstream out((*ptr + "_shruberry").c_str());
		
		out << TREE << std::endl;
		out << TREE << std::endl;
	}
	else
		throw GradeTooLowException();
}
