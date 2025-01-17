/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:34:33 by vejurick          #+#    #+#             */
/*   Updated: 2024/12/01 22:12:39 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    bool is_char = isChar(literal);
    bool is_int = isInt(literal);
    bool is_float = isFloat(literal);
    bool is_double = isDouble(literal);

    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    try {
        if (is_char) {
            c = literal[1];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
        } else if (is_int) {
            i = std::stoi(literal);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        } else if (is_float) {
            f = std::stof(literal);
            i = static_cast<int>(f);
            c = static_cast<char>(i);
            d = static_cast<double>(f);
        } else if (is_double) {
            d = std::stod(literal);
            i = static_cast<int>(d);
            c = static_cast<char>(i);
            f = static_cast<float>(d);
        } else {
            throw std::invalid_argument("Unknown type");
        }

        if (is_char) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";
} else if (i >= 0 && i <= 127) { 
    char tempChar = static_cast<char>(i);
    if (std::isprint(tempChar))
        std::cout << "char: '" << tempChar << "'\n";
    else
        std::cout << "char: Non displayable\n";
} else {
    std::cout << "char: impossible\n";
}
        std::cout << "int: " << i << "\n";

        if (f - static_cast<int>(f) == 0)
            std::cout << "float: " << f << ".0f\n";
        else
            std::cout << "float: " << f << "f\n";

        if (d - static_cast<int>(d) == 0)
            std::cout << "double: " << d << ".0\n";
        else
            std::cout << "double: " << d << "\n";

    } catch (...) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

bool ScalarConverter::isChar(const std::string &literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isInt(const std::string &literal) {
    try {
        std::stoi(literal);
        return true;
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isFloat(const std::string &literal) {
    try {
        std::stof(literal);
        return literal.find('f') != std::string::npos;
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isDouble(const std::string &literal) {
    try {
        std::stod(literal);
        return literal.find('.') != std::string::npos && literal.find('f') == std::string::npos;
    } catch (...) {
        return false;
    }
}
