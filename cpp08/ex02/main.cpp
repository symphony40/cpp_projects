/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/17 12:14:02 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "----MUTANT STACK----" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "MutantStack elements:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n----LIST FOR COMPARISON----" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "\nList top (back): " << lst.back() << std::endl;
    lst.pop_back();

    std::cout << "List size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "List elements:" << std::endl;
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
        std::cout << *lit << std::endl;

    return 0;
}

