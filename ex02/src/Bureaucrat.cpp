/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:11:48 by nseon             #+#    #+#             */
/*   Updated: 2025/12/12 11:03:43 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{}

Bureaucrat::Bureaucrat(Bureaucrat const &m) : _name(m._name), _grade(m._grade)
{}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &m)
{
	if (this != &m)
		_grade = m._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try {		
		setGrade(grade);
	}
	catch (...) {
		std::cout << "Grade is out of range, " << _name << "'s grade is set to 150" << std::endl;
		_grade = 150;
	}
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

Bureaucrat Bureaucrat::operator--()
{
	setGrade(_grade + 1);
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat old = *this;
	
	setGrade(_grade + 1);
	return (old);
}

Bureaucrat Bureaucrat::operator++()
{
	setGrade(_grade - 1);
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat old = *this;
	
	setGrade(_grade - 1);
	return (old);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &m)
{
	os << m.getName() << ", bureaucrat grade " << m.getGrade();
	return (os);
}

void Bureaucrat::setGrade(int n_grade)
{
	if (n_grade > 150)
		throw GradeTooLowException();
	if (n_grade < 1)
		throw GradeTooHighException();
	_grade = n_grade;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Can't lower the grade");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Can't increase the grade");
}

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

