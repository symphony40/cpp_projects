/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:28:56 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/03 13:15:22 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _health(10), _energy(10), _attack(0)
{
	return;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
}

ClapTrap::ClapTrap(std::string name)
{
}

ClapTrap::~ClapTrap()
{
	return;
}

void ClapTrap::attack(const std::string & target)
{
}

void ClapTrap::takeDamage(unsigned int amount)
{
}

void ClapTrap::beRepaired(unsigned int amount)
{
}
