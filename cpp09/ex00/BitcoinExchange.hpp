/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:33:16 by vejurick          #+#    #+#             */
/*   Updated: 2025/01/08 15:53:23 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <map>
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <iostream> 

class BitcoinExchange
{
    private:
        std::map<std::string, float> database;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& a);

		void readDatabase();
		bool parseCSV(std::string filename);
		void readInputFile(char *file);
		bool isValidDate(const std::string& date);
		bool isValidValue(const std::string& value);
		float findClosestLowerDate(const std::string& date);
		
};


#endif
