#pragma once

#include <cstdlib>
#include <string>
#include <iostream>

struct Data
{
    int value;
    std::string name;
};

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &other);
    Serializer& operator=(const Serializer &other);
    ~Serializer();

public:
    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long raw);
};



