#pragma once
#include <fstream>
#include <map>
#include <algorithm>




class BitcoinExchange 
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        bool parseData(std::string& line);
        void parseInput(std::string& line);
        void handleInput(char *file);
    // private:
        std::map<std::string, float> _rates;
};

bool BitcoinExchange::parseData(std::string& line)
{
    std::size_t comma = line.find(',');
    if (comma == std::string::npos)
        return false;
    std::string date = line.substr(0, comma);
    std::string val = line.substr(comma + 1);
    float rate = static_cast<float>(std::atof(val.c_str()));

    // std::cout << val << " Test: " << rate << std::endl;
    _rates[date] = rate;
    return true;
}


std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end   = str.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}


bool isDateValid(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    return true;
}


bool isRateValid(const std::string& str, float& rate)
{
    char* end;
    rate = std::strtof(str.c_str(), &end);

    if (*end != '\0')
        return false;

    if (rate < 0)
        throw std::runtime_error("Error: not a positive number.");

    if (rate > 1000)
        throw std::runtime_error("Error: too large a number.");

    return true;
}


void BitcoinExchange::parseInput(std::string& line)
{
    std::size_t pipe = line.find('|');
    if (pipe == std::string::npos)
        throw std::invalid_argument("Error: bad input => " + line);
    std::string date  = trim(line.substr(0, pipe));
    std::string value = trim(line.substr(pipe + 1));
    if (!isDateValid(date))
        throw std::invalid_argument("Error: bad input => " + line);
    float rate;
    if (!isRateValid(value, rate))
        throw std::invalid_argument("Error: bad input => " + line);
    std::map<std::string, float>::iterator it = _rates.lower_bound(date);
    if (it == _rates.end() || it->first != date)
    {
        if (it == _rates.begin())
            throw std::runtime_error("Error: bad input => " + line);
        --it;
    }
    std::cout << date << " => " <<  rate << " = "  << rate * it->second << std::endl;
}


BitcoinExchange::BitcoinExchange()
{
    std::fstream data("data.csv");
    if (!data.is_open())
        throw std::invalid_argument("Error: could not data.");
    std::string line;
    while (getline(data, line))
        if (!parseData(line))
            continue;
}

void BitcoinExchange::handleInput(char *file)
{
    std::fstream infile(file);
    if (!infile.is_open())
        throw std::invalid_argument("Error: could not open file.");
    std::string line;
    while (getline(infile, line))
    {
        try {
            parseInput(line);
        }catch(std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
}


BitcoinExchange::~BitcoinExchange() {}