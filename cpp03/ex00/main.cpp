/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/07/19 12:55:50 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
    std::cout << "============= stackZombies =============" << std::endl;
	Zombie	zombie1("Zombie1");
	Zombie	zombie2("Zombie2");
	Zombie	zombie3;

	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	randomChump("randomChumpZ");

	std::cout << std::endl;
	std::cout << "============= heapZombies ==============" << std::endl;
	Zombie	*heapZ;

	heapZ = newZombie("HeapZ");
	heapZ->announce();
	delete(heapZ);

	return (0);
}