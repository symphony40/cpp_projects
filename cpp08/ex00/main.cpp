/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/13 15:00:53 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + 5);
try {
        std::vector<int>::const_iterator it = easyfind(vec, 3);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::const_iterator it = easyfind(vec, 6);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

