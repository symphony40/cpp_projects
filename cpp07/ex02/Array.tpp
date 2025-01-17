/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:43:53 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/16 12:10:58 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : elements(0), arraySize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), arraySize(n) {}

template <typename T>
Array<T>::Array(const Array &other) : elements(0), arraySize(0) {
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] elements;
        arraySize = other.arraySize;
        elements = new T[arraySize];
        for (unsigned int i = 0; i < arraySize; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] elements;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= arraySize) {
        throw OutOfBoundsException();
    }
    return elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= arraySize) {
        throw OutOfBoundsException();
    }
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return arraySize;
}

#endif
