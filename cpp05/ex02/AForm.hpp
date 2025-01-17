/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:53:34 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/26 19:20:42 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

	public:
		AForm(void);
		AForm(const AForm &src);
		AForm(int sign_grade, int exec_grade);
		AForm(const std::string name);
		AForm(const std::string name, int sign_grade, int exec_grade);
		~AForm();
		AForm &operator=(const AForm &src);
		void beSigned(const Bureaucrat &signer);
		const std::string getName(void)const;
		const std::string getIsSigned(void)const;
		bool getIsSignedBool(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;
		virtual void		execute(const Bureaucrat &bureaucrat) const = 0;
		void				executeCheck(const Bureaucrat &bureaucrat) const;
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class ExecuteNotSigned : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm *a);

#endif