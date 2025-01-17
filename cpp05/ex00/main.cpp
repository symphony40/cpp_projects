/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/19 16:51:50 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Bureaucrat Testing ===" << std::endl;

    std::cout << "\n--- Creating Bureaucrats ---" << std::endl;
    Bureaucrat b1("Alice", 100);
    std::cout << b1 << std::endl;

    Bureaucrat b2("Bob", 1);
    std::cout << b2 << std::endl;

    Bureaucrat b3("Charlie", 150);
    std::cout << b3 << std::endl;

    std::cout << "\n--- Testing Grade Increments and Decrements ---" << std::endl;
    std::cout << "Incrementing Alice's grade (100 to 99):" << std::endl;
    b1.incrementGrade();
    std::cout << b1 << std::endl;

    std::cout << "Decrementing Alice's grade (99 to 100):" << std::endl;
    b1.decrementGrade();
    std::cout << b1 << std::endl;

    std::cout << "\n--- Testing Grade Increments and Decrements ---" << std::endl;
    std::cout << "Incrementing Alice's grade (100 to 99):" << std::endl;
    b1.incrementGrade();
    std::cout << b1 << std::endl;

    std::cout << "Decrementing Alice's grade (99 to 100):" << std::endl;
    b1.decrementGrade();
    std::cout << b1 << std::endl;

    std::cout << "Incrementing Bob's grade (1 - edge case):" << std::endl;
    try {
        b2.incrementGrade();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "Decrementing Charlie's grade (150 - edge case):" << std::endl;
    try {
        b3.decrementGrade();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

