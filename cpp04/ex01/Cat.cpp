/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:28:56 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/13 12:53:50 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called\n";
}

Cat::Cat (std::string type) : Animal(type)
{
	_type = type;
	brain = new Brain();
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other)
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

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat deconstructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow meow\n";
}

Brain *Cat::getBrain()
{
	return (this->brain);
}
