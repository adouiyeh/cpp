#pragma once

#include <iostream>
#include <string>
#include <limits.h>
#include <cmath>

class ScalarConverter 
{    

    private:
        ScalarConverter() {};
        ScalarConverter(const ScalarConverter &other){ (void)other; } 
        ScalarConverter& operator=(const ScalarConverter &other) { (void)other; return *this; }
        ~ScalarConverter() {}
    
    public:
        enum ScalarType 
        {   
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            INVALID
        };
        static ScalarType getType(const std::string &str);
        static bool isChar(const std::string &str);
        static void charConverter(const std::string &str);
        static void intConverter(const std::string &str);
        static void floatConverter(const std::string &str);
        static void doubleConverter(const std::string &str);
        static void convert(const std::string &str);
        static bool isInt(const  std::string &str);
        static bool isFloat(const std::string &str);
        static bool isDouble(const std::string &str);
    
};