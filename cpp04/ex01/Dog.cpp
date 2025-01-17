/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:28:56 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/13 12:47:33 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor called\n";
}

Dog::Dog (std::string type) : Animal(type)
{
	_type = type;
	brain = new Brain();
	std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        std::cout << "Cat copy assignment constructor called\n";
    }
	return (*this);
}

Dog::~Dog()
{
	 delete brain;
	std::cout << "Dog deconstructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Haf haf\n";
}

Brain *Dog::getBrain()
{
	return (this->brain);
}
	