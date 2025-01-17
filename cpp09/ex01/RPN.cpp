/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:14:18 by vejurick          #+#    #+#             */
/*   Updated: 2025/01/14 16:16:00 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN (){}
RPN::RPN (const RPN &a){this->operator=(a);}
RPN::~RPN (){}
RPN & RPN::operator = (const RPN &a)
{
	(void)a;
	return (*this);
}

int RPN::CalculationResult(int n1, int n2, char o)
{
	switch (o)
	{
		case '+':
			return (n1 + n2);
		case '-':
			return (n2 - n1);
		case '*':
			return (n1 * n2);
		case '/':
		{
			if (n2 == 0)
				throw std::invalid_argument("Floating Point Exception Dividing on Zero\n");
			return (n2 / n1);
		}
	}
	return (0);
}


void    RPN::ReadInput(std::string input)
{
	std::string ope = "+/*-";
	size_t op, num;
	op = num = 0;
	for (size_t i = 0; i < input.length() ; i++)
	{
		if (isdigit(input[i]))
		{
			num++;
			this->_n.push(input[i] - '0');
		}
		else if (ope.find(input[i]) != std::string::npos)
		{
			op++;
			if (_n.size() < 2)
				throw std::invalid_argument("Invalid Input\n");
			int n1 = _n.top();
			_n.pop();
			_n.top() = CalculationResult(n1, _n.top(), input[i]);
		}

		else if (isspace(input[i]))
			continue;
		else
			throw std::invalid_argument("Invalid Input\n");
	}
	if ((op + 1) != num)
		throw std::invalid_argument("Number of operators less or greater than numbers\n");
	std::cout << _n.top() << "\n";
}