/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:33:16 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/16 12:10:16 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <exception>

template <typename T>
class Array {
public:
    Array();                          // Default constructor
    Array(unsigned int n);            // Parameterized constructor
    Array(const Array &other);        // Copy constructor
    Array &operator=(const Array &other); // Assignment operator
    ~Array();                         // Destructor

    T &operator[](unsigned int index);       // Subscript operator (modifiable)
    const T &operator[](unsigned int index) const; // Subscript operator (const)
    unsigned int size() const;               // Size function

    class OutOfBoundsException : public std::exception {
    public:
        const char *what() const throw() {
            return "Index is out of bounds";
        }
    };

private:
    T *elements;                     // Pointer to dynamically allocated array
    unsigned int arraySize;          // Size of the array
};

#include "Array.tpp" // Template implementation
#endif
