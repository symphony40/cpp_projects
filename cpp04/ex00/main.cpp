/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/13 12:10:44 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Testing Animal, Dog, and Cat classes
    std::cout << "\n--- Tests from subject ---\n" << std::endl;
    
    const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

    delete meta;
    delete j;
    delete i;

    // Testing WrongAnimal and WrongCat classes
    std::cout << "\n--- Testing WrongAnimal and WrongCat ---\n" << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Type of wrongCat (WrongCat): " << wrongCat->getType() << std::endl;
    
    wrongCat->makeSound(); // Should print the WrongAnimal sound because it's not virtual
    wrongMeta->makeSound(); // Should print the generic wrong animal sound

    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n--- Additional Tests ---\n" << std::endl;

    // Additional tests for polymorphism and destructors
    {
        Animal* animals[] = {new Dog(), new Cat()};
        for (const Animal* animal : animals) {
            std::cout << animal->getType() << " makes sound: ";
            animal->makeSound();
            delete animal;
        }
    }

    {
        WrongAnimal* wrongAnimals[] = {new WrongCat()};
        for (const WrongAnimal* wrongAnimal : wrongAnimals) {
            std::cout << wrongAnimal->getType() << " makes sound: ";
            wrongAnimal->makeSound();
            delete wrongAnimal;
        }
    }

    return 0;
}
