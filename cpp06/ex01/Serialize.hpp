/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:10:35 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/01 22:18:00 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include "Data.hpp"
#include <cstdint>

class Serialize {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    Serialize();
    ~Serialize();
    Serialize(const Serialize& other);
    Serialize& operator=(const Serialize& other);
};

#endif
