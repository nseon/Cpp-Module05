/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:09:06 by nseon             #+#    #+#             */
/*   Updated: 2025/12/12 11:03:10 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Form form1("Test", 0, 1, 450);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form form1;
		Form form2("form2", 0, 149, 1);
		Bureaucrat bur("Bureaucrat", 160);

		bur.signForm(form1);
		std::cout << form1;
		bur.signForm(form2);
		
		form2.beSigned(bur);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
