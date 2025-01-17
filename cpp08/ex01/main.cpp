/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/13 16:01:05 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(2);
        sp.addNumber(55);
        sp.addNumber(1);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test with 10,000 numbers
    try {
        Span bigSpan(10000);
        for (int i = 0; i < 10000; ++i) {
            bigSpan.addNumber(i);
        }

        std::cout << "Shortest span (big test): " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span (big test): " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
