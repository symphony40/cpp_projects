/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/28 21:02:46 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Intern.hpp"

int main() {
    try {
        // Create an intern
        Intern someRandomIntern;

        // Bureaucrats
        Bureaucrat boss("Boss", 1);
        Bureaucrat assistant("Assistant", 50);

        // Create forms via the intern
        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
        AForm* unknown = someRandomIntern.makeForm("unknown form", "Nowhere"); // Should fail

        // Test valid forms
        if (shrubbery) {
            boss.signForm(*shrubbery);
            boss.executeForm(*shrubbery);
            delete shrubbery; // Clean up
        }

        if (robotomy) {
            assistant.signForm(*robotomy);
            assistant.executeForm(*robotomy);
            delete robotomy; // Clean up
        }

        if (pardon) {
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
            delete pardon; // Clean up
        }

        // Test invalid form
        if (unknown) {
            delete unknown; // Shouldn't happen, but just in case
        }

    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
