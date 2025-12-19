/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:31:31 by nseon             #+#    #+#             */
/*   Updated: 2025/12/17 16:50:38 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _is_signed(0), _min_to_sign(150), _min_to_exec(1)
{}

AForm::AForm(AForm const &m) : _name(m._name), _is_signed(m._is_signed), _min_to_sign(m._min_to_sign), _min_to_exec(m._min_to_exec)
{}

AForm &AForm::operator=(AForm const &m)
{
	if (this != &m)
		_is_signed = m._is_signed;
	return (*this);
}

AForm::AForm(std::string const name, int const min_to_sign, int const min_to_exec) : _name(name), _is_signed(0), _min_to_sign(checkGrade(min_to_sign)), _min_to_exec(checkGrade(min_to_exec))
{}

AForm::~AForm()
{}

std::string const AForm::getName() const
{
	return (_name);
}

bool AForm::getIs_signed() const
{
	return (_is_signed);
}

int AForm::getMin_to_sign() const
{
	return (_min_to_sign);
}

int AForm::getMin_to_exec() const
{
	return (_min_to_exec);
}

int AForm::checkGrade(int n_grade)
{
	if (n_grade > 150)
		throw GradeTooLowException();
	if (n_grade < 1)
		throw GradeTooHighException();
	return (n_grade);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::UnsignedForm::what() const throw()
{
	return ("Form is unsigned");
}


void AForm::beSigned(Bureaucrat &signatory)
{
	if (signatory.getGrade() <= _min_to_sign)
		_is_signed = 1;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, AForm &m)
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
