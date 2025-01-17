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

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    *this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src) {
    (void)src;
    return *this;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    struct FormPair {
        std::string name;
        AForm* (*create)(const std::string &target);
    };

    FormPair forms[] = {
        {"shrubbery creation", [](const std::string &target) -> AForm* { return new ShrubberyCreationForm(target); }},
        {"robotomy request", [](const std::string &target) -> AForm* { return new RobotomyRequestForm(target); }},
        {"presidential pardon", [](const std::string &target) -> AForm* { return new PresidentialPardonForm(target); }}
    };

    for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); ++i) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }
	
    std::cerr << "Error: Form name \"" << formName << "\" not recognized." << std::endl;
    return nullptr;
}

