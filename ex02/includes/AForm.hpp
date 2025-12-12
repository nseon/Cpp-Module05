/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:31:21 by nseon             #+#    #+#             */
/*   Updated: 2025/12/12 20:21:49 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class AForm {
	private:
		std::string const	_name;
		bool 				_is_signed;
		int const			_min_to_sign;
		int const			_min_to_exec;
	public:
		AForm();
		AForm(AForm const &m);
		AForm &operator=(AForm const &m);
		AForm(std::string const name, int const min_to_sign, int const min_to_exec);
		virtual ~AForm();

		std::string const	getName() const;
		bool				getIs_signed() const;
		int					getMin_to_exec() const;
		int					getMin_to_sign() const;
		
		int				checkGrade(int n_grade);
		void			beSigned(Bureaucrat &signatory);
		virtual void	execute(Bureaucrat const & executor) = 0;
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &os, AForm &m);
