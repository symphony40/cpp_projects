/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:41:05 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/27 21:49:48 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential pardon", 25, 5), _target("Default"){}


PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential pardon", 25, 5), _target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidential)
{
	*this = presidential;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidential)
{
	(void)presidential;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &Bureaucrat) const
{
	this->AForm::executeCheck(Bureaucrat);
	std::cout << _target << " was forgiven by Zafor Beeblebrox" << std::endl;
}
