/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/16 12:05:27 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#include <iostream>

int main()
{
    // Test swap with integers
    int a = 42, b = 24;
    std::cout << "Before swap: a = " << a << ", b = " << b << '\n';
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << '\n';

    // Test max and min with integers
    std::cout << "Max of a and b: " << max(a, b) << '\n';
    std::cout << "Min of a and b: " << min(a, b) << '\n';

    // Test swap with doubles
    double x = 3.14, y = 2.71;
    std::cout << "\nBefore swap: x = " << x << ", y = " << y << '\n';
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << '\n';

    // Test max and min with doubles
    std::cout << "Max of x and y: " << max(x, y) << '\n';
    std::cout << "Min of x and y: " << min(x, y) << '\n';

    // Test swap with strings
    std::string str1 = "Hello", str2 = "World";
    std::cout << "\nBefore swap: str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"\n";
    swap(str1, str2);
    std::cout << "After swap: str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"\n";

    // Test max and min with strings
    std::cout << "Max of str1 and str2: \"" << ::max(str1, str2) << "\"\n";
    std::cout << "Min of str1 and str2: \"" << ::min(str1, str2) << "\"\n";

    return 0;
}

