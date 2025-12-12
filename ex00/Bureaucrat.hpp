/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:12:03 by nseon             #+#    #+#             */
/*   Updated: 2025/12/11 12:00:51 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &m);
		Bureaucrat &operator=(Bureaucrat const &m);
		~Bureaucrat();
		
		Bureaucrat(std::string name, int grade);
		
		std::string getName() const;
		int getGrade() const;
		
		Bureaucrat operator--();
		Bureaucrat operator--(int);
		Bureaucrat operator++();
		Bureaucrat operator++(int);
		
		void setGrade(int n_grade);
		
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

#endif
