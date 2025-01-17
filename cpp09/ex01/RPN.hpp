/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:33:16 by vejurick          #+#    #+#             */
/*   Updated: 2025/01/08 16:55:25 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int>     _n;
    public:
        RPN();
        RPN(const RPN &a);
        ~RPN();
        RPN & operator = (const RPN &a);

        void    ReadInput(std::string input);
        int     CalculationResult(int n1, int n2, char o);
};

#endif
