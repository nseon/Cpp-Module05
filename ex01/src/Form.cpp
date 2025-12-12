/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:31:31 by nseon             #+#    #+#             */
/*   Updated: 2025/12/12 09:27:48 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _is_signed(0), _min_to_sign(150), _min_to_exec(1)
{}

Form::Form(Form const &m) : _name(m._name), _is_signed(m._is_signed), _min_to_sign(m._min_to_sign), _min_to_exec(m._min_to_exec)
{}

Form &Form::operator=(Form const &m)
{
	if (this != &m)
		_is_signed = m._is_signed;
	return (*this);
}

Form::Form(std::string const name, bool is_signed, int const min_to_sign, int const min_to_exec) : _name(name), _is_signed(is_signed), _min_to_sign(checkGrade(min_to_sign)), _min_to_exec(checkGrade(min_to_exec))
{}


Form::~Form()
{}

std::string const Form::getName() const
{
	return (_name);
}

bool Form::getIs_signed() const
{
	return (_is_signed);
}

int Form::getMin_to_sign() const
{
	return (_min_to_sign);
}

int Form::getMin_to_exec() const
{
	return (_min_to_exec);
}

int Form::checkGrade(int n_grade)
{
	if (n_grade > 150)
		throw GradeTooLowException();
	if (n_grade < 1)
		throw GradeTooHighException();
	return (n_grade);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

void Form::beSigned(Bureaucrat &signatory)
{
	if (signatory.getGrade() <= _min_to_sign)
		_is_signed = 1;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Form &m)
{
	std::cout << m.getName();
	if (m.getIs_signed())
		std::cout << " is signed ";
	else
		std::cout << " is unsigned ";
	std::cout << "(Min grade to sign : " << m.getMin_to_sign()
	<< " | Min grade to exec : " << m.getMin_to_exec() << ")" << std::endl;
	return (os);
}
