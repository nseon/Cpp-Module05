/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:09:06 by nseon             #+#    #+#             */
/*   Updated: 2025/12/11 12:10:27 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat one("one", 155);

	try {
		std::cout << one << std::endl;
		one--;
		std::cout << one << std::endl;
		--one;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat two("two", 2);

	try {
		std::cout << two << std::endl;
		two++;
		std::cout << two << std::endl;
		++two;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
