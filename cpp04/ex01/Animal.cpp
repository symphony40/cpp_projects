/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:28:56 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/13 11:51:12 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal (std::string type) : _type(type)
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{
	_type = other._type;
	std::cout << "Animal copy assignment constructor called\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called\n";
}

void Animal::makeSound() const
{
	std::cout << "Animal makeSound function called\n";
}

std::string Animal::getType() const
{
	return (_type);
}