#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>


ScalarConverter::ScalarType ScalarConverter::getType(const std::string &str)
{
    if (isChar(str))
        return CHAR;
    if (isInt(str))
        return INT;
    if (isFloat(str))
        return FLOAT;
    if (isDouble(str))
        return DOUBLE;
    if (isPseudo(str))
        return PSEUDO;
    return INVALID;
}

bool ScalarConverter::isChar(const std::string &str)
{
    return str.length() == 1 && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string &str)
{
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}


void ScalarConverter::convertPseudo(const std::string &str)
{
    if (str == "nanf" || str == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "-inff" || str == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (str == "inff" || str == "inf" || str == "+inff" || str == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
}

bool ScalarConverter::isFloat(const std::string &str)
{    
    size_t i = 0;
    bool dot = false;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else if (str[i] == 'f' && i == str.length() - 1)
        {
            return dot;
        }
        else if (!std::isdigit(str[i]))
        {
            return false;
        }
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string &str)
{    
    size_t i = 0;
    bool dot = false;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else if (!std::isdigit(str[i]))
        {
            return false;
        }
    }
    return dot;
}

bool ScalarConverter::isPseudo(const std::string &str)
{
    return (str == "nan" || str == "nanf" ||
            str == "-inf" || str == "-inff" ||
            str == "inf" || str == "inff" ||
            str == "+inf" || str == "+inff");
}

void ScalarConverter::charConverter(const std::string &str)
{
    std::cout << "char: '" << str[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
}


void ScalarConverter::intConverter(const std::string &str)
{
    long num = std::atoll(str.c_str());
    if ((num >= 0 && num < 32) || (num == 127))
        std::cout << "char: non displayable" << std::endl;
    else if (num < 0 || num > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    
    if (num <= std::numeric_limits<int>::max() && num >= std::numeric_limits<int>::min())
        std::cout << "int: " << num << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    
    if (std::abs(num) <= std::numeric_limits<float>::max())
        std::cout << "float: "<< std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    
    if (std::abs(num) <= std::numeric_limits<double>::max())
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::floatConverter(const std::string &str)
{
    float numf = std::strtof(str.c_str(), NULL);
    if ((numf >= 0 && numf < 32) || (numf == 127))
        std::cout << "char: non displayable" << std::endl;
    else if (numf < 0 || numf > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(numf) << "'" << std::endl;
    
    if (numf <= std::numeric_limits<long>::max() && numf >= std::numeric_limits<long>::min() && str.length() < 10)
        std::cout << "int: " << static_cast<int>(numf) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    
    if (std::fabs(numf) <= std::numeric_limits<float>::max())
    {
        if (static_cast<float>(numf) == static_cast<int>(numf))
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(numf) << "f" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(numf) << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
    
    if (std::fabs(numf) <= std::numeric_limits<double>::max())
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(numf) << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::doubleConverter(const std::string &str)
{
    double numd = std::atof(str.c_str());

    if ((numd >= 0 && numd < 32) || (numd == 127))
        std::cout << "char: non displayable" << std::endl;
    else if (numd < 0 || numd > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(numd) << "'" << std::endl;
    
    if (numd <= std::numeric_limits<long>::max() && numd >= std::numeric_limits<long>::min() && str.length() < 10)
        std::cout << "int: " << static_cast<int>(numd) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    
    if (std::abs(numd) <= std::numeric_limits<float>::max())
    {
        if (static_cast<float>(numd) == static_cast<int>(numd))
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(numd) << "f" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(numd) << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
    
    if (std::abs(numd) <= std::numeric_limits<double>::max())
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(numd) << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}



void ScalarConverter::convert(const std::string &str)
{
    ScalarType type = getType(str);
    switch (type)
    {
        case CHAR:
            charConverter(str);
            break;
        case INT:
            intConverter(str);
            break;
        case FLOAT:
            floatConverter(str);
            break;
        case DOUBLE:
            doubleConverter(str);
            break;
        case PSEUDO:
            convertPseudo(str);
            break;
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}
