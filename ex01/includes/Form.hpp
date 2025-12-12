/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:31:21 by nseon             #+#    #+#             */
/*   Updated: 2025/12/12 09:27:48 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Form {
	private:
		std::string const	_name;
		bool 				_is_signed;
		int const			_min_to_sign;
		int const			_min_to_exec;
	public:
		Form();
		Form(Form const &m);
		Form &operator=(Form const &m);
		Form(std::string const name, bool is_signed, int const min_to_sign, int const min_to_exec);
		~Form();

		std::string const	getName() const;
		bool				getIs_signed() const;
		int					getMin_to_exec() const;
		int					getMin_to_sign() const;
		
		int		checkGrade(int n_grade);
		void	beSigned(Bureaucrat &signatory);
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &os, Form &m);
