/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:09:06 by nseon             #+#    #+#             */
/*   Updated: 2025/12/19 10:24:41 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	Bureaucrat	boss("The boss", 1);
	Intern		intern;
	AForm		*Rform = intern.makeForm("robotomy request", "Bender");
	AForm		*Sform = intern.makeForm("shrubbery creation", "Home");
	AForm		*Pform = intern.makeForm("presidential pardon", "Criminal");
	
	if (Rform != NULL)
	{
		boss.signForm(*Rform);
		boss.executeForm(*Rform);
		delete Rform;
	}
	
	if (Sform != NULL)
	{
		boss.signForm(*Sform);
		boss.executeForm(*Sform);
		delete Sform;
	}
	
	if (Pform != NULL)
	{
		boss.signForm(*Pform);
		boss.executeForm(*Pform);
		delete Pform;
	}
	return (0);
}
