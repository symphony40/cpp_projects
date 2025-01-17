/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:25:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/01 22:18:33 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include <iostream>

int main() {
    // Create a Data object
    Data data = {42, "Test Data"};

    // Print the original Data pointer and its contents
    std::cout << "Original Data address: " << &data << "\n";
    std::cout << "Data contents: id = " << data.id << ", name = " << data.name << "\n";

    // Serialize the pointer
    uintptr_t raw = Serialize::serialize(&data);
    std::cout << "Serialized uintptr_t: " << raw << "\n";

    // Deserialize back to a pointer
    Data* deserializedData = Serialize::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserializedData << "\n";
    std::cout << "Data contents after deserialization: id = " 
              << deserializedData->id << ", name = " << deserializedData->name << "\n";

    // Verify that the pointers match
    if (deserializedData == &data) {
        std::cout << "Success: Deserialized pointer matches the original pointer!\n";
    } else {
        std::cout << "Error: Deserialized pointer does not match the original pointer!\n";
    }

    return 0;
}
