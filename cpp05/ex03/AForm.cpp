/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:53:38 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/26 19:27:49 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("Default"), _is_signed(false), _sign_grade(150), _exec_grade(150) {}

AForm::AForm(const AForm &src): _name(src.getName()), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	*this = src;
}

AForm::AForm(int sign_grade, int exec_grade): _name("Default"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(const std::string name): _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150) {}

AForm::AForm(const std::string name, int sign_grade, int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
}

AForm::~AForm(){}

AForm &AForm::operator=(const AForm &src)
{
	if (this == &src)
		return *this;
	return *this;
}

void AForm::beSigned(const Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == "false")
	{
		this->_is_signed = true;
		std::cout << this->getName() << " AForm was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " AForm is already signed" << std::endl;
}

const std::string	AForm::getName(void)const
{
	return (this->_name);
}

const std::string	AForm::getIsSigned(void)const
{
	if (this->_is_signed)
		return ("true");
	else
		return ("false");
}

bool	AForm::getIsSignedBool(void)const
{
	return (this->_is_signed);
}

int	AForm::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade(void)const
{
	return (this->_exec_grade);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *AForm::ExecuteNotSigned::what(void) const throw()
{
	return ("Form not signed");
};

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "AForm " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}

void	AForm::executeCheck(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSignedBool())
		throw AForm::ExecuteNotSigned();
	if (this->getExecGrade() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
}