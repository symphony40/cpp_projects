/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/28 20:34:13 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create Bureaucrats with various grades
        Bureaucrat lowLevel("LowLevel", 150);
        Bureaucrat midLevel("MidLevel", 40);
        Bureaucrat highLevel("HighLevel", 1);

        std::cout << lowLevel << std::endl;
        std::cout << midLevel << std::endl;
        std::cout << highLevel << std::endl;

        // Create Forms
        AForm *shrubbery = new ShrubberyCreationForm("home");
        AForm *robotomy = new RobotomyRequestForm("target_robot");
        AForm *pardon = new PresidentialPardonForm("target_pardon");

        // Attempt to sign and execute forms
        try {
            lowLevel.signForm(*shrubbery); // Should fail due to low grade
            lowLevel.executeForm(*shrubbery); // Should also fail
        } catch (const std::exception &e) {
            std::cerr << "LowLevel Exception: " << e.what() << std::endl;
        }

        try {
            midLevel.signForm(*robotomy); // Should succeed
            midLevel.executeForm(*robotomy); // Should partially succeed (50% chance)
        } catch (const std::exception &e) {
            std::cerr << "MidLevel Exception: " << e.what() << std::endl;
        }

        try {
            highLevel.signForm(*pardon); // Should succeed
            highLevel.executeForm(*pardon); // Should succeed
        } catch (const std::exception &e) {
            std::cerr << "HighLevel Exception: " << e.what() << std::endl;
        }

		try {
            highLevel.signForm(*shrubbery); // Should succeed
            highLevel.executeForm(*shrubbery); // Should succeed
        } catch (const std::exception &e) {
            std::cerr << "LowLevel Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
    }

    return 0;
}
