/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:34:33 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/03 19:45:15 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t Serialize::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

Serialize::Serialize() {}

Serialize::~Serialize() {}

Serialize::Serialize(const Serialize& other) {
    (void)other;
}

Serialize& Serialize::operator=(const Serialize& other) {
    (void)other;
    return *this;
}
