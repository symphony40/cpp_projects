/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:28:56 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/13 11:59:57 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat (std::string type) : WrongAnimal(type)
{
	_type = type;
	std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	_type = other._type;
	std::cout << "WrongCat copy assignment constructor called\n";
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor called\n";
}


// member functions
void WrongCat::makeSound() const
{
	std::cout << "Meow meow\n";
}