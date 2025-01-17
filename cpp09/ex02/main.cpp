/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:18:24 by vejurick          #+#    #+#             */
/*   Updated: 2025/01/14 16:14:12 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>

static std::vector<int> argv_to_vector(int argc, char** argv)
{
    std::vector<int> res;
    res.reserve(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

static std::deque<int> argv_to_deque(int argc, char** argv)
{
    std::deque<int> res;
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

void checkArgs(char **argv)
{
    int i = 1;
    int j = 0;
    while (argv[i])
    {
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                std::cerr << "Error: please enter a valid argument." << std::endl;
                exit(EXIT_FAILURE);
            }
            j++;
        }
        j = 0;
        i++;
    }
}

template <typename Container>
bool is_sorted(const Container& container) {
    typename Container::const_iterator it = container.begin();
    typename Container::const_iterator next_it = it;
    ++next_it;
    while (next_it != container.end()) {
        if (*it > *next_it)
		{
			std::cout << "\n not sorted here " << *it << "\n" << std::endl;
			return false;
		}
        ++it;
        ++next_it;
    }
    return true;
}

int main(int argc, char** argv)
{
    PmergeMe pm;

	checkArgs(argv);
	std::vector<int> vec = argv_to_vector(argc, argv);
    clock_t start_vec = clock();
    pm.sort_vec(vec);
    clock_t end_vec = clock();
    double time_elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

    clock_t start_deque = clock();
    std::deque<int> deque = argv_to_deque(argc, argv);
    pm.sort_deque(deque);
    clock_t end_deque = clock();
    double time_elapsed_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;

	if (!is_sorted(vec) || !is_sorted(deque))
	{
		std::cout << "Error: The range is not sorted." << std::endl;
		exit(EXIT_FAILURE);
	}

    std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << "\nAfter:  ";
	for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\nTime to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << std::setprecision(6) << time_elapsed_vec << "s\n";
    std::cout << "Time to process a range of " << vec.size() << " elements with std::deque:  " << std::fixed << std::setprecision(6) << time_elapsed_deque << "s\n";
}
