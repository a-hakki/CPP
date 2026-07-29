#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
private:

    std::map<std::string, float> _database;


    bool    _loadDatabase(const std::string& filename);
    bool    _isValidDate(const std::string& date) const;
    bool    _isValidValue(const std::string& valueStr, float& outValue) const;
    void    _trim(std::string& str) const;

public:

    BitcoinExchange();
    BitcoinExchange(const std::string& dbFilename);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    // Core functionality
    void    evaluate(const std::string& inputFile) const;
};

#endif