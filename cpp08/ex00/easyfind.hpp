/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:33:16 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/13 14:51:45 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>

class NotFoundException: public std::exception
{
	public:
			virtual const char *what() const throw()
			{
				return ("Value not found in the container");
			}
};

template< typename T>
typename T::iterator easyfind(T &in, int i)
{
	typename T::iterator	it;
	it = find(in.begin(), in.end(), i);
	if (it == in.end())
	{
		throw (NotFoundException());
	}
	return (it);
}

#endif
