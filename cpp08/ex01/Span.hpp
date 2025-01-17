/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:40:43 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/13 16:00:50 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span {
public:
    class FullSpanException : public std::exception {
    public:
        const char* what() const throw() {
            return "Span is full. Cannot add more numbers.";
        }
    };

    class NoSpanException : public std::exception {
    public:
        const char* what() const throw() {
            return "Not enough numbers to calculate a span.";
        }
    };

    Span(unsigned int N);
	Span(const Span &span);
	Span &operator=(const Span &src);
	~Span();
    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
	Span();
};

#endif
