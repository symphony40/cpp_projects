/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:28:56 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/13 11:58:44 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal (std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	_type = other._type;
	std::cout << "WrongAnimal copy assignment constructor called\n";
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor called\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makeSound function called\n";
}

std::string WrongAnimal::getType() const
{
	return (_type);
}