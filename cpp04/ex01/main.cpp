/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/13 12:53:07 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    const int numAnimals = 6;
    Animal* animals[numAnimals];

    // Fill half the array with Dogs and the other half with Cats
    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

    std::cout << "\n--- Animal sounds ---\n" << std::endl;

    // Test making sounds
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "\n--- Deleting animals ---\n" << std::endl;

    // Delete all animals and check for appropriate destructor calls
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    std::cout << "\n--- Testing deep copy ---\n" << std::endl;

    // Test deep copy
    Dog originalDog;
    originalDog.makeSound();

    // Manually set an idea in the original dog's brain
    originalDog.getBrain()->ideas[0] = "Original idea";

    Dog copiedDog = originalDog; // Calls copy constructor

    // Test if the ideas are deeply copied
    std::cout << "Original Dog's first idea: " << originalDog.getBrain()->ideas[0] << std::endl;
    std::cout << "Copied Dog's first idea: " << copiedDog.getBrain()->ideas[0] << std::endl;

    // Modify copied dog's idea to test deep copy
    copiedDog.getBrain()->ideas[0] = "Copied dog's own idea";
    std::cout << "After modification:" << std::endl;
    std::cout << "Original Dog's first idea: " << originalDog.getBrain()->ideas[0] << std::endl;
    std::cout << "Copied Dog's first idea: " << copiedDog.getBrain()->ideas[0] << std::endl;

    return 0;
}
