/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:41:18 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/27 21:58:21 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", 72, 45), _target("Default"){}


RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45), _target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomy)
{
	*this = robotomy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomy)
{
	(void)robotomy;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &Bureaucrat) const
{
	int	robotomy;

	this->AForm::executeCheck(Bureaucrat);
	std::cout << "*drilling noises* ";
	robotomy = rand() % 2;
	if (robotomy)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
