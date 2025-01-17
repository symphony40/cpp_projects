/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:39:33 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/27 21:53:07 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &robotomy);
		
	public:
		RobotomyRequestForm(const std::string &target);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &robotomy);

		void					execute(const Bureaucrat &bureaucrat) const;
};

#endif
