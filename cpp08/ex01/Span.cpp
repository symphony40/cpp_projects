/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:41:13 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/13 15:58:57 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &span)
{
	*this = span;
}

Span::~Span() {}

Span	&Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;
	return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw FullSpanException();
    }
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int shortest = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }

    return shortest;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

    return *maxIt - *minIt;
}
