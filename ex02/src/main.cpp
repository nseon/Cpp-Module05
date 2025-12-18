/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:09:06 by nseon             #+#    #+#             */
/*   Updated: 2025/12/18 11:01:17 by nseon            ###   ########.fr       */
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

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	Bureaucrat	a("The boss", 1);
	Bureaucrat	b;
	
	PresidentialPardonForm P;
	ShrubberyCreationForm S("Garden");
	RobotomyRequestForm R("Nico");
	
	b.executeForm(P);
	b.signForm(P);
	a.signForm(P);
	a.signForm(S);
	a.signForm(R);
	b.executeForm(S);
	b.executeForm(R);
	a.executeForm(P);
	a.executeForm(S);
	a.executeForm(R);
	a.executeForm(R);
	a.executeForm(R);
	a.executeForm(R);
	a.executeForm(R);
	return (0);
}
