/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:14:18 by vejurick          #+#    #+#             */
/*   Updated: 2025/01/08 15:59:29 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	this->database = copy.database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& a)
{
	this->database = a.database;
    return (*this);    
}

bool BitcoinExchange::parseCSV(std::string filename)
{
	std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line);
	
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, rate;
		
        std::getline(ss, date, ',');
        std::getline(ss, rate);
		
        database[date] = static_cast<float>(std::atof(rate.c_str()));
    }
    file.close();
    return true;
}

void BitcoinExchange::readDatabase()
{
	std::string filename = "data.csv";
	
	if (!parseCSV(filename)) {
        std::cerr << "Failed to parse CSV file." << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) {
        if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    for (size_t i = 0; i < year.length(); ++i) {
        if (!std::isdigit(year[i])) return false;
    }
    for (size_t i = 0; i < month.length(); ++i) {
        if (!std::isdigit(month[i])) return false;
    }
    for (size_t i = 0; i < day.length(); ++i) {
        if (!std::isdigit(day[i])) return false;
    }

    int monthInt = std::atoi(month.c_str());
    int dayInt = std::atoi(day.c_str());

    if (monthInt < 1 || monthInt > 12) return false;

    // Days in each month
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (dayInt < 1 || dayInt > daysInMonth[monthInt - 1]) return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) {
    char* endptr;
    double num = std::strtod(value.c_str(), &endptr);

    if (*endptr != '\0') return false;
    if (num < 0 || num > 1000) return false;

    return true;
}

float BitcoinExchange::findClosestLowerDate(const std::string& date) {
    std::map<std::string, float>::const_iterator it = database.lower_bound(date);

    if (it != database.end() && it->first == date) {
        return it->second;
    }

    if (it == database.begin()) {
        std::cerr << "Error: No available date lower than " << date << "." << std::endl;
        return -1.0f;
    }
	
    --it;
    return it->second;
}

void BitcoinExchange::readInputFile(char *file) {
    std::ifstream inputFile(file);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string line;
    bool isFirstLine = true;

    while (std::getline(inputFile, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            if (line != "date | value") {
                std::cerr << "Error: Invalid file format. Expected header 'date | value'." << std::endl;
                return;
            }
            continue;
        }

        std::istringstream ss(line);
        std::string date, value;

        // Parse the line for date and value
        if (!std::getline(ss, date, '|')) {
            std::cerr << "Error: Missing or malformed date in line: " << line << std::endl;
            continue;
        }
        if (!(ss >> value)) {
            std::cerr << "Error: Missing or malformed value in line: " << line << std::endl;
            continue;
        }

        // Trim spaces around date and value
        date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
        value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));

        // Validate the date and value
        if (!isValidDate(date)) {
            std::cerr << "Error: Invalid date format '" << date << "' in line: " << line << std::endl;
            continue;
        }
        if (!isValidValue(value)) {
            std::cerr << "Error: Invalid value '" << value << "' in line: " << line << std::endl;
            continue;
        }
		 float bitcoin_value = findClosestLowerDate(date);
            if (bitcoin_value != -1.0f) {
                std::cout << date << " => " << value << " = " << bitcoin_value * atof(value.c_str()) << std::endl;
            }
    }

    inputFile.close();
}
