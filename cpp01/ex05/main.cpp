/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/07/23 21:46:46 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main()
{
	
	Harl Harl1;

	Harl1.complain("DEBUG");
	Harl1.complain("INFO");
	Harl1.complain("WARNING");
	Harl1.complain("ERROR");
	Harl1.complain("SCREAM");

    return 0;
}
