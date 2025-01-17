/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:29:50 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/27 22:58:38 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(void);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);
    const std::string getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);
	void signForm(AForm &form) const;
	void executeForm(const AForm &form) const;
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade is too low!";
        }
    };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif

