/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:28:56 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/27 22:17:07 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) 
    : _name(bureaucrat._name), _grade(bureaucrat._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat)
        _grade = bureaucrat._grade;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat) {
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (o);
}

const std::string Bureaucrat::getName(void) const {
    return (_name);
}

int Bureaucrat::getGrade(void) const {
    return (_grade);
}

void Bureaucrat::incrementGrade(void) {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

