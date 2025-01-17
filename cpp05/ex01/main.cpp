/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/26 19:34:07 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Create Bureaucrats with various grades
        Bureaucrat bob("Bob", 75);
        Bureaucrat alice("Alice", 150);
        Bureaucrat charlie("Charlie", 1);

        // Display Bureaucrats
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << charlie << std::endl;

        // Test grade increment and decrement
        bob.incrementGrade();
        std::cout << "After incrementing Bob's grade: " << bob << std::endl;

        try {
            alice.incrementGrade(); // Should throw exception
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            charlie.incrementGrade(); // Should throw exception
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Create Forms with various requirements
        Form basicForm("BasicForm", 100, 50);
        Form advancedForm("AdvancedForm", 75, 25);

        // Display Forms
        std::cout << &basicForm << std::endl;
        std::cout << &advancedForm << std::endl;

        // Test signing
        try {
            basicForm.beSigned(alice); // Should fail
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            basicForm.beSigned(bob); // Should succeed
            std::cout << "After signing: " << &basicForm << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            advancedForm.beSigned(bob); // Should fail
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            advancedForm.beSigned(charlie); // Should succeed
            std::cout << "After signing: " << &advancedForm << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
    }

    return 0;
}
