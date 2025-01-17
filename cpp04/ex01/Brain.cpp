/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:15:17 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/13 12:21:13 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Brain.hpp"

    Brain::Brain()
	{
        std::cout << "Brain constructor called." << std::endl;
    }

    Brain::Brain(const Brain& other)
	{
        std::cout << "Brain copy constructor called." << std::endl;
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }

    Brain &Brain::operator=(const Brain& other)
	{
        std::cout << "Brain assignment operator called." << std::endl;
        if (this != &other) {
            for (int i = 0; i < 100; ++i) {
                ideas[i] = other.ideas[i];
            }
        }
        return *this;
    }

    Brain::~Brain()
	{
        std::cout << "Brain destructor called." << std::endl;
    }
