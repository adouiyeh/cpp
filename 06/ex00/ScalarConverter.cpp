#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>


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

bool ScalarConverter::isFloat(const std::string &str)
{
    if (str == "nanf" || str == "+nanf" || str == "-nanf")
        return true;
    if (str == "inff" || str == "+inff" || str == "-inff")
        return true;
    
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
    if (str == "nan" || str == "+nan" || str == "-nan")
        return true;
    if (str == "inf" || str == "+inf" || str == "-inf")
        return true;
    
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

void ScalarConverter::charConverter(const std::string &str)
{
    std::cout << "char: '" << str[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
}


void ScalarConverter::intConverter(const std::string &str)
{
    try
    {
        std::stringstream ss(str);
        int value;
        ss >> value;
        if (ss.fail())
            throw std::exception();

        if (isprint(value))
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << value << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    }
    catch (const std::exception &)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        try
        {
            std::stringstream ss(str);
            double d;
            ss >> d;
            if (ss.fail())
                throw std::exception();
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
        catch (const std::exception &)
        {
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
}


void ScalarConverter::floatConverter(const std::string &str)
{
    try
    {
        std::stringstream ss(str);
        double d;
        ss >> d;
        if (ss.fail())
            throw std::exception();

        if (std::isnan(d) || std::isinf(d))
            std::cout << "char: impossible" << std::endl;
        else if (d >= 32 && d <= 126)
            std::cout << "char: '" << static_cast<unsigned char>(d) << "'" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        
        if (std::isnan(d) || std::isinf(d))
            std::cout << "int: impossible" << std::endl;
        else if (d >= INT_MIN && d <= INT_MAX)
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    catch (const std::exception& )
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::doubleConverter(const std::string &str)
{
    try
    {
        std::stringstream ss(str);
        double d;
        ss >> d;
        if (ss.fail())
            throw std::exception();
        
        if (std::isnan(d) || std::isinf(d))
            std::cout << "char: impossible" << std::endl;
        else if (d >= 32 && d <= 126)
            std::cout << "char: '" << static_cast<unsigned char>(d) << "'" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        if (std::isnan(d) || std::isinf(d))
            std::cout << "int: impossible" << std::endl;
        else if (d >= INT_MIN && d <= INT_MAX)
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    catch (const std::exception& )
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
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
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}
