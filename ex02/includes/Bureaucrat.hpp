/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:12:03 by nseon             #+#    #+#             */
/*   Updated: 2025/12/12 10:53:47 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class AForm;

class Bureaucrat{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &m);
		Bureaucrat(std::string name, int grade);
		Bureaucrat &operator=(Bureaucrat const &m);
		~Bureaucrat();

		Bureaucrat operator--();
		Bureaucrat operator--(int);
		Bureaucrat operator++();
		Bureaucrat operator++(int);

		std::string	getName() const;
		int			getGrade() const;

		void setGrade(int n_grade);
		
		void signForm(AForm &form);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &m);
