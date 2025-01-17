/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:39:23 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/27 21:39:25 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &presidential);
		
	public:
		PresidentialPardonForm(const std::string &target);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &presidential);

		void					execute(const Bureaucrat &Bureaucrat) const;
};

#endif
