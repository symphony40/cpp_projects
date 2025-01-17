/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2025/01/08 17:12:26 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iomanip>

int main(int ac, char *av[])
{
    RPN obj;
	
    if (ac == 2)
    {

        try
        {
            obj.ReadInput(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }
        
    }
	else
        std::cout << "Usage: ./RPN \"expression to calculate\"" << std::endl;
	
	return (0);
}

