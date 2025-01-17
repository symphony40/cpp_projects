/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:53:38 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/27 22:22:09 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("Default"), _is_signed(false), _sign_grade(150), _exec_grade(150) {}

Form::Form(const Form &src): _name(src.getName()), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	*this = src;
}

Form::Form(int sign_grade, int exec_grade): _name("Default"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string name): _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150) {}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::~Form(){}

Form &Form::operator=(const Form &src)
{
	if (this == &src)
		return *this;
	return *this;
}

void Form::beSigned(const Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == "false")
	{
		this->_is_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

const std::string	Form::getName(void)const
{
	return (this->_name);
}

const std::string	Form::getIsSigned(void)const
{
	if (this->_is_signed)
		return ("true");
	else
		return ("false");
}

bool	Form::getIsSignedBool(void)const
{
	return (this->_is_signed);
}

int	Form::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade(void)const
{
	return (this->_exec_grade);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}