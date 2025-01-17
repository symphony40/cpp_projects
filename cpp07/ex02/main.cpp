/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/09 14:44:21 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Test 1: Default constructor
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test 2: Parameterized constructor
        Array<int> intArray(5);
        std::cout << "Array size after construction: " << intArray.size() << std::endl;
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 2;
        }
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << "Element at index " << i << ": " << intArray[i] << std::endl;
        }

        // Test 3: Copy constructor
        Array<int> copyArray = intArray;
        std::cout << "Copy array size: " << copyArray.size() << std::endl;

        // Modify copyArray to check deep copy
        copyArray[0] = 42;
        std::cout << "Original array first element after modification in copy: " << intArray[0] << std::endl;

        // Test 4: Assignment operator
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;

        // Test 5: Out of bounds
        try {
            std::cout << intArray[10] << std::endl; // Should throw exception
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
