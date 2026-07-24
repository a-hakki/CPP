#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {
    _loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& dbFilename) {
    _loadDatabase(dbFilename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// --- Helpers ---
void BitcoinExchange::_trim(std::string& str) const {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        str = "";
        return;
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    str = str.substr(first, (last - first + 1));
}

bool BitcoinExchange::_isValidDate(const std::string& date) const {
    // Format must be strictly YYYY-MM-DD
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }

    int year, month, day;
    std::istringstream(date.substr(0, 4)) >> year;
    std::istringstream(date.substr(5, 2)) >> month;
    std::istringstream(date.substr(8, 2)) >> day;

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    // Basic day limits for months
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeap ? 29 : 28)) return false;
    }
    return true;
}

bool BitcoinExchange::_isValidValue(const std::string& valueStr, float& outValue) const {
    std::istringstream iss(valueStr);
    iss >> outValue;

    // Check if the string actually parsed to a valid float
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}

// --- Loading the internal DB ---
bool BitcoinExchange::_loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file (" << filename << ")." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            std::string rateStr = line.substr(commaPos + 1);
            
            float rate;
            std::istringstream(rateStr) >> rate;
            _database[date] = rate;
        }
    }
    file.close();
    return true;
}


void BitcoinExchange::evaluate(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }

        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);
        _trim(date);
        _trim(valueStr);

        if (!_isValidDate(date)) {
            std::cout << "Error: bad input => " << (date.empty() ? line : date) << "\n";
            continue;
        }

        float value;
        if (!_isValidValue(valueStr, value)) {
            std::cout << "Error: bad input => " << valueStr << "\n";
            continue;
        }

        if (value < 0) {
            std::cout << "Error: not a positive number.\n";
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number.\n";
            continue;
        }

        std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

        if (it == _database.end() || it->first != date) {
            // If we are at the very beginning, there is no lower date available.
            if (it == _database.begin()) {
                std::cout << "Error: no exchange rate data available prior to " << date << "\n";
                continue;
            }
            // Step the iterator backward once to get the closest LOWER date
            --it;
        }

        // Output the calculated value
        std::cout << date << " => " << value << " = " << (value * it->second) << "\n";
    }
    file.close();
}